/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_cleanup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 21:00:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/10/16 16:54:58 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	find_last_heredoc_index(t_cmd *cmd)
{
	int	last;
	int	i;

	last = -1;
	i = 0;
	while (i < cmd->nb_redirect)
	{
		if (cmd->redirect[i].type == HEREDOC)
			last = i;
		i++;
	}
	return (last);
}

void	delete_heredoc_file(char *file)
{
	if (file && is_our_tempfile(file))
	{
		unlink(file);
		free(file);
	}
}

void	cleanup_heredoc_keep_last(t_cmd *cmd)
{
	int	last;
	int	i;

	i = 0;
	last = find_last_heredoc_index(cmd);
	if (last == -1)
		return ;
	while (i < cmd->nb_redirect)
	{
		if (cmd->redirect[i].type == HEREDOC && i != last)
		{
			delete_heredoc_file(cmd->redirect[i].files);
			cmd->redirect[i].files = NULL;
		}
		i++;
	}
}

int	run_one_heredoc(t_redirect *r, t_cleanup_ctx *ctx)
{
	int		do_expand;
	char	*path;
	pid_t	pid;

	do_expand = r->expand_heredoc;
	path = make_tempfile_path();
	if (!path)
		return (-1);
	pid = fork_heredoc_child(r->eof, path, ctx, do_expand);
	if (pid < 0)
	{
		free(path);
		return (-1);
	}
	if (wait_heredoc_child(pid) < 0)
	{
		unlink(path);
		free(path);
		return (-1);
	}
	cleanup_old_heredoc_file(r);
	r->files = path;
	r->expand_heredoc = do_expand;
	return (0);
}
