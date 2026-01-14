/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u2_smart_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:13:08 by simon             #+#    #+#             */
/*   Updated: 2025/10/16 17:52:18 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	handle_word_before_meta(int size_words, char *line, char **ret,
		t_split_state *state)
{
	int	cpy;
	int	cursor;

	if (size_words > 0)
	{
		cursor = *state->cursor;
		cpy = copy_word(size_words, line, ret + *state->index, cursor);
		if (cpy < 1 && cpy == -1)
			return (-1);
		(*state->index)++;
	}
	return (0);
}

int	handle_metachar(char *line, char **ret, t_split_state *state)
{
	int	metachar_size;

	if (handle_word_before_meta(*state->word_size, line, ret, state) == -1)
		return (-1);
	metachar_size = copy_metachar(line, ret + *state->index, *state->cursor);
	if (metachar_size == -1)
		return (-1);
	(*state->index)++;
	*state->cursor += metachar_size;
	*state->word_size = 0;
	return (1);
}

int	handle_space(char *line, char **ret, t_split_state *state)
{
	int	cpy;

	cpy = copy_word(*state->word_size, line, ret + *state->index,
			*state->cursor);
	if (cpy == -1)
		return (-1);
	if (cpy == 0)
		(*state->index)++;
	while (line[*state->cursor] == ' ')
		(*state->cursor)++;
	*state->word_size = 0;
	return (1);
}

int	handle_quotes(char *line, int *size_words, int *j)
{
	int	quote_len;

	if (is_quote(line[*j]))
	{
		quote_len = size_quotes(line, *j);
		if (quote_len > 0)
		{
			*size_words += quote_len + 1;
			*j += quote_len + 1;
			return (1);
		}
	}
	return (0);
}
