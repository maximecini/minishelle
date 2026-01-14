/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:45:47 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:05:24 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
 * @brief Calcule le nombre de chiffres dans un entier.
 *
 * La fonction `ft_digitlen` prend un entier `n` et retourne le nombre
 * de chiffres qu'il contient. Elle gère également les nombres négatifs
 * en les convertissant en valeurs absolues, mais ne compte pas le signe négatif
 * comme un chiffre.
 *
 * @param n L'entier dont on veut connaître le nombre de chiffres.
 *
 * @return Le nombre de chiffres dans l'entier, y compris le signe pour
 * 	les nombres négatifs.
 *
 * @note Si le nombre est négatif, le signe '-' est pris en compte
 * 	dans le calcul.
 *
 */
size_t	ft_digitlen(long long n, int base)
{
	long long	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n = n / base;
		i++;
	}
	return (i);
}
