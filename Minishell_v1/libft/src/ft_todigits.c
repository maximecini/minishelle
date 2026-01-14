/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_todigits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:11:03 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:04:26 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Convertit un chiffre en caractère.
 *
 * Cette fonction prend un entier `n`, vérifie s'il s'agit d'un chiffre
 * (0 à 9) et le convertit en son équivalent caractère ASCII.
 *
 * @param n Un entier à convertir.
 *
 * @return Le caractère ASCII du chiffre si `n` est valide, 0 sinon.
 */
char	ft_todigits(int n)
{
	if (ft_int_isdigit(n))
		return (n + '0');
	return (0);
}
