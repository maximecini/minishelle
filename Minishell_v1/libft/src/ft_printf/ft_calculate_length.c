/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_length.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:50:24 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/01 11:15:37 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_string(void *str, void (*f)(char *, int))
{
	if (!((char *)str))
		return (ft_putstr_fd("(null)", 1), 6);
	f((char *)str, 1);
	return (ft_strlen((char *)str));
}

int	ft_display_base(size_t number, char *str, void f(size_t, char *, int *))
{
	int	i;

	i = 0;
	if (!number)
		return (ft_putstr_fd("(nil)", 1), 5);
	if (number == 0)
		return (ft_putstr_fd("(null)", 1), 6);
	f(number, (char *)str, &i);
	return (i);
}

int	ft_display_uint(int number, void f(int, int *))
{
	int	i;

	i = 0;
	f(number, &i);
	return (i);
}
