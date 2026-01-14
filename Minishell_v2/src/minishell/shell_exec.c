/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:00:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 22:52:29 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	update_exit_code_in_env(t_list *lst_env, int exit_code)
{
	char	*value;

	value = ft_itoa(exit_code);
	if (!value)
		return ;
	if (!get_lst_key(&lst_env, "?"))
		add_back_nodes_env(&lst_env, "?=0", 1);
	update_nodes_env(lst_env, "?", value, "=");
	free(value);
}

void	cleanup_iteration(t_prompt_state *state)
{
	free_all_with_cmd(state->lst_token, state->lst_cmd, *state->tab,
		state->line);
	*state->tab = NULL;
	state->line = NULL;
}

static void	exit_program(t_prompt_state *state, int exit_code)
{
	cleanup_iteration(state);
	rl_clear_history();
	ft_lstclear(&state->lst_env, free_node_env_content);
	exit(exit_code);
}

int	handle_heredoc(t_prompt_state *state, t_cleanup_ctx *ctx)
{
	if (process_heredoc(*state->lst_cmd, state->lst_env, ctx) == -1)
	{
		g_last_status = 130;
		cleanup_iteration(state);
		return (1);
	}
	return (0);
}

int	run_execute(t_prompt_state *state, t_cleanup_ctx *ctx)
{
	if (*state->lst_cmd)
		state->result = execute_command(*state->lst_cmd, &state->lst_env,
				*state->tab, ctx);
	else
		state->result = state->last_exit_code;
	if (state->result == -3)
		state->result = state->last_exit_code;
	if (state->result <= -2000)
		exit_program(state, -(state->result + 2000));
	if (state->result == -42)
	{
		cleanup_iteration(state);
		state->should_exit = 1;
		return (1);
	}
	cleanup_iteration(state);
	return (0);
}
