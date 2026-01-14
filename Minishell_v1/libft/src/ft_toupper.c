/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:58:39 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:04:27 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Convertit un caractère en majuscule.
 *
 * La fonction `ft_toupper` prend un caractère en entrée et retourne
 * sa version en majuscule si le caractère est une lettre minuscule (a-z).
 * Si le caractère est déjà en majuscule (A-Z) ou n'est pas une lettre,
 * la fonction retourne le caractère inchangé.
 *
 * @param c Le caractère à convertir.
 *
 * @return Le caractère converti en majuscule, ou le caractère inchangé
 * s'il est déjà en majuscule ou non alphabétique.
 *
 */
int	ft_toupper(int c)
{
	if (ft_islowercase(c))
		return (c - ('a' - 'A'));
	return (c);
}
