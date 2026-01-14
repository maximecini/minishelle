/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:58:18 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/10/17 11:36:33 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	cleanup_exec(t_exec *exec)
{
	if (exec->pid)
		free(exec->pid);
	if (exec->pipefd)
		free(exec->pipefd);
}

static void	report_signal_status(t_exec *exec, int sig, int *quit_done,
		int *int_done)
{
	if (sig == SIGQUIT && !(*quit_done))
	{
		if (exec->nb_cmd == 1)
			ft_putendl_fd("Quit (core dumped)", 2);
		*quit_done = 1;
	}
	else if (sig == SIGINT && !(*int_done))
	{
		write(1, "\n", 1);
		*int_done = 1;
	}
}

int	wait_for_children(t_exec *exec)
{
	int	index;
	int	status;
	int	last_status;
	int	quit_done;
	int	int_done;

	index = 0;
	last_status = 0;
	quit_done = 0;
	int_done = 0;
	while (index < exec->nb_cmd)
	{
		waitpid(exec->pid[index], &status, 0);
		if (WIFEXITED(status))
			last_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			last_status = 128 + WTERMSIG(status);
			report_signal_status(exec, WTERMSIG(status), &quit_done, &int_done);
		}
		index++;
	}
	return (last_status);
}

void	handle_exec_error(char *cmd, char *error_msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error_msg, 2);
}
