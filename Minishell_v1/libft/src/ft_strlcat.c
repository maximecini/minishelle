/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:17:48 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:04:15 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Concatène une chaîne de caractères à une autre avec une longueur
 * 	maximale.
 *
 * La fonction `ft_strlcat` concatène jusqu'à `size - strlen(dst) - 1`
 * caractères de la chaîne `src` à la chaîne `dst`, tout en garantissant que
 * la chaîne résultante est bien terminée par un caractère nul (`'\0'`).
 * Le paramètre `size` est la taille totale de la zone mémoire allouée
 * pour `dst`. La fonction veille à ne pas dépasser cette taille, pour éviter
 * les dépassements de mémoire. Elle retourne la longueur totale de la chaîne
 * concaténée si elle avait suffisamment de place, ou la taille totale
 * nécessaire pour concaténer si la taille de `dst` était trop petite.
 *
 * @param dst La chaîne de destination à laquelle ajouter les caractères
 * 	de `src`.
 * @param src La chaîne source à ajouter à `dst`.
 * @param size La taille totale disponible pour `dst`
 * 	(y compris le caractère nul de fin).
 *
 * @return La longueur totale de la chaîne résultante si `size`
 * est suffisante,ou la longueur nécessaire pour concaténer les deux chaînes
 * si `size` est trop petite.
 *
 * @note Si `size` est inférieur à la longueur de `dst`, la chaîne `dst`
 * ne sera pas modifiée,et la fonction retournera la longueur nécessaire
 * pour contenir la chaîne concaténée.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;
	size_t	j;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	i = 0;
	j = dest_size;
	if (size <= dest_size || size == 0)
		return (src_size + size);
	while (src[i] && i < size - dest_size - 1)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest_size + src_size);
}
