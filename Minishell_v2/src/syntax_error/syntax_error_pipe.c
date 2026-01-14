/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:00:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:03:45 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static int	check_leading_pipe(char *line, size_t len)
{
	int	i;

	i = 0;
	while (i < (int)len && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (i < (int)len && line[i] == '|')
	{
		if (line[i + 1] == '|')
			return (syntax_error_msg("||"));
		return (syntax_error_msg("|"));
	}
	return (1);
}

static int	handle_pipe_count(int count, char *line, int j, size_t len)
{
	if (count == 1)
	{
		if (j >= (int)len || line[j] == '\0' || line[j] == '\n')
			return (syntax_error_msg("|"));
		else if (line[j] == '|')
			return (syntax_error_msg("|"));
	}
	else if (count == 2)
	{
		if (j >= (int)len || line[j] == '\0' || line[j] == '\n'
			|| line[j] == '|')
			return (syntax_error_msg("||"));
	}
	else if (count >= 3)
		return (syntax_error_msg("|"));
	return (1);
}

static int	process_pipe(char *line, int i, size_t len)
{
	int	count;
	int	j;

	count = 0;
	j = i;
	while (j < (int)len && line[j] == '|')
	{
		count++;
		j++;
	}
	while (j < (int)len && (line[j] == ' ' || line[j] == '\t'))
		j++;
	return (handle_pipe_count(count, line, j, len));
}

int	error_pipe(char *line, size_t len)
{
	int	i;
	int	result;

	result = check_leading_pipe(line, len);
	if (result != 1)
		return (result);
	i = 0;
	while (line[i] && i < (int)len)
	{
		if (!is_inside_quotes(line, i) && line[i] == '|')
		{
			result = process_pipe(line, i, len);
			if (result != 1)
				return (result);
			while (i < (int)len && line[i] == '|')
				i++;
			i--;
		}
		i++;
	}
	return (1);
}
