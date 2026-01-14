/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_redirect_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:15:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:13:55 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	check_following_redirect(char *line, int j)
{
	if (line[j] == '>' && line[j + 1] == '>')
		return (syntax_error_msg(">>"));
	else if (line[j] == '<' && line[j + 1] == '<')
		return (syntax_error_msg("<<"));
	else if (line[j] == '>')
		return (syntax_error_msg(">"));
	else if (line[j] == '<')
		return (syntax_error_msg("<"));
	return (1);
}

int	handle_input_triple(int count)
{
	int	remainder;

	remainder = count - 3;
	if (remainder == 1)
		return (syntax_error_msg("<"));
	else if (remainder == 2)
		return (syntax_error_msg("<<"));
	return (syntax_error_msg("<<<"));
}

int	handle_triple_redirect(char redirect_char, int count, char *line, int j)
{
	int	remainder;

	if (j < (int)ft_strlen(line) && (line[j] == '>' || line[j] == '<'))
	{
		if (check_following_redirect(line, j) != 1)
			return (check_following_redirect(line, j));
	}
	if (redirect_char == '<')
		return (handle_input_triple(count));
	remainder = count - 2;
	if (remainder == 1)
		return (syntax_error_msg(">"));
	return (syntax_error_msg(">>"));
}
