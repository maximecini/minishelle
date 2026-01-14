/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 23:19:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/28 09:07:40 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_heredoc_data(t_heredoc_data *herdoc)
{
	if (!herdoc)
		return ;
	if (herdoc->delimiteur)
		free(herdoc->delimiteur);
	if (herdoc->line)
		free(herdoc->line);
	free(herdoc);
}

t_heredoc_data	**get_heredoc_data(void)
{
	static t_heredoc_data	*heredoc_data_singleton = NULL;

	return (&heredoc_data_singleton);
}

void	set_heredoc_data(t_heredoc_data *data)
{
	*get_heredoc_data() = data;
}
