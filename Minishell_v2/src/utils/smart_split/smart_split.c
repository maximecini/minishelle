/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:38:14 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:21:29 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	count_words(char *line, char ch)
{
	size_t	i;
	size_t	trigger;
	int		j;

	(void)ch;
	i = 0;
	trigger = 0;
	j = 0;
	while (line[j])
	{
		if (is_quote(line[j]))
			j += size_quotes(line, j);
		if (is_metachar(line[j]))
		{
			count_metachar(line, &j, &i, &trigger);
			continue ;
		}
		process_count_char(line, &j, &i, &trigger);
	}
	return (i);
}

char	**write_words(char **ret, char *line, int j, int i)
{
	int				size_words;
	t_split_state	state;
	int				params[2];

	size_words = 0;
	state.index = &i;
	state.cursor = &j;
	state.word_size = &size_words;
	ret = process_write_loop(ret, line, &state, &size_words);
	if (!ret)
		return (NULL);
	params[0] = *state.word_size;
	params[1] = *state.cursor;
	return (finalize_write(ret, line, *state.index, params));
}

char	**smart_split(char *line)
{
	char	**ret;
	int		nb_words;

	nb_words = count_words(line, ' ');
	ret = ft_calloc(nb_words + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	return (write_words(ret, line, 0, 0));
}

void	ft_free_split(char **split)
{
	size_t	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
