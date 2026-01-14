/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 23:19:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/27 23:21:26 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_delimiter_reached(char *line, char *delim, size_t l_arg)
{
	size_t	l_line;
	char	*tmp;

	if (!line || !delim)
		return (0);
	l_line = ft_strlen(line);
	tmp = ft_strdup(line);
	if (!tmp)
		return (0);
	if (l_line > 0 && tmp[l_line - 1] == '\n')
		tmp[--l_line] = '\0';
	if (l_line == l_arg && !ft_strncmp(delim, tmp, l_arg))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

void	write_line_to_heredoc(t_heredoc_data *heredoc_data)
{
	size_t	len;

	if (heredoc_data->here_doc_fd != -1)
	{
		if (!heredoc_data->line)
			return ;
		len = ft_strlen(heredoc_data->line);
		write(heredoc_data->here_doc_fd, heredoc_data->line, len);
		write(heredoc_data->here_doc_fd, "\n", 1);
	}
}
