/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_split_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 00:00:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/10/16 17:58:25 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	process_count_char(char *line, int *j, size_t *i, size_t *trigger)
{
	if (line[*j] != ' ' && *trigger == 0)
	{
		*trigger = 1;
		(*i)++;
	}
	else if (line[*j] == ' ')
		*trigger = 0;
	(*j)++;
}

char	**process_write_loop(char **ret, char *line, t_split_state *state,
		int *size_words)
{
	int	result;

	while (line[*state->cursor])
	{
		if (handle_quotes(line, size_words, state->cursor))
			continue ;
		if (is_metachar(line[*state->cursor]))
		{
			result = handle_metachar(line, ret, state);
			if (result == -1)
				return (ft_free_split(ret), NULL);
			continue ;
		}
		if (line[*state->cursor] == ' ' || line[*state->cursor] == '\0')
		{
			result = handle_space(line, ret, state);
			if (result == -1)
				return (ft_free_split(ret), NULL);
			continue ;
		}
		(*size_words)++;
		(*state->cursor)++;
	}
	return (ret);
}

char	**finalize_write(char **ret, char *line, int i, int params[2])
{
	int	result;

	result = copy_word(params[0], line, ret + i, params[1]);
	if (result == -1)
		return (ft_free_split(ret), NULL);
	if (result == 0)
		i++;
	ret[i] = NULL;
	return (ret);
}
