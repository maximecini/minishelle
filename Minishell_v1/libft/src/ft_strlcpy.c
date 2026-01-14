/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:09:29 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:04:15 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Copie une chaîne de caractères avec une longueur maximale.
 *
 * La fonction `ft_strlcpy` copie jusqu'à `size - 1` caractères de la
 * chaîne `src` dans la chaîne `dst`,tout en garantissant que la chaîne `dst`
 * est terminée par un caractère nul (`'\0'`). Si `size` est inférieur ou égal
 * à la longueur de `dst`, la chaîne `dst` sera coupée et un caractère nul
 * sera ajouté à la fin pour garantir la terminaison. La fonction retourne
 * la longueur totale de la chaîne source `src`, ce qui permet de savoir si
 * la copie a été tronquée.
 *
 * @param dst La chaîne de destination où copier les caractères de `src`.
 * @param src La chaîne source à copier dans `dst`.
 * @param size La taille totale disponible pour `dst`
 * 	(y compris le caractère nul de fin).
 *
 * @return La longueur totale de la chaîne source `src`, c'est-à-dire la
 * longueur nécessaire pour copier toute la chaîne, sans tenir compte de
 * la taille de `dst`.
 *
 * @note Si `size` est inférieur à la longueur de `src`, la chaîne `dst`
 * sera tronquée et la fonction retournera la longueur totale de `src`, ce
 * qui permet de savoir si la copie a été tronquée.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	size_str;

	size_str = ft_strlen(src);
	if (size == 0)
		return (size_str);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (size_str);
}
