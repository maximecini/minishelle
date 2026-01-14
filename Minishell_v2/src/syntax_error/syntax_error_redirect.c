/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_redirect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:00:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:13:52 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static int	check_redirect_token(char *line, int j)
{
	if (line[j] == '>' && line[j + 1] == '>')
		return (syntax_error_msg(">>"));
	else if (line[j] == '<' && line[j + 1] == '<')
		return (syntax_error_msg("<<"));
	else if (line[j] == '|' && line[j + 1] == '|')
		return (syntax_error_msg("||"));
	else if (line[j] == '>')
		return (syntax_error_msg(">"));
	else if (line[j] == '<')
		return (syntax_error_msg("<"));
	else if (line[j] == '|')
		return (syntax_error_msg("|"));
	return (1);
}

static int	handle_single_redirect(char *line, int j, size_t len)
{
	if (j >= (int)len || line[j] == '\0' || line[j] == '\n')
		return (syntax_error_msg("newline"));
	else if (line[j] == '>' || line[j] == '<' || line[j] == '|')
		return (check_redirect_token(line, j));
	return (1);
}

static int	process_redirect(char *line, int i, size_t len)
{
	char	redirect_char;
	int		count;
	int		j;

	redirect_char = line[i];
	count = 0;
	j = i;
	while (j < (int)len && line[j] == redirect_char)
	{
		count++;
		j++;
	}
	while (j < (int)len && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if (count == 1 || count == 2)
		return (handle_single_redirect(line, j, len));
	else if (count >= 3)
		return (handle_triple_redirect(redirect_char, count, line, j));
	return (1);
}

int	error_redirect(char *line, size_t len)
{
	int	i;
	int	result;

	i = 0;
	while (line[i] && i < (int)len)
	{
		if (!is_inside_quotes(line, i))
		{
			if (line[i] == '<' && line[i + 1] == '>')
				return (syntax_error_msg("newline"));
			if (line[i] == '>' || line[i] == '<')
			{
				result = process_redirect(line, i, len);
				if (result != 1)
					return (result);
				while (i < (int)len && (line[i] == '>' || line[i] == '<'))
					i++;
				i--;
			}
		}
		i++;
	}
	return (1);
}
