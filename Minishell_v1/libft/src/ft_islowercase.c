/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islowercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:37:10 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 20:11:03 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Vérifie si un caractère est une lettre minuscule.
 *
 * La fonction `ft_islowercase` vérifie si le caractère donné en argument `c`
 * correspond à une lettre minuscule dans le code ASCII (entre 'a' et 'z').
 *
 * @param c Le caractère à vérifier, passé sous forme d'entier 
 * 	(comme spécifié par les standards C).
 *
 * @return 
 * - `1` si le caractère est une lettre minuscule (entre 'a' et 'z'),
 * - `0` sinon.
 *
 * @note Cette fonction ne traite que les caractères dans le jeu ASCII.
 *	Les lettres majuscules, les chiffres, les caractères 
 * 	spéciaux ou tout autre caractère en dehors de 'a'-'z' retourneront 0.
 */
int	ft_islowercase(int c)
{
	return (c >= 'a' && c <= 'z');
}
