/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:40:17 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/04/11 21:22:03 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Compare les `n` premiers caractères de deux chaînes de caractères.
 *
 * La fonction `ft_strncmp` compare les `n` premiers caractères de
 * deux chaînes `s1` et `s2`.Elle retourne un entier qui indique la différence
 * entre les deux chaînes :
 * - Un nombre négatif si `s1` est inférieur à `s2`.
 * - Un nombre positif si `s1` est supérieur à `s2`.
 * - Zéro si les `n` premiers caractères des deux chaînes sont égaux.
 * Si l'une des chaînes est plus courte que l'autre et que la comparaison
 * atteint la fin de la chaîne,la fonction renvoie la différence entre
 * les caractères nuls (ce qui est équivalent à une comparaison avec `'\0'`).
 *
 * @param s1 La première chaîne de caractères à comparer.
 * @param s2 La deuxième chaîne de caractères à comparer.
 * @param n Le nombre de caractères à comparer.
 *
 * @return Un nombre négatif, zéro, ou un nombre positif, en fonction
 * 	du résultat de la comparaison.
 *
 * @note Cette fonction est utile pour effectuer des comparaisons limitées
 * 	de chaînes sans avoir besoin de les comparer entièrement.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i] && (s1[i] && s2[i]) && i < n))
		i++;
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}
