/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:00:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 18:48:02 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static void	save_original_fds(int *original_stdout, int *original_stdin)
{
	*original_stdout = dup(STDOUT_FILENO);
	*original_stdin = dup(STDIN_FILENO);
}

static void	restore_original_fds(int original_stdout, int original_stdin)
{
	ft_dup(original_stdout, STDOUT_FILENO, 0);
	ft_dup(original_stdin, STDIN_FILENO, 0);
	close(original_stdout);
	close(original_stdin);
	signal(SIGINT, handle_sigint_parent);
	signal(SIGQUIT, SIG_IGN);
}

static void	handle_empty_cmd(t_exec *exec, t_node_cmd *node_cmd)
{
	if (node_cmd->nb_redirect > 0)
	{
		exec->status = 0;
		g_last_status = 0;
	}
	else
	{
		exec->status = 0;
		g_last_status = 0;
	}
}

static void	execute_builtin_cmd(t_exec *exec, t_node_cmd *node_cmd,
		t_element **lst_env, t_element **lst_cmd)
{
	if (!node_cmd->cmd || !node_cmd->cmd[0] || !node_cmd->cmd[0][0])
		handle_empty_cmd(exec, node_cmd);
	else
	{
		exec->status = execute_builtin(node_cmd, lst_env, lst_cmd);
		g_last_status = exec->status;
	}
}

int	exec_single_builtin(t_exec *exec, t_node_cmd *node_cmd, t_element **lst_env,
		t_element **lst_cmd)
{
	int	err;
	int	original_stdout;
	int	original_stdin;

	save_original_fds(&original_stdout, &original_stdin);
	err = process_redirections(exec, node_cmd);
	if (err)
	{
		restore_original_fds(original_stdout, original_stdin);
		free(exec->pid);
		g_last_status = err;
		return (err);
	}
	free(exec->pid);
	execute_builtin_cmd(exec, node_cmd, lst_env, lst_cmd);
	restore_original_fds(original_stdout, original_stdin);
	if (node_cmd->cmd[0] && ft_strcmp(node_cmd->cmd[0], "exit") == 0)
	{
		free_lst(lst_env, lst_cmd);
		exit(exec->status);
	}
	return (exec->status);
}
