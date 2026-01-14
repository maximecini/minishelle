/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_child_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:00:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 16:54:43 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	cleanup_singleton_files(t_heredoc_singleton *s)
{
	if (s->fd != -1)
		close(s->fd);
	if (s->eof_str)
		free(s->eof_str);
	if (s->path)
		free(s->path);
	if (s->inherited_path)
		free(s->inherited_path);
}

void	cleanup_heredoc_ctx(t_cleanup_ctx *ctx)
{
	t_list	*tmp;

	if (!ctx)
		return ;
	if (ctx->lst_token && *ctx->lst_token)
		ft_lstclear(ctx->lst_token, free_node_token_content);
	if (ctx->lst_cmd && *ctx->lst_cmd)
		ft_lstclear(ctx->lst_cmd, free_node_cmd_content);
	if (ctx->tab && *ctx->tab)
		ft_free_split(*ctx->tab);
	if (ctx->lst_env)
	{
		tmp = ctx->lst_env;
		ft_lstclear(&tmp, free_node_env_content);
	}
}

int	fork_heredoc_child(const char *eof, const char *path, t_cleanup_ctx *ctx,
		int do_expand)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
		heredoc_child_process(eof, path, ctx, do_expand);
	return (pid);
}

int	wait_heredoc_child(pid_t pid)
{
	int	status;

	setup_heredoc_signals();
	if (waitpid(pid, &status, 0) < 0)
	{
		restore_heredoc_signals();
		return (-1);
	}
	restore_heredoc_signals();
	if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
		return (-1);
	return (0);
}
