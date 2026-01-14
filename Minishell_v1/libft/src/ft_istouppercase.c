/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istouppercase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:29:37 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 20:12:35 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Vérifie si un caractère est une lettre majuscule.
 *
 * La fonction `ft_istouppercase` vérifie si le caractère donné en argument `c`
 * correspond à une lettre majuscule dans le code ASCII (entre 'A' et 'Z').
 *
 * @param c Le caractère à vérifier, passé sous forme d'entier (comme spécifié 
 * 	par les standards C).
 *
 * @return 
 * - `1` si le caractère est une lettre majuscule (entre 'A' et 'Z'),
 * - `0` sinon.
 *
 * @note Cette fonction ne traite que les caractères dans le jeu ASCII.
 * 	Les lettres minuscules, les chiffres, les caractères spéciaux ou tout autre
 	caractère en dehors de 'A'-'Z' retourneront 0.
 */
int	ft_istouppercase(int c)
{
	return (c >= 'A' && c <= 'Z');
}
