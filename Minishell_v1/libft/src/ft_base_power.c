/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_power.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:38:03 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 18:47:18 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
 * @brief Calcule la taille nécessaire pour représenter un entier
 * 	dans une base donnée.
 *
 * La fonction `ft_base_power` prend un entier `s` et une base `size_base`
 * et calcule la taille (en termes de puissance de la base) nécessaire
 * pour représenter le nombre `s` dans cette base. La fonction continue
 * de diviser `s` par la base jusqu'à ce que `s` soit inférieur ou égal
 * à la base, et renvoie la "taille" correspondante sous la forme d'une
 * puissance de la base.
 *
 * @param s L'entier à analyser. Ce nombre est divisé successivement
 * 	par `size_base` jusqu'à ce que `s` soit inférieur ou égal à `size_base`.
 * @param size_base La base dans laquelle l'entier `s` doit être représenté.
 * 	Cela doit être un entier supérieur à 1.
 *
 * @return La taille nécessaire pour représenter `s` dans la base `size_base`.
 * 	Cette taille est calculée comme étant la plus petite
 *  puissance de `size_base` telle que `s` puisse être représenté
 *  sans dépasser cette valeur.
 *
 */
size_t	ft_base_power(long long s, int size_base)
{
	long long	size;

	if (s < 0)
		s *= -1;
	size = 1;
	while (s > size_base)
	{
		s /= size_base;
		size *= size_base;
	}
	return (size);
}
