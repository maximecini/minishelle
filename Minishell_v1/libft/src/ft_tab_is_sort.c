/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_is_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:00:36 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/11 17:05:24 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Vérifie si un tableau d'entiers est trié en ordre croissant.
 *
 * Cette fonction parcourt le tableau et vérifie si chaque élément est inférieur
 * ou égal au suivant. Si une inversion est détectée, elle retourne `1`,
 * sinon elle retourne `0`.
 *
 * @param tab Tableau d'entiers à vérifier.
 * @param size Taille du tableau.
 *
 * @return 0 si le tableau est trié en ordre croissant, 1 sinon.
 */
int	ft_tab_is_sort(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		if (tab[i] > tab[j])
			return (1);
		i++;
	}
	return (0);
}
