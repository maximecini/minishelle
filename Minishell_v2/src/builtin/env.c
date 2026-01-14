/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:46:59 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/15 20:19:53 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	env(t_list *lst_env)
{
	t_env	*node_env;

	while (lst_env)
	{
		node_env = (t_env *)lst_env->content;
		if (node_env->value)
			printf("%s=%s\n", node_env->key, node_env->value);
		lst_env = lst_env->next;
	}
	return (0);
}
