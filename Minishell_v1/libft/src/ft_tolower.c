/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:41:17 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/11 15:12:02 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Convertit un caractère en minuscule.
 *
 * La fonction `ft_tolower` prend un caractère en entrée et retourne sa
 * version en minuscule si le caractère est une lettre majuscule (A-Z).
 * Si le caractère est déjà en minuscule (a-z) ou n'est pas une lettre,
 * la fonction retourne le caractère inchangé.
 *
 * @param c Le caractère à convertir.
 *
 * @return Le caractère converti en minuscule, ou le caractère inchangé
 * s'il est déjà en minuscule ou non alphabétique.
 */
int	ft_tolower(int c)
{
	if (ft_istouppercase(c))
		return (c + ('a' - 'A'));
	return (c);
}
