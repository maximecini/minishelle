/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:11:44 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:04:40 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Copie une zone mémoire dans une autre.
 *
 * La fonction `ft_memcpy` copie `n` octets de la zone mémoire source (`src`)
 * vers la zone mémoire destination (`dst`). La copie est effectuée octet
 * par octet. Si les zones mémoire se chevauchent, le comportement de
 * `ft_memcpy` est indéfini. Pour gérer les chevauchements,
 * il est recommandé d'utiliser `ft_memmove`.
 *
 * @param dst Pointeur vers la zone mémoire de destination où les données
 * 	doivent être copiées.
 * @param src Pointeur vers la zone mémoire source à copier.
 * @param n Le nombre d'octets à copier.
 *
 * @return Un pointeur vers la zone mémoire destination (`dst`).
 *
 * @note Le comportement de cette fonction est indéfini si les zones mémoire
 * 	source et destination se chevauchent. Dans ce cas, il est recommandé
 * 	d'utiliser `ft_memmove` à la place.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*cpy_src;
	unsigned char		*cpy_dest;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (0);
	cpy_src = src;
	cpy_dest = dest;
	i = 0;
	while (i < n)
	{
		cpy_dest[i] = cpy_src[i];
		i++;
	}
	return (dest);
}
