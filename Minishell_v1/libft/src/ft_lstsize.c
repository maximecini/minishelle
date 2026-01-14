/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:22:07 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/26 21:09:56 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Calcule la taille d'une liste chaînée.
 *
 * La fonction `ft_lstsize` prend en entrée un pointeur vers la tête d'une
 * liste chaînée et retourne le nombre d'éléments dans cette liste.
 * La fonction parcourt la liste à partir de la tête jusqu'à ce qu'elle
 * atteigne un élément NULL (fin de la liste).
 *

	* @param lst Le pointeur vers le premier élément de la liste (tête de la liste).
 *
 * @return Le nombre d'éléments dans la liste. Si la liste est vide, la
 * 	fonction retourne 0.
 *
 * @note La fonction effectue une itération sur tous les éléments de
 * 	la liste pour calculer sa taille.Si la liste est vide (`lst` est NULL),
 * 	la fonction retourne 0.
 */
int	ft_lstsize(t_element *lst)
{
	t_element	*temp;
	int			i;

	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
