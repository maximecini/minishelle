/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:38:27 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/15 19:38:27 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	apply_redirect(t_redirect *redirect)
{
	int	fd;

	if (redirect->type == HEREDOC && redirect->files == NULL)
		return (0);
	if (!redirect->files)
	{
		errno = EINVAL;
		perror("minishell");
		return (-1);
	}
	if (redirect->type == REDIR_IN || redirect->type == HEREDOC)
	{
		fd = open_input_file(redirect->files);
		if (fd == -1)
			return (-1);
		if (dup2(fd, STDIN_FILENO) == -1)
			return (close(fd), perror("dup2"), -1);
		return (close(fd), 0);
	}
	fd = open_output_file(redirect->files, redirect->type);
	if (fd == -1)
		return (-1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (close(fd), perror("dup2"), -1);
	return (close(fd), 0);
}

int	setup_redirections(t_cmd *cmd)
{
	int	index;

	index = 0;
	while (index < cmd->nb_redirect)
	{
		if (validate_redirect(&cmd->redirect[index]) == -1)
			return (-1);
		index++;
	}
	index = 0;
	while (index < cmd->nb_redirect)
	{
		if (apply_redirect(&cmd->redirect[index]) == -1)
			return (-1);
		index++;
	}
	return (0);
}

int	open_input_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		perror(filename);
	return (fd);
}

int	open_output_file(char *filename, int type)
{
	int	flags;
	int	fd;

	flags = O_WRONLY | O_CREAT;
	if (type == REDIR_APPEND)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	fd = open(filename, flags, 0644);
	if (fd == -1)
		perror(filename);
	return (fd);
}
