/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 06:33:51 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/14 13:07:29 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Ajoute un élément au début d'une liste chaînée.
 *
 * La fonction `ft_lstadd_front` prend en entrée un pointeur vers
 * un pointeur de tête de liste chaînée (`lst`) et un pointeur vers
 * le nouvel élément (`new`). Elle ajoute cet élément au début de la
 * liste existante, en modifiant la tête de la liste pour qu'elle pointe
 * vers le nouvel élément. Cette fonction est généralement utilisée pour
 * insérer un élément en tête de liste sans avoir à parcourir la liste.
 *
 * @param lst Le pointeur vers le premier élément de la liste (tête de la liste).
 * @param new Le nouvel élément à ajouter au début de la liste.
 *
 * @return Aucune valeur de retour. La liste est modifiée directement.
 *
 * @note Cette version peut comporter des comportements supplémentaires, comme
 *       la gestion de certains types spécifiques de données ou l'optimisation
 * 	de certaines opérations.
 */
void	ft_lstadd_front(t_element **lst, t_element *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
