/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:05:12 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 15:53:25 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static int	expand_single_arg(char **arg, t_list *lst_env)
{
	char	*expanded;
	char	*old_arg;

	if (!arg || !*arg)
		return (0);
	old_arg = *arg;
	expanded = expand_string(*arg, lst_env);
	if (!expanded)
		return (-1);
	free(old_arg);
	*arg = expanded;
	return (0);
}

int	expand_command_args(t_cmd *node_cmd, t_list *lst_env)
{
	int	i;

	if (!node_cmd || !node_cmd->cmd)
		return (0);
	i = 0;
	while (node_cmd->cmd[i])
	{
		if (expand_single_arg(&node_cmd->cmd[i], lst_env) == -1)
			return (-1);
		i++;
	}
	return (0);
}
