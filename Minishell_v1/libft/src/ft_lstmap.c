/* ************************************************************************** */
/*
 *                                     */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:59:58 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/17 03:58:37 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Applique une fonction à chaque élément d'une liste chaînée et crée
 * 	une nouvelle liste.
 *
 * La fonction `ft_lstmap` prend en entrée un pointeur vers la tête
 * d'une liste chaînée (`lst`),une fonction de transformation (`f`)
 * et une fonction de suppression (`del`). Elle parcourt la liste,
 * applique la fonction de transformation `f` sur chaque élément,
 * et crée une nouvelle liste avec les résultats. Si une erreur d'allocation
 * mémoire se produit, elle libère la mémoire déjà allouée à l'aide de la
 * fonction `del` pour éviter les fuites de mémoire.
 *
 * @param lst Le pointeur vers le premier élément de la liste.
 * @param f La fonction de transformation à appliquer à chaque élément
 * 	de la liste.
 * @param del La fonction de suppression à appliquer au contenu des éléments
 * 	en cas d'erreur.
 *
 * @return La nouvelle liste contenant les éléments transformés, ou NULL
 * 	si l'allocation échoue.
 *
 * @note Cette version peut inclure des vérifications supplémentaires ou des
 * optimisations de performance,telles que la gestion de types de données
 *  spécifiques ou des erreurs d'allocation.
 */
t_element	*ft_lstmap(t_element *lst, void *(*f)(void *), void (*del)(void *))
{
	t_element	*new_elem;
	t_element	*new_list;
	void		*content;

	new_list = NULL;
	new_elem = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
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
