/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 06:26:20 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/14 13:07:29 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Crée un nouvel élément pour une liste chaînée.
 *
 * La fonction `ft_lstnew` alloue de la mémoire pour un nouvel élément
 * de la liste chaînée et initialise son contenu avec la valeur fournie.
 * Le champ `next` de l'élément est initialisé à `NULL`, ce qui signifie que
 * l'élément ne pointe vers aucun autre élément.Cette fonction est
 * généralement utilisée pour ajouter un nouvel élément à la liste.
 *
 * @param content Le contenu de l'élément, qui sera copié dans le `content`
 * 	du maillon.
 *
 * @return Un pointeur vers le nouvel élément créé, ou `NULL`
 * 	si l'allocation échoue.
 *
 * @note Le contenu est dupliqué dans l'élément. Si le contenu est une chaîne
 * 	de caractères ou un autre type de donnée allouée dynamiquement, il est
 * 	important de libérer cette mémoire lorsque l'élément est supprimé.
 */
t_element	*ft_lstnew(void *content)
{
	t_element	*elememt;

	elememt = (t_element *)malloc(sizeof(t_element));
	if (!elememt)
		return (NULL);
	elememt->content = content;
	elememt->next = NULL;
	return (elememt);
}
