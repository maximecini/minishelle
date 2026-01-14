/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:28:43 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/28 09:05:19 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	read_and_write_heredoc_loop(t_heredoc_data *heredoc_data)
{
	char	*input;

	set_heredoc_data(heredoc_data);
	g_last_status = heredoc_data->here_doc_fd;
	while (1)
	{
		input = readline("< ");
		if (!input)
			break ;
		heredoc_data->line = input;
		if (is_delimiter_reached(heredoc_data->line, heredoc_data->delimiteur,
				heredoc_data->delim_len))
		{
			free(heredoc_data->line);
			heredoc_data->line = NULL;
			break ;
		}
		write_line_to_heredoc(heredoc_data);
		free(heredoc_data->line);
		heredoc_data->line = NULL;
	}
	g_last_status = -1;
}

void	child_read_heredoc(t_heredoc_data *data)
{
	signal(SIGINT, heredoc_sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	read_and_write_heredoc_loop(data);
	if (data->here_doc_fd != -1)
		close(data->here_doc_fd);
	free_heredoc_data(data);
	set_heredoc_data(NULL);
	exit(0);
}
