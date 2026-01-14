/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:05:15 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/16 09:55:17 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*ft_strnncpy(char *dest, const char *s1, size_t min, size_t max)
{
	size_t	i;

	i = 0;
	while (min < max)
	{
		dest[i] = s1[min];
		i++;
		min++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_char_in_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
/**
 * @brief Supprime les caractères spécifiés du début et de la fin d'une
 * 	chaîne.
 *
 * La fonction `ft_strtrim` prend une chaîne de caractères `s1` et un
 * ensemble de caractères`set`, et retourne une nouvelle chaîne dans
 * laquelle les caractères de `set` sont supprimés du début et de la fin
 * de `s1`.La fonction alloue dynamiquement de la mémoire pour
 * la chaîne résultante.
 * Si `s1` ou `set` est `NULL`, la fonction retourne `NULL`. La mémoire
 * allouée pour la chaîne retournée doit être libérée après usage.
 *
 * @param s1 La chaîne de caractères à traiter.
 * @param set L'ensemble de caractères à supprimer du début et de la fin de `s1`.
 *
 * @return Une nouvelle chaîne contenant `s1` sans les caractères de `set`
 * au début et à la fin,ou `NULL` en cas d'allocation échouée.
 *
 * @note La fonction alloue dynamiquement la mémoire pour la chaîne résultante.
 *  Il est donc nécessaire de libérer cette mémoire.
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	min;
	size_t	max;
	char	*dest;

	max = ft_strlen(s1);
	min = 0;
	if (!set)
		return (0);
	while (s1[min] && ft_char_in_set(set, s1[min]))
		min++;
	while (max > 0 && ft_char_in_set(set, s1[max - 1]))
		max--;
	if (max < min)
		dest = ft_strdup("\0");
	else
	{
		dest = (char *)malloc((max - min + 1) * sizeof(char));
		if (!dest)
			return (NULL);
		dest = ft_strnncpy(dest, s1, min, max);
	}
	return (dest);
}
