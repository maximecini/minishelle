/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:49:42 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/15 19:49:42 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "function.h"
#include <sys/stat.h>

static char	*dup_if_executable(char *cmd)
{
	struct stat	info;

	if (access(cmd, F_OK) != 0)
		return (NULL);
	if (stat(cmd, &info) == 0 && S_ISDIR(info.st_mode))
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

static char	**get_paths_array(t_list *lst_env)
{
	char	*path_env;
	char	**paths;

	path_env = get_env_value("PATH", lst_env);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	free(path_env);
	return (paths);
}

static char	*search_in_paths(char *cmd, char **paths)
{
	int		index;
	char	*tmp;
	char	*full;

	index = 0;
	while (paths[index])
	{
		tmp = ft_strjoin(paths[index], "/", 0, 0);
		if (!tmp)
			return (NULL);
		full = ft_strjoin(tmp, cmd, 1, 0);
		if (!full)
			return (NULL);
		if (access(full, F_OK | X_OK) == 0)
			return (full);
		free(full);
		index++;
	}
	return (NULL);
}

static void	free_paths(char **paths)
{
	int	index;

	if (!paths)
		return ;
	index = 0;
	while (paths[index])
	{
		free(paths[index]);
		index++;
	}
	free(paths);
}

char	*find_command_path(char *cmd, t_list *lst_env)
{
	char	**paths;
	char	*full;

	if (ft_strchr(cmd, '/'))
		return (dup_if_executable(cmd));
	paths = get_paths_array(lst_env);
	if (!paths)
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	full = search_in_paths(cmd, paths);
	free_paths(paths);
	return (full);
}
