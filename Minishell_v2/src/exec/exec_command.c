/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:00:13 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 23:40:35 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "function.h"

static int	handle_empty_command(t_cmd *cmd)
{
	int	result;
	int	fds[2];

	if (!cmd || (cmd->cmd[0] && cmd->cmd[0][0]))
		return (-1);
	if (cmd->cmd_quoted && cmd->cmd_quoted[0])
	{
		ft_putstr_fd(": command not found\n", 2);
		return (127);
	}
	if (!cmd->nb_redirect)
		return (-3);
	if (save_stdio(fds) == -1)
		return (1);
	result = setup_redirections(cmd);
	restore_stdio(fds);
	if (result == -1)
		return (1);
	return (0);
}

static int	handle_bang_command(t_cmd *cmd)
{
	int	result;
	int	fds[2];

	if (!cmd || !cmd->cmd[0] || ft_strcmp(cmd->cmd[0], "!") || cmd->cmd[1])
		return (-1);
	cmd->status = 1;
	if (!cmd->nb_redirect)
		return (1);
	if (save_stdio(fds) == -1)
		return (1);
	result = setup_redirections(cmd);
	restore_stdio(fds);
	if (result == -1)
		return (1);
	return (1);
}

static int	handle_exit_command(t_cmd *cmd, t_list **lst_cmd, t_list **lst_env)
{
	int	exit_code;

	if (!cmd || !cmd->cmd[0] || ft_strcmp(cmd->cmd[0], "exit"))
		return (-1);
	exit_code = execute_builtin(cmd, lst_env, lst_cmd);
	if (exit_code <= -1000)
		return (-(exit_code + 1000));
	return (-(exit_code + 2000));
}

static int	run_single_builtin(t_cmd *cmd, t_list **lst_cmd, t_list **lst_env)
{
	int	fds[2];
	int	status;

	if (save_stdio(fds) == -1)
		return (1);
	if (setup_redirections(cmd) == -1)
	{
		restore_stdio(fds);
		return (1);
	}
	status = execute_builtin(cmd, lst_env, lst_cmd);
	restore_stdio(fds);
	return (status);
}

int	execute_command(t_list *lst_cmd, t_list **lst_env, char **tab,
		t_cleanup_ctx *ctx)
{
	t_cmd	*cmd;
	int		cmd_count;
	int		result;

	if (!lst_cmd)
		return (1);
	cmd_count = ft_lstsize(lst_cmd);
	cmd = (t_cmd *)lst_cmd->content;
	if (cmd_count == 1)
	{
		result = handle_empty_command(cmd);
		if (result != -1)
			return (result);
		result = handle_bang_command(cmd);
		if (result != -1)
			return (result);
		if (cmd && cmd->cmd[0] && !ft_strcmp(cmd->cmd[0], "exit"))
			return (handle_exit_command(cmd, &lst_cmd, lst_env));
		if (is_single_builtin(lst_cmd))
			return (run_single_builtin(cmd, &lst_cmd, lst_env));
	}
	return (execute_pipeline(lst_cmd, lst_env, tab, ctx));
}
