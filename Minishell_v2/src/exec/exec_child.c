/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:44:06 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/15 19:44:06 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "function.h"
#include <sys/stat.h>

static void	run_builtin_child(t_cmd *cmd, t_exec *exec)
{
	int		status;
	t_list	*env_data;

	env_data = exec->lst_env;
	status = execute_builtin(cmd, &env_data, NULL);
	cleanup_child_inherited(exec);
	exit(status);
}

static void	exit_path_error(t_cmd *cmd, t_exec *exec)
{
	struct stat	info;

	if (ft_strchr(cmd->cmd[0], '/') && access(cmd->cmd[0], F_OK) == 0)
	{
		if (stat(cmd->cmd[0], &info) == 0 && S_ISDIR(info.st_mode))
			handle_exec_error(cmd->cmd[0], "Is a directory");
		else
			handle_exec_error(cmd->cmd[0], "Permission denied");
		cleanup_child_inherited(exec);
		exit(126);
	}
	if (ft_strchr(cmd->cmd[0], '/'))
		handle_exec_error(cmd->cmd[0], "No such file or directory");
	else
		handle_exec_error(cmd->cmd[0], "command not found");
	cleanup_child_inherited(exec);
	exit(127);
}

static void	free_env_array(char **env_array)
{
	int	index;

	if (!env_array)
		return ;
	index = 0;
	while (env_array[index])
	{
		free(env_array[index]);
		index++;
	}
	free(env_array);
}

static void	exec_external_command(t_cmd *cmd, t_exec *exec, char *path)
{
	char	**env_array;

	env_array = env_list_to_array(exec->lst_env);
	if (!env_array)
	{
		free(path);
		cleanup_child_inherited(exec);
		exit(1);
	}
	execve(path, cmd->cmd, env_array);
	perror(path);
	free(path);
	free_env_array(env_array);
	cleanup_child_inherited(exec);
	exit(126);
}

void	execute_child_process(t_cmd *cmd, t_exec *exec)
{
	char	*path;

	if (!cmd->cmd[0] || !cmd->cmd[0][0])
	{
		cleanup_child_inherited(exec);
		exit(0);
	}
	if (is_builtin(cmd->cmd[0]))
		run_builtin_child(cmd, exec);
	path = find_command_path(cmd->cmd[0], exec->lst_env);
	if (!path)
		exit_path_error(cmd, exec);
	exec_external_command(cmd, exec, path);
}
