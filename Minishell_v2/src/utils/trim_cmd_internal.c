/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_cmd_internal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:00:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:25:36 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

/*
** Traite la boucle de trim des caractères
*/
static void	process_trim_loop(t_trim_state *state, char *str, int start,
		int end)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if (process_trim_char(state, str[i]))
			append_trim_char(state, str[i]);
		i++;
	}
}

/*
** Supprime les quotes et concatène selon POSIX
*/
char	*remove_quotes_trim_internal(char *str, int *was_quoted)
{
	t_trim_state	*state;
	char			*result;
	int				start;
	int				end;

	if (!str)
		return (NULL);
	*was_quoted = has_quotes(str);
	trim_whitespace(str, &start, &end);
	if (start > end)
	{
		free(str);
		return (NULL);
	}
	state = init_trim_state(ft_strlen(str) + 1);
	if (!state)
		return (str);
	process_trim_loop(state, str, start, end);
	result = state->result;
	free(state);
	free(str);
	return (result);
}
