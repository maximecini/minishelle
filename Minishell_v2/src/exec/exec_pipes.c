/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:35:12 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/15 19:35:12 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	setup_pipes(t_exec *exec)
{
	int	i;
	int	count;

	if (exec->nb_cmd <= 1)
		return (0);
	count = (exec->nb_cmd - 1);
	i = 0;
	while (i < count)
	{
		if (pipe(&exec->pipefd[i * 2]) == -1)
		{
			perror("pipe");
			return (-1);
		}
		i++;
	}
	return (0);
}

void	setup_child_pipes(t_exec *exec, int cmd_index)
{
	int	total;
	int	i;

	if (cmd_index > 0)
		dup2(exec->pipefd[(cmd_index - 1) * 2], STDIN_FILENO);
	if (cmd_index < exec->nb_cmd - 1)
		dup2(exec->pipefd[cmd_index * 2 + 1], STDOUT_FILENO);
	total = (exec->nb_cmd - 1) * 2;
	i = 0;
	while (i < total)
	{
		close(exec->pipefd[i]);
		i++;
	}
}

void	close_pipes(t_exec *exec, int cmd_index)
{
	if (cmd_index > 0)
		close(exec->pipefd[(cmd_index - 1) * 2]);
	if (cmd_index < exec->nb_cmd - 1)
		close(exec->pipefd[cmd_index * 2 + 1]);
}
