/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:36:53 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 18:50:15 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	cleanup_and_exit(t_exec *exec, t_element **lst_env, t_element **lst_cmd,
		int exit_code)
{
	(void)exec;
	free_lst(lst_env, lst_cmd);
	exit(exit_code);
}

int	setup_command_execution(t_exec *exec, t_node_cmd *node_cmd,
		t_element **lst_env, t_element **lst_cmd)
{
	int	err;
	int	validation_err;

	err = setup_pipes(exec);
	if (err)
		cleanup_and_exit(exec, lst_env, lst_cmd, err);
	validation_err = check_command_valid(node_cmd);
	if (validation_err)
		cleanup_and_exit(exec, lst_env, lst_cmd, validation_err);
	err = process_redirections(exec, node_cmd);
	if (err)
		cleanup_and_exit(exec, lst_env, lst_cmd, err);
	return (0);
}

void	execute_external_command(t_exec *exec, t_node_cmd *node_cmd,
		t_element **lst_env, t_element **lst_cmd)
{
	char	*e_path;
	char	**env;

	env = NULL;
	if (lst_env && *lst_env)
		env = cpy_lst_to_tab(*lst_env);
	exec->path = NULL;
	exec->error = 0;
	e_path = resolve_executable_or_exit(exec, node_cmd, env);
	if (execve(e_path, node_cmd->cmd, env) == -1)
	{
		if (e_path && ft_strlen(e_path) > 0)
			error_cmd(127, node_cmd->cmd[0]);
		free(exec->path);
		ft_free_split(env);
		free(e_path);
		cleanup_and_exit(exec, lst_env, lst_cmd, 127);
	}
}

void	process_command(t_exec *exec, t_node_cmd *node_cmd, t_element **lst_env,
		t_element **lst_cmd)
{
	setup_command_execution(exec, node_cmd, lst_env, lst_cmd);
	if ((!node_cmd->cmd || !node_cmd->cmd[0] || !node_cmd->cmd[0][0])
		&& node_cmd->nb_redirect > 0)
		cleanup_and_exit(exec, lst_env, lst_cmd, 0);
	if (try_builtin_and_exit_if_ok(node_cmd, lst_env, lst_cmd))
		cleanup_and_exit(exec, lst_env, lst_cmd, g_last_status);
	execute_external_command(exec, node_cmd, lst_env, lst_cmd);
}
