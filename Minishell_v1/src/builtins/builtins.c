/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:20:46 by thodavid          #+#    #+#             */
/*   Updated: 2025/07/31 19:38:27 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

int	is_single_builtin(t_element *lst_cmd)
{
	t_node_cmd	*node_cmd;
	int			result;

	if (!lst_cmd || lst_cmd->next)
		return (0);
	node_cmd = (t_node_cmd *)lst_cmd->content;
	if (!node_cmd || !node_cmd->cmd || !node_cmd->cmd[0])
		return (1);
	if (!node_cmd->cmd[0][0])
		return (1);
	result = is_builtin(node_cmd->cmd[0]);
	return (result);
}

int	try_builtin_and_exit_if_ok(t_node_cmd *node_cmd, t_element **lst_env,
		t_element **lst_cmd)
{
	int	status;

	if (is_builtin(node_cmd->cmd[0]))
	{
		status = execute_builtin(node_cmd, lst_env, lst_cmd);
		g_last_status = status;
		free_lst(lst_env, lst_cmd);
		exit(status);
	}
	return (0);
}

// Fonction pour vérifier si c'est une builtin
int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	return (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd") || !ft_strcmp(cmd,
			"pwd") || !ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "exit"));
}

// Exécute la fonction builtin correspondant à la commande dans 'line'
// Cette fonction split la ligne en tokens, puis compare le premier token
// aux noms des builtins connus. Si une correspondance est trouvée, elle appelle
// la fonction builtin associée.
// Ne gère pas encore les arguments passés aux builtins (à faire).
int	execute_builtin(t_node_cmd *node_cmd, t_element **lst_env,
		t_element **lst_cmd)
{
	if (!ft_strcmp(node_cmd->cmd[0], "echo"))
		return (echo(node_cmd));
	else if (!ft_strcmp(node_cmd->cmd[0], "cd"))
		return (cd(node_cmd->cmd, lst_env));
	else if (!ft_strcmp(node_cmd->cmd[0], "pwd"))
		return (pwd());
	else if (!ft_strcmp(node_cmd->cmd[0], "export"))
		return (export(node_cmd, lst_env));
	else if (!ft_strcmp(node_cmd->cmd[0], "env"))
		return (env(*lst_env));
	else if (!ft_strcmp(node_cmd->cmd[0], "unset"))
		return (unset(node_cmd, lst_env));
	else if (!ft_strcmp(node_cmd->cmd[0], "exit"))
		return (exit_builtin(node_cmd, lst_env, lst_cmd));
	return (1);
}
