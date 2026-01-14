/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:13:14 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:04:25 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Extrait une sous-chaîne à partir d'une chaîne donnée.
 *
 * La fonction `ft_substr` alloue une nouvelle chaîne qui est une sous-chaîne
 * de `s`, commençant à l'indice`start` et ayant une longueur
 * maximale de `len` caractères. Si `start` est plus grand que la longueur
 * de la chaîne `s`, la fonction retourne une chaîne vide. Si la
 * longueur de `s` à partir de `start` est inférieure à `len`,la fonction
 * retourne une sous-chaîne allant jusqu'à la fin de `s`. La mémoire pour
 * la sous-chaîne est allouée dynamiquement.Si l'allocation échoue,
 * la fonction retourne `NULL`.
 *
 * @param s La chaîne de caractères source à partir de laquelle extraire
 * 	la sous-chaîne.
 * @param start L'indice à partir duquel commencer l'extraction de
 * 	la sous-chaîne.
 * @param len La longueur maximale de la sous-chaîne.
 *
 * @return Une nouvelle chaîne contenant la sous-chaîne extraite, ou `NULL`
 * 	en cas d'échec d'allocation.
 *
 * @note La fonction alloue dynamiquement la mémoire pour la sous-chaîne
 * 	résultante. Il est donc nécessaire de libérer cette mémoire.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	l;

	l = ft_strlen(s);
	if (start > l)
		start = l;
	if (len > l - start)
		len = l - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
