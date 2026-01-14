/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:07:42 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 15:15:31 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/function.h"

static int	check_numeric_overflow(long result, int digit, int sign)
{
	if (sign == 1 && (result > LONG_MAX / 10 || (result == LONG_MAX / 10
				&& digit > LONG_MAX % 10)))
		return (0);
	if (sign == -1 && (result > -(LONG_MIN / 10) || (result == -(LONG_MIN / 10)
				&& digit > -(LONG_MIN % 10))))
		return (0);
	return (1);
}

int	is_numeric_body_valid(char *arg, int sign)
{
	int		i;
	long	result;
	int		digit;

	i = 0;
	result = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		digit = arg[i] - '0';
		if (!check_numeric_overflow(result, digit, sign))
			return (0);
		result = result * 10 + digit;
		i++;
	}
	return (1);
}
