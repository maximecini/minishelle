/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:08:50 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/05 13:56:46 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	valide_base(char *base)
{
	long	i;
	long	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == 43 || base[i] == 45)
			return (0);
		if (base[i] <= 32)
			return (0);
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && j != i)
				return (0);
			j++;
		}
		i++;
	}
	if (i == 1)
		return (0);
	return (i);
}
