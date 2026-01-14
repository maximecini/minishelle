/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:27:23 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/03/17 11:15:31 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_printf(int nb, int *i)
{
	long	number;

	number = nb;
	if (number < 0)
	{
		*i += 1;
		number *= -1;
		write(1, "-", 1);
	}
	if (number > 9)
	{
		ft_putnbr_printf(number / 10, i);
	}
	*i += 1;
	ft_putchar_fd(ft_todigits(number % 10), 1);
}
