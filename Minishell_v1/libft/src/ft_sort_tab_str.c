/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:05:54 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/26 21:17:28 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	**copy_or_return_if_small(char **dbtab, int nb)
{
	if (nb < 2)
		return (copy_string_array(dbtab, nb));
	return (copy_string_array(dbtab, nb));
}

static void	sort_string_array(char **tab, int nb)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (i < nb - 1)
	{
		j = i + 1;
		while (j < nb)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

char	**ft_sort_tab_str(char **dbtab)
{
	char	**tab;
	int		nb;

	if (!dbtab)
		return (NULL);
	nb = ft_array_len(dbtab);
	tab = copy_or_return_if_small(dbtab, nb);
	if (!tab || nb < 2)
		return (tab);
	sort_string_array(tab, nb);
	return (tab);
}
