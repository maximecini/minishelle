/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:26:36 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/14 13:09:32 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Ajoute un élément à la fin d'une liste chaînée.
 *
 * La fonction `ft_lstadd_back` prend en entrée un pointeur vers
 * un pointeur de tête de liste chaînée (`lst`) et un pointeur vers
 * le nouvel élément (`new`). Elle ajoute cet élément à la fin de
 * la liste existante.Si la liste est vide (c'est-à-dire si `lst` est
 * NULL), l'élément est ajouté comme premier élément de la liste.
 *
 * @param lst Le pointeur vers le premier élément de la liste (tête de la liste).
 * @param new Le nouvel élément à ajouter à la fin de la liste.
 *
 * @return Aucune valeur de retour. La liste est modifiée directement.
 *
 * @note Si `lst` est NULL, l'élément `new` devient la tête de la liste.
 */
void	ft_lstadd_back(t_element **lst, t_element *new)
{
	t_element	*temp;

	if (!new)
		return ;
	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		new->prev = NULL;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
	new->prev = temp;
}
