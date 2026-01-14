/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:26:58 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:04:45 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Trie un tableau d'entiers dans l'ordre décroissant.
 *
 * Cette fonction implémente un tri par sélection en comparant chaque élément
 * du tableau avec les suivants et en échangeant les valeurs si nécessaire.
 *
 * @param tab Pointeur vers le tableau d'entiers à trier.
 * @param size Nombre d'éléments dans le tableau.
 */

/* Déclaration des variables :
   - i : indice de l'élément actuellement en cours de tri.
   - j : indice utilisé pour parcourir les éléments suivants.
   - current : variable temporaire pour l'échange des valeurs. */

/* Parcours du tableau élément par élément */
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	current;

	current = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] < tab[j])
			{
				current = tab[i];
				tab[i] = tab[j];
				tab[j] = current;
			}
			j++;
		}
		i++;
	}
}
