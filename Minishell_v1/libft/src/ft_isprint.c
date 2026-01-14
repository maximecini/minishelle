/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:01:26 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 20:11:38 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Vérifie si un caractère est imprimable.
 *
 * La fonction `isprint` prend un caractère en entrée et vérifie 
 * s'il est imprimable,c'est-à-dire si c'est un caractère visible, 
 * tel qu'une lettre, un chiffre, un symbole de ponctuation, ou même un espace.
 * Les caractères non imprimables comme les caractèresde contrôle (ASCII 0-31) 
 * ne sont pas considérés comme imprimables.
 * 
 * @param c Le caractère à tester.
 * 
 * @return 1 si le caractère est imprimable, 0 sinon.
 * 
 * @note Les caractères imprimables sont ceux dont le code ASCII 
 * 	est compris entre 32
 *       (espace) et 126 (tilde '~').
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c < 127);
}
