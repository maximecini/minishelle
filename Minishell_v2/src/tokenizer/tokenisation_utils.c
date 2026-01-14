/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:20:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:19:28 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	add_token_to_list(t_list **lst_token, t_token *token_ptr)
{
	t_list	*new_node;

	new_node = ft_lstnew(token_ptr);
	if (!new_node)
	{
		free(token_ptr);
		ft_lstclear(lst_token, free_node_token_content);
		return (0);
	}
	ft_lstadd_back(lst_token, new_node);
	return (1);
}
