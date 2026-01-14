/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:55:59 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/23 16:36:31 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_is_valide(char str, char *base)
{
	int	j;

	j = 0;
	while (base[j])
	{
		if (base[j] == str)
		{
			return (j);
		}
		j++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	indice;

	if (!valide_base(base))
		return (0);
	i = 0;
	result = 0;
	indice = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			indice = -indice;
		i++;
	}
	while (str[i] && ft_is_valide(str[i], base) != -1)
	{
		result *= ft_strlen(base);
		result += ft_is_valide(str[i], base);
		i++;
	}
	return (result * indice);
}
