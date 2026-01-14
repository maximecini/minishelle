/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:03:07 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:04:36 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
 * @brief Déplace une zone mémoire vers une autre zone mémoire.
 *
 * La fonction `ft_memmove` copie `n` octets de la zone mémoire source (`src`)
 * vers la zone mémoire destination (`dst`), en gérant correctement
 * les chevauchements entre ces zones.Contrairement à `ft_memcpy`, qui ne gère
 * pas les chevauchements,`ft_memmove` garantit que les données seront
 * copiées correctement même si les zones source et destination se chevauchent,
 * en copiant d'abord dans un tampon temporaire si nécessaire.
 *
 * @param dst Pointeur vers la zone mémoire de destination où les données
 * 	doivent être copiées.
 * @param src Pointeur vers la zone mémoire source à copier.
 * @param n Le nombre d'octets à copier.
 *
 * @return Un pointeur vers la zone mémoire destination (`dst`).
 *
 * @note Cette fonction gère correctement les chevauchements de mémoire,
 * contrairement à `ft_memcpy`.Le comportement de `ft_memmove` est défini
 * même si les zones source et destination se chevauchent.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cpy_dest;
	const char		*cpy_src;
	size_t			i;

	if (n <= 0 || (!dest && !src))
		return (dest);
	cpy_dest = dest;
	cpy_src = src;
	i = 0;
	if (dest < src)
	{
		ft_memcpy(cpy_dest, cpy_src, n);
	}
	else
	{
		i = n;
		while (i--)
		{
			cpy_dest[i] = cpy_src[i];
		}
	}
	return (dest);
}
