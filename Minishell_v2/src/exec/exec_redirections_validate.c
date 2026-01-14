/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirections_validate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:10:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 20:10:00 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	validate_filename(t_redirect *redirect)
{
	if (redirect->files)
		return (0);
	errno = EINVAL;
	perror("minishell");
	return (-1);
}

static int	validate_input_redirect(t_redirect *redirect)
{
	int	fd;

	fd = open(redirect->files, O_RDONLY);
	if (fd == -1)
	{
		perror(redirect->files);
		return (-1);
	}
	close(fd);
	return (0);
}

static int	validate_output_redirect(t_redirect *redirect)
{
	int	flags;
	int	fd;

	flags = O_WRONLY | O_CREAT;
	if (redirect->type == REDIR_APPEND)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	fd = open(redirect->files, flags, 0644);
	if (fd == -1)
	{
		perror(redirect->files);
		return (-1);
	}
	close(fd);
	return (0);
}

int	validate_redirect(t_redirect *redirect)
{
	if (redirect->type == HEREDOC && redirect->files == NULL)
		return (0);
	if (validate_filename(redirect) == -1)
		return (-1);
	if (redirect->type == REDIR_IN || redirect->type == HEREDOC)
		return (validate_input_redirect(redirect));
	return (validate_output_redirect(redirect));
}
