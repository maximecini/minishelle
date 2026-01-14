/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_pipe_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:00:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/29 11:14:44 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static void	setup_pipe_fds(t_exec *exec, int i)
{
	exec->pipe[0] = exec->prev_fd;
	exec->pipe[1] = -1;
	if (i < exec->nb_cmd - 1)
		exec->pipe[1] = exec->pipefd[1];
}

static void	handle_child_process(t_exec *exec, int i)
{
	if (i < exec->nb_cmd - 1)
		close(exec->pipefd[0]);
}

static void	handle_parent_process(t_exec *exec, int i)
{
	if (exec->prev_fd != -1)
		close(exec->prev_fd);
	if (i < exec->nb_cmd - 1)
	{
		close(exec->pipefd[1]);
		exec->prev_fd = exec->pipefd[0];
	}
}

static int	create_pipe_and_fork(t_exec *exec, int i)
{
	int	pid;

	if (i < exec->nb_cmd - 1 && pipe(exec->pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

int	fork_and_manage_pipe(t_exec *exec, int i)
{
	int	pid;

	pid = create_pipe_and_fork(exec, i);
	setup_pipe_fds(exec, i);
	if (pid == 0)
		handle_child_process(exec, i);
	else
		handle_parent_process(exec, i);
	return (pid);
}
