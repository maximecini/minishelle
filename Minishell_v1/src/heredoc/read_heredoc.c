/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:21:24 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/28 09:10:47 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	close_and_reset_fd(t_redirect *redirect)
{
	if (redirect->here_doc_fd != -1)
	{
		close(redirect->here_doc_fd);
		redirect->here_doc_fd = -1;
	}
}

static int	handle_child_exit(int status, t_redirect *redirect)
{
	int	code;

	if (WIFEXITED(status))
	{
		code = WEXITSTATUS(status);
		close_and_reset_fd(redirect);
		g_last_status = code;
		if (code == 130)
			unlink(redirect->heredoc_filename);
		return (code);
	}
	if (WIFSIGNALED(status))
	{
		close_and_reset_fd(redirect);
		if (WTERMSIG(status) == SIGINT)
		{
			unlink(redirect->heredoc_filename);
			return (130);
		}
	}
	return (0);
}

static t_heredoc_data	*create_heredoc_data(t_redirect *redirect)
{
	t_heredoc_data	*heredoc_data;

	heredoc_data = malloc(sizeof(t_heredoc_data));
	if (!heredoc_data)
		return (NULL);
	heredoc_data->here_doc_fd = redirect->here_doc_fd;
	heredoc_data->delimiteur = ft_strdup(redirect->delimiteur);
	heredoc_data->line = NULL;
	if (!heredoc_data->delimiteur)
	{
		free(heredoc_data);
		return (NULL);
	}
	heredoc_data->delim_len = ft_strlen(heredoc_data->delimiteur);
	return (heredoc_data);
}

int	read_heredoc_fork(t_redirect *redirect, t_element **lst_cmd,
		t_element **lst_env)
{
	pid_t			pid;
	int				status;
	t_heredoc_data	*data;

	data = NULL;
	pid = fork();
	if (pid < 0)
		return (perror("fork heredoc"), 1);
	if (pid == 0)
	{
		set_heredoc_data(create_heredoc_data(redirect));
		data = *get_heredoc_data();
		free_lst(lst_env, lst_cmd);
		if (!data)
		{
			free_heredoc_data(data);
			exit(1);
		}
		child_read_heredoc(data);
		free_heredoc_data(data);
	}
	waitpid(pid, &status, 0);
	handle_status(status);
	return (handle_child_exit(status, redirect));
}
