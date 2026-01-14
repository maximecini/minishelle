/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:43:16 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/29 16:27:48 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	open_heredoc_file(t_redirect *redirect)
{
	redirect->heredoc_filename = create_temp_filename();
	redirect->here_doc_fd = open(redirect->heredoc_filename,
			O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (redirect->here_doc_fd == -1)
	{
		perror("open heredoc file");
		return (1);
	}
	return (0);
}

static int	handle_single_heredoc(t_redirect *redirect, t_element **lst_cmd,
		t_element **lst_env)
{
	int	status;

	if (open_heredoc_file(redirect))
		return (1);
	status = read_heredoc_fork(redirect, lst_cmd, lst_env);
	if (redirect->here_doc_fd != -1)
	{
		close(redirect->here_doc_fd);
		redirect->here_doc_fd = -1;
	}
	if (status == 130)
	{
		printf("\n");
		return (130);
	}
	return (0);
}

static int	process_redirects_for_node(t_node_cmd *node_cmd,
		t_element **lst_cmd, t_element **lst_env)
{
	int	i;
	int	status;

	i = 0;
	while (i < node_cmd->nb_redirect)
	{
		if (node_cmd->redirect[i].type == REDIR_HEREDOC)
		{
			status = handle_single_heredoc(&node_cmd->redirect[i], lst_cmd,
					lst_env);
			if (status)
				return (status);
		}
		i++;
	}
	return (0);
}

void	prepare_heredocs(t_element *lst_cmd, t_element **lst_env)
{
	t_element	*current;
	t_node_cmd	*node_cmd;
	int			status;
	void		(*old_sigint)(int);

	old_sigint = signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	current = lst_cmd;
	while (current)
	{
		node_cmd = (t_node_cmd *)current->content;
		status = process_redirects_for_node(node_cmd, &lst_cmd, lst_env);
		if (status)
		{
			g_last_status = status;
			signal(SIGINT, old_sigint);
			return ;
		}
		current = current->next;
	}
	signal(SIGINT, old_sigint);
}
