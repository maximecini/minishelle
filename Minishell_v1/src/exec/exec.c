/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:13:17 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/29 10:55:41 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

int	execution(t_element *lst_cmd, t_element **lst_env)
{
	t_exec		exec;
	t_node_cmd	*node_cmd;
	int			ret;

	g_last_status = 0;
	ret = setup_execution(&exec, lst_cmd, lst_env);
	if (ret)
		return (ret);
	handle_signals_for_parent();
	if (is_single_builtin(lst_cmd))
	{
		node_cmd = (t_node_cmd *)lst_cmd->content;
		return (exec_single_builtin(&exec, node_cmd, lst_env, &lst_cmd));
	}
	exec_all_commands(&exec, lst_cmd, lst_env);
	wait_and_finalize(&exec, lst_cmd);
	return (exec.status);
}
