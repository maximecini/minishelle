/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:24:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/26 18:25:01 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	handle_status(int status)
{
	int	sig;

	if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		g_last_status = 128 + sig;
		if (sig == SIGINT)
			ft_printf("\n");
		else if (sig == SIGQUIT)
			ft_printf("Quit (core dumped)\n");
	}
	else if (WIFEXITED(status))
	{
		g_last_status = WEXITSTATUS(status);
	}
}

void	wait_for_children(t_exec *exec)
{
	int	status;
	int	i;

	i = 0;
	while (i < exec->nb_cmd)
	{
		if (waitpid(exec->pid[i], &status, 0) == -1)
		{
			perror("waitpid");
			continue ;
		}
		if (i == exec->nb_cmd - 1)
			handle_status(status);
		i++;
	}
}
