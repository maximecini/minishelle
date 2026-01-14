/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:05:12 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 16:03:10 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static int	handle_quote_toggle(t_expand_state *state, char **str, char c)
{
	if (c == '\'' && state->respect_single_quotes && !state->in_double_quote)
	{
		state->in_single_quote = !state->in_single_quote;
		append_char(state, c);
		(*str)++;
		return (1);
	}
	if (c == '"' && !state->in_single_quote)
	{
		state->in_double_quote = !state->in_double_quote;
		append_char(state, c);
		(*str)++;
		return (1);
	}
	return (0);
}

static int	handle_variable_expansion(t_expand_state *state, char **str,
		t_list *lst_env)
{
	if (**str == '$'
		&& (!state->respect_single_quotes || !state->in_single_quote))
	{
		(*str)++;
		*str += expand_variable(state, *str, lst_env);
		return (1);
	}
	return (0);
}

void	process_char(t_expand_state *state, char **str, t_list *lst_env)
{
	char	c;

	c = **str;
	if (handle_quote_toggle(state, str, c))
		return ;
	if (handle_variable_expansion(state, str, lst_env))
		return ;
	append_char(state, c);
	(*str)++;
}
