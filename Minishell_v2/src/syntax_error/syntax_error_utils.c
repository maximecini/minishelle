/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:00:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:03:45 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	syntax_error_msg(char *token)
{
	ft_putstr_fd(" syntax error near unexpected token `", 2);
	ft_putstr_fd(token, 2);
	ft_putstr_fd("'\n", 2);
	return (0);
}

int	is_inside_quotes(char *line, int pos)
{
	int	i;
	int	in_single;
	int	in_double;

	i = 0;
	in_single = 0;
	in_double = 0;
	while (i < pos && line[i])
	{
		update_quote_state(line[i], &in_single, &in_double);
		i++;
	}
	return (in_single || in_double);
}
