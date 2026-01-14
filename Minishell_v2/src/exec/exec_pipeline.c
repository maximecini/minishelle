/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:00:14 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/15 19:00:14 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "function.h"

static int	init_exec_context(t_exec *exec, t_list *lst_cmd, t_list *lst_env,
		char **tab)
{
	exec->lst_env = lst_env;
	exec->nb_cmd = ft_lstsize(lst_cmd);
	exec->pid = ft_calloc(exec->nb_cmd, sizeof(pid_t));
	exec->pipefd = NULL;
	exec->prev_fd = -1;
	exec->status = 0;
	exec->lst_cmd = lst_cmd;
	exec->tab = tab;
	if (!exec->pid)
		return (-1);
	if (exec->nb_cmd > 1)
	{
		exec->pipefd = ft_calloc((exec->nb_cmd - 1) * 2, sizeof(int));
		if (!exec->pipefd)
			return (-1);
		if (setup_pipes(exec) == -1)
			return (-1);
	}
	return (0);
}

static int	spawn_child(t_exec *exec, t_cmd *cmd, int index)
{
	exec->pid[index] = fork();
	if (exec->pid[index] == -1)
	{
		perror("fork");
		return (-1);
	}
	if (exec->pid[index] == 0)
	{
		setup_child_signals();
		setup_child_pipes(exec, index);
		if (setup_redirections(cmd) == -1)
		{
			cleanup_child_inherited(exec);
			exit(1);
		}
		execute_child_process(cmd, exec);
	}
	return (0);
}

static void	parent_step(t_exec *exec, int index)
{
	close_pipes(exec, index);
}

static int	run_pipeline_loop(t_exec *exec, t_list *lst_cmd)
{
	t_list	*current;
	int		index;

	current = lst_cmd;
	index = 0;
	while (current && index < exec->nb_cmd)
	{
		if (spawn_child(exec, (t_cmd *)current->content, index) == -1)
			return (-1);
		parent_step(exec, index);
		current = current->next;
		index++;
	}
	return (0);
}

int	execute_pipeline(t_list *lst_cmd, t_list **lst_env, char **tab,
		t_cleanup_ctx *ctx)
{
	t_exec	exec;
	int		status;

	if (init_exec_context(&exec, lst_cmd, *lst_env, tab) == -1)
	{
		cleanup_exec(&exec);
		return (1);
	}
	setup_parent_exec_signals();
	if (run_pipeline_loop(&exec, lst_cmd) == -1)
	{
		restore_interactive_signals();
		cleanup_exec(&exec);
		return (1);
	}
	restore_interactive_signals();
	status = wait_for_children(&exec);
	if (ctx && ctx->original_term)
		tcsetattr(STDIN_FILENO, TCSANOW, ctx->original_term);
	cleanup_exec(&exec);
	return (status);
}
