/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:56:26 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:04:33 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
 * @brief Remplit une zone mémoire avec une valeur spécifique.
 *
 * La fonction `ft_memset` remplit les `n` premiers octets de la zone
 * mémoire pointée par `s` avec la valeur spécifiée par `c`.
 * Le remplissage est effectué octet par octet.La fonction est souvent
 * utilisée pour initialiser des zones mémoire à une valeur spécifique,comme
 * zéro ou d'autres valeurs constantes.
 *
 * @param s Pointeur vers la zone mémoire à remplir.
 * @param c La valeur à remplir dans la mémoire (convertie en unsigned char).
 * @param n Le nombre d'octets à remplir dans la zone mémoire.
 *
 * @return Un pointeur vers la zone mémoire modifiée (`s`).
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}
