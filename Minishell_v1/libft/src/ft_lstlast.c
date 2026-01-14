/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:58:42 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/14 13:07:29 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Trouve le dernier élément d'une liste chaînée.
 *
 * La fonction `ft_lstlast_bonus` prend en entrée un pointeur vers la tête
 * d'une liste chaînée et renvoie un pointeur vers le dernier élément de
 * la liste. Si la liste est vide (c'est-à-dire que `lst` est `NULL`),
 * la fonction retourne `NULL`. Cette version "bonus" peut inclure des
 * optimisations spécifiques ou des comportements supplémentaires comme la
 * gestion de types particuliers de données.
 *
 * @param lst Le pointeur vers le premier élément de la liste (tête de la liste).
 *
 * @return Le dernier élément de la liste, ou `NULL` si la liste est vide.
 *
 * @note Cette version peut comporter des vérifications ou des optimisations
 * supplémentaires, mais elle fonctionne essentiellement comme une fonction
 * de base pour parcourir la liste jusqu'à son dernier élément.
 */
t_element	*ft_lstlast(t_element *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
