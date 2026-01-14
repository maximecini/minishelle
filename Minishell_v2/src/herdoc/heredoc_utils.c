/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 21:00:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/10/16 22:56:13 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	is_our_tempfile(const char *s)
{
	const char	*prefix = "/tmp/minishell_heredoc_";

	if (!s)
		return (0);
	return (ft_strncmp(s, prefix, ft_strlen(prefix)) == 0);
}

void	cleanup_old_heredoc_file(t_redirect *r)
{
	if (r->files)
	{
		if (is_our_tempfile(r->files))
		{
			unlink(r->files);
			free(r->files);
		}
	}
}

void	write_heredoc_line(int fd, char *line, t_list *env, int do_expand)
{
	char	*expanded;

	if (do_expand)
	{
		expanded = expand_string_heredoc(line, env);
		if (!expanded)
			expanded = ft_strdup(line);
		write(fd, expanded, ft_strlen(expanded));
		free(expanded);
	}
	else
	{
		write(fd, line, ft_strlen(line));
	}
	write(fd, "\n", 1);
}

int	open_heredoc_file(const char *path)
{
	return (open(path, O_CREAT | O_WRONLY | O_TRUNC, 0600));
}
