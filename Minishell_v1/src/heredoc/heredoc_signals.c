/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 23:19:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/28 09:07:40 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	heredoc_sigint_handler(int sig)
{
	t_heredoc_data	*data;

	(void)sig;
	data = *get_heredoc_data();
	if (g_last_status != -1)
	{
		close(g_last_status);
		g_last_status = -1;
	}
	free_heredoc_data(data);
	set_heredoc_data(NULL);
	g_last_status = 130;
	exit(130);
}
