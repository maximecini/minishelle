/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:41:54 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 14:32:47 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *lst, void (*del)(void *))
{
	t_list	*new_elem;
	t_list	*new_list;
	void	*content;

	new_list = NULL;
	new_elem = NULL;
	if (lst == NULL || del == NULL)
		return (NULL);
	while (lst)
	{
		content = lst->content;
		new_elem = ft_lstnew(content);
		if (new_elem == NULL)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	new_elem->next = NULL;
	return (new_list);
}
