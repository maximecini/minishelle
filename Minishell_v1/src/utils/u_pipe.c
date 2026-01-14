/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_pipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:29:55 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/29 11:14:48 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"
#include <fcntl.h>

void	close_pipe(int pipe, int condition)
{
	if (condition)
		close(pipe);
}

int	setup_pipes(t_exec *exec)
{
	if (exec->pipe[0] != -1)
	{
		if (dup2(exec->pipe[0], STDIN_FILENO) == -1)
		{
			perror("minishell: dup2 in");
			return (EXIT_FAILURE);
		}
		close(exec->pipe[0]);
	}
	if (exec->pipe[1] != -1)
	{
		if (dup2(exec->pipe[1], STDOUT_FILENO) == -1)
		{
			perror("minishell: dup2 out");
			return (EXIT_FAILURE);
		}
		close(exec->pipe[1]);
	}
	return (0);
}
