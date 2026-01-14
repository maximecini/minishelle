/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:43:24 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:51:15 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	is_quote(char c)
{
	return (c == SIMPLE_QUOTES || c == DBL_QUOTES);
}

int	check_quotes(char *line)
{
	int		i;
	char	quot;

	quot = *line;
	i = 1;
	while (line[i])
	{
		if (line[i] == quot)
			return (i);
		i++;
	}
	return (0);
}

int	size_quotes(char *line, int j)
{
	int	len_quotes;

	len_quotes = check_quotes(line + j);
	if (len_quotes > 0)
		return (len_quotes);
	return (0);
}

void	update_quote_state(char c, int *in_single, int *in_double)
{
	if (c == SIMPLE_QUOTES && !(*in_double))
		*in_single = !(*in_single);
	else if (c == DBL_QUOTES && !(*in_single))
		*in_double = !(*in_double);
}
