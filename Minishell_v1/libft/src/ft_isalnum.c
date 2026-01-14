/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:06:57 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:05:28 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Vérifie si un caractère est alphanumérique.
 *
 * La fonction `isalnum` prend un caractère en entrée et vérifie
 * s'il est une lettre(majuscule ou minuscule) ou un chiffre. Elle retourne
 * un résultat booléen :
 * - Retourne 1 si le caractère est alphanumérique (lettre ou chiffre).
 * - Retourne 0 si le caractère n'est ni une lettre, ni un chiffre.
 *
 * @param c Le caractère à tester.
 *
 * @return 1 si le caractère est alphanumérique, 0 sinon.
 *
 * @note Cette fonction est équivalente à `isalpha(c) || isdigit(c)`.
 *       Le caractère est testé en fonction de la table ASCII.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
