/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:35:44 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/27 18:27:49 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	setup_execution(t_exec *exec, t_element *lst_cmd, t_element **lst_env)
{
	prepare_heredocs(lst_cmd, lst_env);
	if (g_last_status == 130 || g_last_status == 131)
		return (g_last_status);
	if (initialise_exec(exec, lst_cmd))
		return (perror("initialise_exec"), (1));
	if (g_last_status == 130 || g_last_status == 131)
		return (g_last_status);
	return (0);
}

void	handle_signals_for_parent(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
