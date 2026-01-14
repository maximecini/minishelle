/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:37:41 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/25 12:42:31 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

int	initialise_exec(t_exec *exec, t_element *lst_cmd)
{
	exec->nb_cmd = count_lst(lst_cmd);
	exec->pid = ft_calloc(exec->nb_cmd + 1, sizeof(pid_t));
	if (!exec->pid)
	{
		perror("malloc exec->pid");
		return (1);
	}
	exec->status = 0;
	exec->prev_fd = -1;
	return (0);
}
