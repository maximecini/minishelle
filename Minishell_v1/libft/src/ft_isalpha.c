/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:41:16 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 20:08:22 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Vérifie si un caractère est une lettre alphabétique.
 *
 * La fonction `isalpha` prend un caractère en entrée et vérifie 
 * s'il est une lettre de l'alphabet, qu'elle soit en majuscule ou en minuscule.
 * Elle retourne un résultat booléen :
 * - Retourne 1 si le caractère est une lettre de l'alphabet (A-Z ou a-z).
 * - Retourne 0 si le caractère n'est pas une lettre.
 * 
 * @param c Le caractère à tester.
 * 
 * @return 1 si le caractère est une lettre alphabétique, 0 sinon.
 * 
 * @note Cette fonction se base sur la table ASCII et fonctionne pour 
 * les caractères allant de `A` à `Z` (majuscule) et de `a` à `z` (minuscule).
 */
int	ft_isalpha(int letter)
{
	if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
	{
		return (letter);
	}
	return (0);
}
