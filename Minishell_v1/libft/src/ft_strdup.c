/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:03:36 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/23 16:35:32 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Crée une copie dynamique d'une chaîne de caractères.
 *
 * La fonction `ft_strdup` alloue de la mémoire et crée une copie exacte de
 * la chaîne de caractères `s1`. La chaîne copié est terminée par un
 * caractère nul (`'\0'`). Si l'allocation échoue, la fonction retourne `NULL`.
 * Il est important de libérer la mémoire allouée pour la chaîne retournée
 * après usage.
 *
 * @param s1 La chaîne de caractères à copier.
 *
 * @return Une nouvelle chaîne contenant une copie de `s1`, ou `NULL`
 * 	si l'allocation échoue.
 *
 * @note La fonction alloue dynamiquement de la mémoire pour la nouvelle chaîne.
 * 	Il est donc nécessaire de libérer cette mémoire une fois qu'elle n'est
 * 	plus utilisée.
 */
char	*ft_strdup(const char *src)
{
	char	*s;
	int		l;
	int		i;

	if (!src)
		return (NULL);
	l = ft_strlen(src);
	s = (char *)malloc((l + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (i < l)
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
