/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:18:34 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:53:29 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	is_redirection(int c)
{
	return (c == REDIR_IN || c == REDIR_OUT || c == REDIR_APPEND
		|| c == HEREDOC);
}

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}
