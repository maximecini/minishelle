/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:00:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 22:49:02 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	handle_expand(t_prompt_state *state)
{
	if (expand(state->lst_cmd, state->lst_env) == -1)
	{
		state->last_exit_code = 1;
		cleanup_iteration(state);
		return (1);
	}
	return (0);
}

static int	handle_line_eof(t_prompt_state *state)
{
	cleanup_prompt_state(state->lst_token, state->lst_cmd, state->tab);
	if_print_exit();
	return (1);
}

static void	init_cleanup_ctx(t_cleanup_ctx *ctx, t_prompt_state *state)
{
	ctx->lst_token = state->lst_token;
	ctx->lst_cmd = state->lst_cmd;
	ctx->tab = state->tab;
	ctx->lst_env = state->lst_env;
	ctx->original_term = &state->original_term;
	ctx->last_exit_code = state->last_exit_code;
}

static int	loop_iteration(t_prompt_state *state)
{
	t_cleanup_ctx	ctx;

	if (handle_parse_result(state))
		return (1);
	init_cleanup_ctx(&ctx, state);
	if (handle_heredoc(state, &ctx))
		return (1);
	update_exit_code_in_env(state->lst_env, state->last_exit_code);
	if (handle_expand(state))
		return (1);
	trim_commands(state->lst_cmd);
	if (run_execute(state, &ctx))
		return (state->should_exit == 0);
	state->last_exit_code = state->result;
	return (1);
}

int	process_shell_loop(t_list **lst_token, t_list **lst_cmd, char ***tab,
		t_list **lst_env)
{
	t_prompt_state	state;
	int				should_continue;

	state.lst_token = lst_token;
	state.lst_cmd = lst_cmd;
	state.tab = tab;
	state.lst_env = *lst_env;
	state.last_exit_code = 0;
	while (1)
	{
		tcgetattr(STDIN_FILENO, &state.original_term);
		state.line = readline("Minishell$ ");
		if (!state.line)
		{
			*lst_env = state.lst_env;
			return (handle_line_eof(&state));
		}
		state.should_exit = 0;
		state.result = process_input_line(&state);
		should_continue = loop_iteration(&state);
		*lst_env = state.lst_env;
		if (!should_continue)
			return (cleanup_prompt_state(lst_token, lst_cmd, tab), (0));
	}
	return (1);
}
