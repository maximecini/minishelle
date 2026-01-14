/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:23:03 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:05:27 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	*ft_intdup(int *arryint, int size)
{
	int	*s;
	int	i;

	s = (int *)malloc(size * sizeof(int));
	if (!s)
		return (0);
	i = 0;
	while (i < size)
	{
		s[i] = arryint[i];
		i++;
	}
	return (s);
}
