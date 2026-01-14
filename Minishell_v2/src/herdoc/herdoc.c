/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:00:39 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/10/16 16:24:10 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static int	process_cmd_heredocs(t_cmd *cmd, t_cleanup_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < cmd->nb_redirect)
	{
		if (cmd->redirect[i].type == HEREDOC)
		{
			if (!cmd->redirect[i].eof || cmd->redirect[i].eof[0] == '\0')
			{
				i++;
				continue ;
			}
			if (run_one_heredoc(&cmd->redirect[i], ctx) != 0)
			{
				cleanup_heredoc_keep_last(cmd);
				return (-1);
			}
		}
		i++;
	}
	return (0);
}

int	process_heredoc(t_list *lst_cmd, t_list *lst_env, t_cleanup_ctx *ctx)
{
	t_cmd	*cmd;

	(void)lst_env;
	while (lst_cmd)
	{
		cmd = (t_cmd *)lst_cmd->content;
		if (!cmd)
		{
			lst_cmd = lst_cmd->next;
			continue ;
		}
		if (process_cmd_heredocs(cmd, ctx) != 0)
			return (-1);
		cleanup_heredoc_keep_last(cmd);
		lst_cmd = lst_cmd->next;
	}
	return (0);
}
