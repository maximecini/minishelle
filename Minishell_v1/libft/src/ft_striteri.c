/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:23:06 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 20:55:44 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Applique une fonction à chaque caractère d'une chaîne, avec son 
 * 	index.
 *
 * La fonction `ft_striteri` parcourt la chaîne de caractères `s` et applique 
 * la fonction `f` à chaque caractère de la chaîne, en passant l'index du 
 * caractère dans la chaîne comme argument à la fonction `f`. 
 * Cela permet de modifier chaque caractère de la chaîne en fonction de 
 * sa position dans la chaîne.
 *
 * @param s La chaîne de caractères à parcourir.
 * @param f La fonction à appliquer à chaque caractère, prenant deux arguments: 
 * 	l'index et le caractère.
 * 
 * @return Aucune valeur de retour. La fonction modifie directement 
 * 	la chaîne `s`.
 * 
 * @note Cette fonction est particulièrement utile lorsque vous avez besoin de
 *  modifier une chaîne en fonction des positions de ses caractères, comme 
 * 	dans le cas d'une transformation basée sur l'index de chaque caractère.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
