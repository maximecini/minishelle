/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:00:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:25:36 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

/*
** Supprime les espaces de début et fin d'une chaîne
*/
void	trim_whitespace(char *str, int *start, int *end)
{
	*start = 0;
	while (str[*start] && ft_is_whitespace(str[*start]))
		(*start)++;
	*end = ft_strlen(str) - 1;
	while (*end > *start && ft_is_whitespace(str[*end]))
		(*end)--;
}

/*
** Ajoute un caractère au résultat
*/
void	append_trim_char(t_trim_state *state, char c)
{
	state->result[state->len++] = c;
	state->result[state->len] = '\0';
}

/*
** Traite un caractère pendant le quote removal
** Retourne 1 si le caractère doit être ajouté, 0 sinon
*/
int	process_trim_char(t_trim_state *state, char c)
{
	if (c == '\'' && !state->in_double_quote)
	{
		state->in_single_quote = !state->in_single_quote;
		return (0);
	}
	else if (c == '"' && !state->in_single_quote)
	{
		state->in_double_quote = !state->in_double_quote;
		return (0);
	}
	return (1);
}

/*
** Initialise l'état de trim
*/
t_trim_state	*init_trim_state(int capacity)
{
	t_trim_state	*state;

	state = malloc(sizeof(t_trim_state));
	if (!state)
		return (NULL);
	state->result = malloc(capacity);
	if (!state->result)
	{
		free(state);
		return (NULL);
	}
	state->len = 0;
	state->in_single_quote = 0;
	state->in_double_quote = 0;
	state->result[0] = '\0';
	return (state);
}
