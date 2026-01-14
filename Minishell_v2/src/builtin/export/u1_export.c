/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u1_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:26:36 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 15:27:34 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	export_print(t_list **lst_env)
{
	t_list	*cpy;

	cpy = ft_lstcpy(*lst_env, free_node_env_content);
	if (!cpy)
		return (1);
	ft_sort_lst(cpy, cmp_key);
	print_lst_env(cpy);
	ft_lstclear(&cpy, NULL);
	return (0);
}
