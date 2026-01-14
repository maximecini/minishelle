/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:41:13 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/05 15:15:19 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../../include/libft.h"
# include <bsd/string.h>
# include <ctype.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

/*******************************/
/*         DEF FORMAT          */
/*******************************/
# define CHAR 'c'
# define STRING 's'
# define DECIMAL 'd'
# define INTEGER 'i'
# define U_INTEGER 'u'
# define HEX_LOWER_ 'x'
# define HEX_UPP 'X'
# define POINTER 'p'
# define PERCENT '%'
/*******************************/
/*         base        */
/*******************************/
# define BASE_HEX "0123456789abcdef"
# define BASE_HEX_UPP "0123456789ABCDEF"
# define BASE_DEC "0123456789"

int				ft_printf(const char *format, ...);
void			ft_putnbr_printf(int nb, int *i);
int				ft_display_string(void *str, void (*f)(char *, int));
void			ft_putnbr_base_printf(size_t number, char *base, int *i);
int				ft_display_uint(int number, void (*f)(int, int *i));

#endif
