/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_path.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:30:54 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/30 15:33:31 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	get_path(t_exec *exec, char **env)
{
	int	i;

	i = 0;
	exec->path = NULL;
	if (!env)
	{
		exec->path = ft_strdup("");
		return ;
	}
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			exec->path = ft_substr(env[i], 5, ft_strlen(env[i]));
			return ;
		}
		i++;
	}
	exec->path = NULL;
}

char	*get_path_cmd(t_exec *exec, char *cmd)
{
	char	**paths;
	char	*command;
	char	*tmp;
	int		i;

	i = 0;
	paths = ft_split(exec->path, ':');
	if (!paths)
		return (NULL);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/", 0, 0);
		if (!tmp)
			return (ft_free_split(paths), NULL);
		command = ft_strjoin(tmp, cmd, 1, 0);
		if (!command)
			return (ft_free_split(paths), NULL);
		exec->error = acces_cmd(command);
		if (!exec->error)
			return (ft_free_split(paths), command);
		free(command);
		i++;
	}
	return (ft_free_split(paths), NULL);
}

char	*is_exec(t_exec *exec, char **cmd)
{
	char	*new_cmd;

	new_cmd = NULL;
	if (!cmd[0] || cmd[0][0] == '\0')
	{
		exec->error = 127;
		return (NULL);
	}
	if (ft_strchr(cmd[0], '/'))
		new_cmd = ft_strdup(cmd[0]);
	else
		new_cmd = get_path_cmd(exec, cmd[0]);
	if (!new_cmd)
	{
		exec->error = 127;
		return (ft_strdup(cmd[0]));
	}
	exec->error = acces_cmd(new_cmd);
	if (exec->error)
	{
		free(new_cmd);
		error_file(exec->error, new_cmd);
		return (NULL);
	}
	return (new_cmd);
}

int	acces_cmd(char *cmd)
{
	struct stat	st;

	if (stat(cmd, &st) == -1)
		return (127);
	if (S_ISDIR(st.st_mode))
	{
		errno = EISDIR;
		return (126);
	}
	if (access(cmd, X_OK) == -1)
		return (126);
	return (0);
}
