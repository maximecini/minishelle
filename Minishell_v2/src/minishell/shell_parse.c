/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:00:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 14:53:40 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static int	create_all_list(t_prompt_state *state)
{
	if (!create_list_token(state->lst_token, *state->tab))
		return (0);
	if (!create_lst_cmd(*state->lst_token, state->lst_cmd))
		return (0);
	if (!fill_node(state->lst_cmd, state->lst_token))
		return (-1);
	return (1);
}

int	process_input_line(t_prompt_state *state)
{
	int	result;

	if (!get_syntax_error(state->line))
		return (-1);
	*state->tab = smart_split(state->line);
	if (!*state->tab)
		return (0);
	if (!get_quote_error(state->line))
		return (-1);
	if (ft_strlen(state->line))
		add_history(state->line);
	result = create_all_list(state);
	if (result == 1 && *state->lst_token)
	{
		ft_lstclear(state->lst_token, free_node_token_content);
		*state->lst_token = NULL;
	}
	return (result);
}

int	handle_parse_result(t_prompt_state *state)
{
	if (state->result == -1)
	{
		state->last_exit_code = 2;
		free_all_with_cmd(state->lst_token, state->lst_cmd, *state->tab,
			state->line);
		*state->tab = NULL;
		state->line = NULL;
		return (1);
	}
	if (state->result == 0)
	{
		free_all_with_cmd(state->lst_token, state->lst_cmd, *state->tab,
			state->line);
		*state->tab = NULL;
		state->line = NULL;
		return (1);
	}
	return (0);
}
