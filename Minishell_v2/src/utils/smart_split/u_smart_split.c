/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_smart_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:17:48 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:53:15 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	is_metachar(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	is_double_metachar(char *line, int j)
{
	return ((line[j] == '<' && line[j + 1] == '<') || (line[j] == '>'
			&& line[j + 1] == '>'));
}

void	count_metachar(char *line, int *j, size_t *i, size_t *trigger)
{
	if (*trigger == 1)
	{
		*trigger = 0;
		(*i)++;
	}
	(*i)++;
	if (is_double_metachar(line, *j))
		(*j)++;
	(*j)++;
	*trigger = 0;
}

int	copy_metachar(char *line, char **ret, int j)
{
	if (is_double_metachar(line, j))
	{
		*ret = ft_substr(line, j, 2);
		if (!*ret)
			return (-1);
		return (2);
	}
	*ret = ft_substr(line, j, 1);
	if (!*ret)
		return (-1);
	return (1);
}

int	copy_word(int size_words, char *line, char **ret, int j)
{
	if (size_words > 0)
	{
		*ret = ft_substr(line, j - size_words, size_words);
		if (!*ret)
			return (-1);
		return (0);
	}
	return (1);
}
