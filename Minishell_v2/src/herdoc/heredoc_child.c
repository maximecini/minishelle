/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 21:00:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/10/16 16:51:42 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static t_heredoc_singleton	*get_heredoc_singleton(void)
{
	static t_heredoc_singleton	singleton = {NULL, -1, NULL, NULL, NULL};

	return (&singleton);
}

static void	cleanup_and_exit(int exit_code)
{
	t_heredoc_singleton	*s;

	s = get_heredoc_singleton();
	cleanup_singleton_files(s);
	cleanup_heredoc_ctx(s->ctx);
	rl_clear_history();
	_exit(exit_code);
}

static void	heredoc_signal_handler(int sig)
{
	(void)sig;
	cleanup_and_exit(130);
}

static void	heredoc_loop(int fd, char *clean_eof, t_cleanup_ctx *ctx,
		int do_expand)
{
	char	*line;
	int		line_num;

	signal(SIGINT, heredoc_signal_handler);
	line_num = 1;
	while (1)
	{
		line = readline("> ");
		if (!line)
			handle_heredoc_eof(clean_eof, line_num, cleanup_and_exit);
		if (ft_strcmp(line, clean_eof) == 0)
		{
			free(line);
			break ;
		}
		write_heredoc_line(fd, line, ctx->lst_env, do_expand);
		free(line);
		line_num++;
	}
}

void	heredoc_child_process(const char *raw_eof, const char *path,
		t_cleanup_ctx *ctx, int do_expand)
{
	t_heredoc_singleton	*s;
	int					fd;

	s = get_heredoc_singleton();
	s->ctx = ctx;
	fd = init_heredoc_child(s, raw_eof, path, cleanup_and_exit);
	if (fd == -1)
		cleanup_and_exit(1);
	s->fd = fd;
	heredoc_loop(fd, s->eof_str, ctx, do_expand);
	close(fd);
	finish_heredoc_child(s, ctx);
	_exit(0);
}
