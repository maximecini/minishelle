/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:24:07 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/28 20:28:40 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	error_cmd(int error, char *cmd)
{
	char	*err;

	err = NULL;
	g_last_status = error;
	if (error == 127)
	{
		err = ft_strjoin("minishell: command not found: ", cmd, 0, 0);
		print_error(err);
		free(err);
	}
	else if (error == 126)
	{
		err = ft_strjoin("minishell: Permission denied: ", cmd, 0, 0);
		print_error(err);
		free(err);
	}
}

void	error_file(int error, char *file)
{
	const char	*msg;

	if (error == 127)
		msg = "No such file or directory";
	else if (error == 126)
	{
		if (errno == EISDIR)
			msg = "Is a directory";
		else if (errno == EACCES)
			msg = "Permission denied";
		else
			msg = strerror(errno);
	}
	else
		msg = "Error";
	fprintf(stderr, "minishell: %s: %s\n", file, msg);
}

void	print_error(char *str)
{
	ft_putendl_fd(str, 2);
}
