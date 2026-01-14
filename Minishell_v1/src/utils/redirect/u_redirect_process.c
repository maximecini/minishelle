/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_redirect_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:30:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 15:41:28 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	handle_stdin_redirect(t_exec *exec, t_redirect *redirect)
{
	if (get_infile(exec, redirect) == 0)
		return (1);
	return (0);
}

static int	handle_stdout_redirect(t_redirect *redirect)
{
	int	result;

	result = open_and_redirect(redirect->filename,
			O_WRONLY | O_CREAT | O_TRUNC, STDOUT_FILENO, "dup2 stdout");
	return (result);
}

static int	handle_append_redirect(t_redirect *redirect)
{
	int	result;

	result = open_and_redirect(redirect->filename,
			O_WRONLY | O_CREAT | O_APPEND, STDOUT_FILENO, "dup2 append");
	return (result);
}

static int	handle_heredoc_redirect(t_redirect *redirect)
{
	int	result;

	result = open_and_redirect(redirect->heredoc_filename, O_RDONLY,
			STDIN_FILENO, "dup2 heredoc");
	return (result);
}

int	process_redirections(t_exec *exec, t_node_cmd *node_cmd)
{
	int			i;
	t_redirect	*redirect;
	int			result;

	i = -1;
	while (++i < node_cmd->nb_redirect)
	{
		redirect = &node_cmd->redirect[i];
		if (redirect->type == REDIR_STDIN)
			result = handle_stdin_redirect(exec, redirect);
		else if (redirect->type == REDIR_STDOUT)
			result = handle_stdout_redirect(redirect);
		else if (redirect->type == REDIR_APPEND)
			result = handle_append_redirect(redirect);
		else if (redirect->type == REDIR_HEREDOC)
			result = handle_heredoc_redirect(redirect);
		else
			result = 0;
		if (result != 0)
			return (result);
	}
	return (0);
}
