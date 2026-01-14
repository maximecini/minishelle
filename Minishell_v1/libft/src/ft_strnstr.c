/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:24:23 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/04/10 09:39:41 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Recherche la première occurrence d'une sous-chaîne dans
 * une chaîneprincipale, avec une limite.
 *
 * La fonction `ft_strnstr` recherche la première occurrence de
 * la sous-chaîne `to_find` dans la chaîne principale `str`, en ne
 * parcourant que les `size` premiers caractères de `str`. Si `to_find` est
 * une chaîne vide, la fonction retourne immédiatement `str`. Si `to_find`
 * est trouvé dans `str` dans la limite spécifiée, la fonction retourne
 * un pointeur vers le début de la première occurrence.
 * Si `to_find` n'est pas trouvé ou si `size` est nul, la fonction retourne
 * `NULL`.
 *
 * @param str La chaîne principale dans laquelle rechercher.
 * @param to_find La sous-chaîne à rechercher dans `str`.
 * @param size Le nombre de caractères dans `str` à parcourir.
 *
 * @return Un pointeur vers la première occurrence de `to_find` dans `str`,
 *  ou `NULL` si la sous-chaîne n'est pas trouvée.
 *
 * @note Cette fonction est utile pour effectuer des recherches dans des chaînes
 *  en limitant la recherche à un certain nombre de caractères, ce qui peut être
 * 	utile pour les recherches dans des portions spécifiques d'une chaîne ou pour
 * 	optimiser la recherche dans de grandes chaînes.
 */
char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	l_to_find;
	size_t	i;
	char	*s1;

	l_to_find = ft_strlen(to_find);
	s1 = (char *)str;
	i = 0;
	if (to_find[0] == '\0')
		return (s1);
	if (size == 0 || s1[0] == '\0')
	{
		return (NULL);
	}
	while (i < size)
	{
		if (ft_strncmp(s1, (char *)to_find, l_to_find) == 0)
		{
			if (i + l_to_find > size)
				return (NULL);
			return (s1);
		}
		s1++;
		i++;
	}
	return (0);
}
