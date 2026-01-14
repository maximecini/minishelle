/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_exec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:37:57 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/29 11:06:15 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*resolve_executable_or_exit(t_exec *exec, t_node_cmd *node_cmd,
		char **env)
{
	char	*e_path;

	get_path(exec, env);
	e_path = is_exec(exec, node_cmd->cmd);
	if (!e_path)
	{
		error_cmd(exec->error, node_cmd->cmd[0]);
		return (NULL);
	}
	return (e_path);
}

void	ft_dup(int fd, int output, int file)
{
	if (dup2(fd, output) == -1)
	{
		if (file == 2)
			print_error("Permission denied");
		else if (!file)
			perror("dup");
		exit(errno);
	}
	close(fd);
}
