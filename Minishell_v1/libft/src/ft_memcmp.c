/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:04:56 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:04:48 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Compare deux zones mémoire.
 *
 * La fonction `ft_memcmp` compare les `n` premiers octets de deux
 * zones mémoire.Elle retourne un entier qui indique la différence entre
 * les deux zones mémoire :
 * - Un nombre négatif si p1 est inférieure à p2.
 * - Un nombre positif si p1 est supérieure à la p2.
 * - Zéro si les deux zones mémoire sont égales.
 *
 * @param s1 Pointeur vers la première zone mémoire à comparer.
 * @param s2 Pointeur vers la deuxième zone mémoire à comparer.
 * @param n Le nombre d'octets à comparer.
 *
 * @return Un nombre négatif, zéro ou positif, selon le résultat de
 * 	la comparaison.
 *
 * @note Cette fonction est équivalente à la fonction standard `memcmp`
 * 	de la bibliothèque C.
 */
int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	const unsigned char	*s1;
	const unsigned char	*s2;
	size_t				i;

	s1 = p1;
	s2 = p2;
	i = 0;
	while (i < size)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
