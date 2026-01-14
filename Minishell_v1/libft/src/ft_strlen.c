/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 05:10:50 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/26 21:09:39 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Calcule la longueur d'une chaîne de caractères.
 *
 * La fonction `ft_strlen` parcourt la chaîne de caractères `s` et retourne
 * le nombre de caractères avant le caractère nul (`'\0'`), qui marque
 * la fin de la chaîne. La fonction ne compte pas le caractère nul lui-même,
 * elle retourne uniquement la longueur de la partie visible de la chaîne.
 *
 * @param s La chaîne de caractères dont la longueur doit être calculée.
 *
 * @return La longueur de la chaîne de caractères.
 */
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
