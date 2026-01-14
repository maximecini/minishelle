/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:30:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 16:54:49 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	handle_heredoc_eof(char *clean_eof, int line_num,
		void (*exit_func)(int))
{
	ft_putstr_fd(" here-document at line ", 2);
	ft_putnbr_fd(line_num, 2);
	ft_putstr_fd(" delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(clean_eof, 2);
	ft_putendl_fd("')", 2);
	if (exit_func)
		exit_func(0);
}

int	init_heredoc_child(t_heredoc_singleton *s, const char *raw_eof,
		const char *path, void (*exit_func)(int))
{
	s->fd = -1;
	s->eof_str = ft_strdup(raw_eof);
	if (!s->eof_str)
		s->eof_str = ft_strdup("");
	s->inherited_path = (char *)path;
	s->path = ft_strdup(path);
	if (!s->path && exit_func)
		exit_func(1);
	return (open_heredoc_file(s->path));
}

void	finish_heredoc_child(t_heredoc_singleton *s, t_cleanup_ctx *ctx)
{
	free(s->eof_str);
	free(s->path);
	free(s->inherited_path);
	cleanup_heredoc_ctx(ctx);
	rl_clear_history();
}
