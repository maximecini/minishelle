/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:02:49 by thodavid          #+#    #+#             */
/*   Updated: 2025/07/26 21:07:04 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

int	env(t_element *lst_env)
{
	t_node_env	*node_env;

	while (lst_env)
	{
		node_env = (t_node_env *)lst_env->content;
		if (node_env->value)
			printf("%s=%s\n", node_env->key, node_env->value);
		lst_env = lst_env->next;
	}
	return (0);
}
