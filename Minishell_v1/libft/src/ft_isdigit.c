/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:41:21 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 20:10:14 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Vérifie si un caractère est un chiffre.
 *
 * La fonction `isdigit` prend un caractère en entrée et vérifie 
 * s'il est un chiffre (c'est-à-dire un caractère compris entre '0' et '9'). 
 * Elle retourne un résultat booléen :
 * - Retourne 1 si le caractère est un chiffre.
 * - Retourne 0 si le caractère n'est pas un chiffre.
 * 
 * @param c Le caractère à tester.
 * 
 * @return 1 si le caractère est un chiffre (0-9), 0 sinon.
 * 
 * @note Cette fonction fonctionne sur la base de la table ASCII,
 * où les chiffres sont compris entre '0' (code 48) et '9' (code 57).
 */
int	ft_isdigit(int nb)
{
	return (nb >= '0' && nb <= '9');
}
