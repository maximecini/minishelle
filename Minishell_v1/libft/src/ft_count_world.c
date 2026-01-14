/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:18:14 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/23 14:55:54 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_count_word(char const *str, char ch)
{
	size_t	i;
	size_t	trigger;

	if (!str)
		return (0);
	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != ch && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == ch)
			trigger = 0;
		str++;
	}
	return (i);
}
