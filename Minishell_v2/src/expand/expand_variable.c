/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:05:12 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 15:59:16 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static int	handle_literal_dollar(t_expand_state *state, char *str)
{
	if (!state->in_double_quote && (str[0] == '"' || str[0] == '\''))
		return (0);
	append_char(state, '$');
	return (0);
}

int	get_var_name_len(char *str)
{
	int	len;

	len = 0;
	if (str[0] == '?')
		return (1);
	if (ft_isdigit(str[0]))
		return (1);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	while (str[len] && (ft_isalnum(str[len]) || str[len] == '_'))
		len++;
	return (len);
}

int	expand_variable(t_expand_state *state, char *str, t_list *lst_env)
{
	int		var_len;
	char	*var_name;
	char	*var_value;

	var_len = get_var_name_len(str);
	if (var_len == 0)
		return (handle_literal_dollar(state, str));
	var_name = ft_substr(str, 0, var_len);
	if (!var_name)
		return (var_len);
	var_value = get_env_value(var_name, lst_env);
	free(var_name);
	if (var_value)
	{
		append_string(state, var_value);
		free(var_value);
	}
	return (var_len);
}
