/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:47:28 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 15:16:07 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	env(t_cmd *node_cmd, t_list *lst_env)
{
	t_env	*node_env;

	if (node_cmd && node_cmd->cmd[1])
	{
		ft_putstr_fd("env: '", 2);
		ft_putstr_fd(node_cmd->cmd[1], 2);
		ft_putstr_fd("': No such file or directory\n", 2);
		return (127);
	}
	while (lst_env)
	{
		node_env = (t_env *)lst_env->content;
		if (node_env->value)
			printf("%s=%s\n", node_env->key, node_env->value);
		lst_env = lst_env->next;
	}
	return (0);
}
