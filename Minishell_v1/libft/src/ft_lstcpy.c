/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:06:12 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/26 21:09:44 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_element	*ft_lstcpy(t_element *lst, void (*del)(void *))
{
	t_element	*new_elem;
	t_element	*new_list;
	void		*content;

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
