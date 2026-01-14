/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:48:44 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 20:09:46 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Vérifie si un caractère appartient à la table ASCII.
 *
 * La fonction `isascii` prend un caractère en entrée et vérifie 
 * s'il appartient à la table ASCII. Les caractères ASCII vont de 0 à 127, 
 * incluant des lettres,des chiffres, des symboles de ponctuation 
 * et des caractères de contrôle.
 * 
 * @param c Le caractère à tester.
 * 
 * @return 1 si le caractère appartient à la table ASCII (valeurs de 0 à 127), 
 * 	0 sinon.
 * 
 * @note Cette fonction fonctionne uniquement avec des caractères 
 * 	ayant une valeur comprise entre 0 et 127 inclus. Les valeurs au-delà 
 * 	de cette plage ne sont pas considérées comme ASCII.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
