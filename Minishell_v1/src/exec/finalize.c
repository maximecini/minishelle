/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:38:35 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/27 18:27:57 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	cleanup_heredoc_files(t_element *lst_cmd)
{
	t_node_cmd	*node_cmd;
	int			j;

	while (lst_cmd)
	{
		node_cmd = (t_node_cmd *)lst_cmd->content;
		j = 0;
		while (j < node_cmd->nb_redirect)
		{
			if (node_cmd->redirect[j].type == REDIR_HEREDOC
				&& node_cmd->redirect[j].heredoc_filename)
			{
				unlink(node_cmd->redirect[j].heredoc_filename);
			}
			j++;
		}
		lst_cmd = lst_cmd->next;
	}
}

void	wait_and_finalize(t_exec *exec, t_element *lst_cmd)
{
	wait_for_children(exec);
	signal(SIGINT, handle_sigint_parent);
	signal(SIGQUIT, SIG_IGN);
	cleanup_heredoc_files(lst_cmd);
	free(exec->pid);
}
