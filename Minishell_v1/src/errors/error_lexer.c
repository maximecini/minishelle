/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 08:30:41 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/08/01 11:52:27 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Parcourt la chaîne `input` pour détecter une erreur de syntaxe dans
** les tokens. Renvoie 1 si une erreur est détectée, 0 sinon.
*/
int	has_syntax_error(char *input)
{
	t_syntax_state	state;

	init_syntax_state(&state);
	while (input[state.index])
	{
		if (should_skip_char(input, &state))
		{
			state.index++;
			continue ;
		}
		if (process_token(input, &state))
			return (1);
	}
	return (0);
}

int	ft_check_err(char *line)
{
	int	check_err;
	int	i;
	int	in_single_quote;
	int	in_double_quote;

	check_err = 0;
	i = 0;
	in_single_quote = 0;
	in_double_quote = 0;
	while (line[i])
	{
		update_quote_state(line[i], &in_single_quote, &in_double_quote);
		if (in_single_quote || in_double_quote)
		{
			i++;
			continue ;
		}
		if (line[i] == '&')
			return (2);
		if (line[i] == '|' && line[i + 1] == '|')
			return (1);
		i++;
	}
	return (0);
}

void	ft_log(char *line)
{
	if (ft_check_err(line) == 1)
		ft_putendl_fd("minishell: syntax error near unexpected token `|'", 2);
	if (ft_check_err(line) == 2)
		ft_putendl_fd("minishell: syntax error near unexpected token `&'", 2);
}

int	print_syntax_error(char *token)
{
	ft_putstr_fd("Minishell: syntax error near unexpected token `", 2);
	if (token)
		ft_putstr_fd(token, 2);
	else
		ft_putstr_fd("NULL", 2);
	ft_putendl_fd("`", 2);
	return (1);
}

int	print_syntax_error_export(char *token, int error)
{
	if (error == EXPORT_NO_VALID)
	{
		ft_putstr_fd("export:", 2);
		ft_putstr_fd(token, 2);
		ft_putstr_fd(": not a valid identifier\n", 2);
	}
	else
		ft_putstr_fd("NULL", 2);
	return (1);
}
