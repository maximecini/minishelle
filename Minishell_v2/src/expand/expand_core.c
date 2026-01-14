/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:38:46 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 15:53:25 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

char	*expand_string(char *str, t_list *lst_env)
{
	t_expand_state	*state;

	if (!str)
		return (NULL);
	state = init_expand_state(1);
	if (!state)
		return (ft_strdup(str));
	while (*str)
		process_char(state, &str, lst_env);
	return (finalize_expand_state(state));
}

char	*expand_string_heredoc(char *str, t_list *lst_env)
{
	t_expand_state	*state;

	if (!str)
		return (NULL);
	state = init_expand_state(0);
	if (!state)
		return (ft_strdup(str));
	while (*str)
		process_char(state, &str, lst_env);
	return (finalize_expand_state(state));
}
