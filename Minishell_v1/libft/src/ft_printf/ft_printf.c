/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:16:55 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/23 16:36:53 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_adress(long number, char *base, int point)
{
	int	r;

	r = 0;
	if (!point && number == 0)
		return (ft_putstr_fd("0", 1), 1);
	if (!number)
		return (ft_putstr_fd("(nil)", 1), 5);
	if (number == 0)
		return (ft_putstr_fd("(null)", 1), 6);
	if (point)
	{
		ft_putstr_fd("0x", 1);
		r += 2;
	}
	r += ft_display_base(number, base, ft_putnbr_base_printf);
	return (r);
}

static int	ft_call_function_type(const char format, va_list args)
{
	if (format == CHAR)
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	else if (format == STRING)
		return (ft_display_string(va_arg(args, char *), ft_putstr_fd));
	else if (format == POINTER)
		return (print_adress(va_arg(args, unsigned long long), BASE_HEX, 1));
	else if (format == DECIMAL || format == INTEGER)
		return (ft_display_uint(va_arg(args, int), ft_putnbr_printf));
	else if (format == U_INTEGER)
		return (print_adress(va_arg(args, unsigned int), BASE_DEC, 0));
	else if (format == HEX_LOWER_)
		return (print_adress(va_arg(args, unsigned int), BASE_HEX, 0));
	else if (format == HEX_UPP)
		return (print_adress(va_arg(args, unsigned int), BASE_HEX_UPP, 0));
	else if (format == PERCENT)
		return (ft_putchar_fd('%', 1), 1);
	return (-1);
}

static int	ft_show_arguments(const char *format, va_list args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*format)
	{
		if (*format == '%')
		{
			j = ft_call_function_type(*(format + 1), args);
			format++;
			i = i + j - 1;
		}
		else
			ft_putchar_fd(*format, 1);
		i++;
		format++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	if (!format)
		return (-1);
	i = 0;
	va_start(args, format);
	i = ft_show_arguments(format, args);
	va_end(args);
	return (i);
}

void	ft_putnbr_base_printf(size_t number, char *base, int *i)
{
	unsigned int	lengt_base;

	lengt_base = valide_base(base);
	if (!lengt_base)
		return ;
	if (number >= lengt_base)
	{
		ft_putnbr_base_printf(number / lengt_base, base, i);
	}
	*i += 1;
	ft_putchar_fd(base[number % lengt_base], 1);
}
