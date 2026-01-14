/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiter_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 00:00:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/10/16 19:47:17 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static int	should_skip_dollar(char *str, int i)
{
	if (str[i] != '$')
		return (0);
	if (str[i + 1] != '"' && str[i + 1] != '\'')
		return (0);
	if (i > 0 && str[i - 1] == '$')
		return (0);
	return (1);
}

static int	should_skip_quote(char c)
{
	return (c == '"' || c == '\'');
}

static void	copy_valid_chars(char *str, char *result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (should_skip_dollar(str, i))
		{
			i++;
			continue ;
		}
		if (should_skip_quote(str[i]))
		{
			i++;
			continue ;
		}
		result[j++] = str[i++];
	}
	result[j] = '\0';
}

char	*process_delimiter_string(char *str)
{
	char	*result;

	if (!str)
		return (NULL);
	result = malloc(ft_strlen(str) + 1);
	if (!result)
		return (ft_strdup(str));
	copy_valid_chars(str, result);
	return (result);
}

char	*remove_quotes_from_delimiter(char *eof, int *should_expand)
{
	char	*processed;

	*should_expand = 1;
	if (!eof || !*eof)
		return (eof);
	if (has_quotes(eof))
		*should_expand = 0;
	processed = process_delimiter_string(eof);
	if (!processed)
		return (ft_strdup(eof));
	return (processed);
}
