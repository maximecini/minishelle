/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:46:45 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 15:05:19 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/function.h"

int	is_single_builtin(t_list *lst_cmd)
{
	t_cmd	*node_cmd;
	int		result;

	if (!lst_cmd || lst_cmd->next)
		return (0);
	node_cmd = (t_cmd *)lst_cmd->content;
	if (!node_cmd || !node_cmd->cmd[0] || !node_cmd->cmd[0][0])
		return (0);
	result = is_builtin(node_cmd->cmd[0]);
	return (result);
}

int	try_builtin_and_exit_if_ok(t_cmd *node_cmd, t_list **lst_env,
		t_list **lst_cmd)
{
	int	status;

	if (is_builtin(node_cmd->cmd[0]))
	{
		status = execute_builtin(node_cmd, lst_env, lst_cmd);
		free_all(lst_env, NULL, NULL);
		exit(status);
	}
	return (0);
}

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	return (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd") || !ft_strcmp(cmd,
			"pwd") || !ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "exit") || !ft_strcmp(cmd,
			":"));
}

// Exécute la fonction builtin correspondant à la commande dans 'line'
// Cette fonction split la ligne en tokens, puis compare le premier token
// aux noms des builtins connus. Si une correspondance est trouvée, elle appelle
// la fonction builtin associée.
// Ne gère pas encore les arguments passés aux builtins (à faire).

int	execute_builtin(t_cmd *node_cmd, t_list **lst_env, t_list **lst_cmd)
{
	int	status;

	if (!ft_strcmp(node_cmd->cmd[0], "echo"))
		status = echo(node_cmd);
	else if (!ft_strcmp(node_cmd->cmd[0], "cd"))
		status = cd(node_cmd->cmd, lst_env);
	else if (!ft_strcmp(node_cmd->cmd[0], "pwd"))
		status = pwd(node_cmd);
	else if (!ft_strcmp(node_cmd->cmd[0], "export"))
		status = export(node_cmd, lst_env);
	else if (!ft_strcmp(node_cmd->cmd[0], "env"))
		status = env(node_cmd, *lst_env);
	else if (!ft_strcmp(node_cmd->cmd[0], "unset"))
		status = unset(node_cmd, lst_env);
	else if (!ft_strcmp(node_cmd->cmd[0], "exit"))
		status = exit_builtin(node_cmd, lst_env, lst_cmd);
	else if (!ft_strcmp(node_cmd->cmd[0], ":"))
		status = 0;
	else
		status = 1;
	node_cmd->status = status;
	return (status);
}
