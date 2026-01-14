/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:26:25 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 18:50:27 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_command_valid(t_node_cmd *node_cmd)
{
	int	err;

	if (!node_cmd->cmd || !node_cmd->cmd[0])
		return (0);
	if (!node_cmd->cmd[0][0])
		return (0);
	if (ft_strchr(node_cmd->cmd[0], '/'))
	{
		err = acces_cmd(node_cmd->cmd[0]);
		if (err)
			return (error_file(err, node_cmd->cmd[0]), (err));
	}
	return (0);
}

void	check_command_valid_or_exit(t_node_cmd *node_cmd, t_element **lst_env,
		t_element **lst_cmd)
{
	int	err;

	err = check_command_valid(node_cmd);
	if (err)
	{
		free_lst(lst_env, lst_cmd);
		exit(err);
	}
}

void	exec_all_commands(t_exec *exec, t_element *lst_cmd, t_element **lst_env)
{
	t_node_cmd	*node_cmd;
	t_element	*current;
	int			i;

	current = lst_cmd;
	i = 0;
	while (current)
	{
		node_cmd = (t_node_cmd *)current->content;
		exec->pid[i] = fork_and_manage_pipe(exec, i);
		if (exec->pid[i] == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			free(exec->pid);
			exec->i = i;
			process_command(exec, node_cmd, lst_env, &lst_cmd);
		}
		close_unused_fds(exec, i);
		i++;
		current = current->next;
	}
}

void	close_unused_fds(t_exec *exec, int i)
{
	if (i > 0 && exec->prev_fd != -1)
	{
		if (i < exec->nb_cmd - 1 && exec->prev_fd != exec->pipefd[0])
		{
			if (close(exec->prev_fd) == -1)
				perror("minishell");
		}
	}
	if (i < exec->nb_cmd - 1)
		exec->prev_fd = exec->pipefd[0];
}

int	is_point(char *line)
{
	if (!line)
		return (-1);
	if (strlen(line) == 1)
		if (line[0] == '.')
			return (print_error("filename argument required."),
				print_error(" : usage: . filename [arguments]"), 1);
	return (0);
}
