/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:36:12 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:05:19 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Met une zone mémoire à zéro.
 *
 * La fonction `bzero` prend un pointeur vers une zone mémoire et définit tous
 * les octets de cette zone à zéro. Cette fonction est souvent utilisée pour
 * initialiser des blocs de mémoire avant de les utiliser dans un programme.
 *
 * @param s Pointeur vers la zone mémoire à mettre à zéro.
 * @param len La taille de la zone mémoire à traiter, en octets.
 *
 * @note Cette fonction est obsolète et est remplacée par `memset(s, 0, len)`
 * dans lesimplémentations modernes, mais elle peut encore être utilisée
 * dans certains cas de compatibilité avec des systèmes plus anciens.
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}
