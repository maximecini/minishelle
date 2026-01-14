/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:33:17 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/14 13:40:20 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Supprime tous les éléments d'une liste chaînée et libère la
 * 	mémoire associée.
 *
 * La fonction `ft_lstclear` prend en entrée un pointeur vers un
 * pointeur de tête de liste chaînée (`lst`) et une fonction de
 * suppression (`del`). Elle parcourt la liste et libère chaque élément de
 * la liste ainsi que son contenu à l'aide de la fonction `del`.Une fois tous
 * les éléments supprimés, le pointeur `lst` est mis à NULL pour éviter tout
 * accès à de la mémoire déjà libérée.
 *
 * @param lst Le pointeur vers le premier élément de la
 * 	liste (tête de la liste).
 * @param del La fonction à appliquer pour supprimer le contenu
 * 	de chaque élément.
 *
 * @return Aucune valeur de retour. La liste est modifiée directement et tous
 * 	les éléments sont supprimés.
 *
 * @note Cette version permet d'inclure des comportements spécifiques à
 * la gestion de la mémoire ou de la structure de la liste, comme des
 * vérifications supplémentaires ou des optimisations de performance.
 */
void	ft_lstclear(t_element **lst, void (*del)(void *))
{
	t_element	*element;

	if (!lst)
		return ;
	while (*lst)
	{
		element = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = element;
	}
}
