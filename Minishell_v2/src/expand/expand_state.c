/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:05:12 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 15:53:24 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

t_expand_state	*init_expand_state(int respect_single_quotes)
{
	t_expand_state	*state;

	state = malloc(sizeof(t_expand_state));
	if (!state)
		return (NULL);
	state->capacity = 256;
	state->result = malloc(state->capacity);
	if (!state->result)
	{
		free(state);
		return (NULL);
	}
	state->len = 0;
	state->in_single_quote = 0;
	state->in_double_quote = 0;
	state->respect_single_quotes = respect_single_quotes;
	state->result[0] = '\0';
	return (state);
}

int	append_char(t_expand_state *state, char c)
{
	char	*new_result;
	int		new_capacity;

	if (state->len + 1 >= state->capacity)
	{
		new_capacity = state->capacity * 2;
		new_result = malloc(new_capacity);
		if (!new_result)
			return (0);
		ft_memcpy(new_result, state->result, state->len);
		free(state->result);
		state->result = new_result;
		state->capacity = new_capacity;
	}
	state->result[state->len++] = c;
	state->result[state->len] = '\0';
	return (1);
}

int	append_string(t_expand_state *state, char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (!append_char(state, str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*finalize_expand_state(t_expand_state *state)
{
	char	*result;

	if (!state)
		return (NULL);
	result = state->result;
	free(state);
	return (result);
}
