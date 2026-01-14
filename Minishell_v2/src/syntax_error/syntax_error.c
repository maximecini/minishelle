/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:49:52 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:07:05 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	error_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '&' && line[i + 1] == '&' && !is_inside_quotes(line, i))
			return (syntax_error_msg("&&"));
		i++;
	}
	return (1);
}

int	get_quote_error(char *line)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (line[i])
	{
		if (line[i] == DBL_QUOTES || line[i] == SIMPLE_QUOTES)
		{
			nb = check_quotes(line + i);
			if (!nb)
				return (printf("syntax error near quote\n"), 0);
			else
				i += nb;
		}
		i++;
	}
	return (1);
}

static int	check_semicolon_and_ampersand(char *trimmed_line)
{
	int	i;

	i = 0;
	while (trimmed_line[i])
	{
		if (trimmed_line[i] == ';' && !is_inside_quotes(trimmed_line, i))
			return (syntax_error_msg(";"), 0);
		i++;
	}
	if (!error_char(trimmed_line))
		return (0);
	i = 0;
	while (trimmed_line[i])
	{
		if (trimmed_line[i] == '&' && !is_inside_quotes(trimmed_line, i))
			return (syntax_error_msg("&"), 0);
		i++;
	}
	return (1);
}

static int	validate_syntax(char *trimmed_line, size_t len_line)
{
	if (!check_semicolon_and_ampersand(trimmed_line))
		return (0);
	if (!error_pipe(trimmed_line, len_line))
		return (0);
	if (!error_redirect(trimmed_line, len_line))
		return (0);
	return (1);
}

int	get_syntax_error(char *line)
{
	char	*trimmed_line;
	size_t	len_line;

	if (!line)
		return (1);
	trimmed_line = ft_strtrim(line, " \t\n\r\f\v");
	if (!trimmed_line)
		return (0);
	len_line = ft_strlen(trimmed_line);
	if (!ft_str_is_printable(trimmed_line))
		return (free(trimmed_line), 0);
	if (!validate_syntax(trimmed_line, len_line))
		return (free(trimmed_line), 0);
	free(trimmed_line);
	return (1);
}
