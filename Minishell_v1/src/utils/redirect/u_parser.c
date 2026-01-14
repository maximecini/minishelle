/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 08:56:32 by thodavid          #+#    #+#             */
/*   Updated: 2025/07/26 18:59:50 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Détecte si on est sur une redirection non entre guillemets.
** Si oui, saute l'opérateur et son argument.
** Renvoie 1 si une redirection a été traitée, sinon 0.
*/
int	is_redirection_to_skip(const char *line, size_t *read_pos)
{
	t_redirection_type	redir_type;
	int					tmp_sq;
	int					tmp_dq;

	redir_type = get_redirection_type((char *)&line[*read_pos]);
	if (redir_type == NO_REDIR)
		return (0);
	if (redir_type == REDIR_HEREDOC || redir_type == REDIR_APPEND)
		*read_pos += 2;
	else
		*read_pos += 1;
	while (line[*read_pos] == ' ')
		(*read_pos)++;
	tmp_sq = 0;
	tmp_dq = 0;
	while (line[*read_pos])
	{
		update_quote_state(line[*read_pos], &tmp_sq, &tmp_dq);
		if (!tmp_sq && !tmp_dq && is_sep(line[*read_pos]))
			break ;
		(*read_pos)++;
	}
	return (1);
}

/*
** Détermine le type de redirection à partir d’une chaîne donnée.
** La chaîne est supposée pointer sur un opérateur de redirection.
**
** Retourne :
** - REDIR_HEREDOC  pour "<<"
** - REDIR_APPEND   pour ">>"
** - REDIR_STDIN    pour "<"
** - REDIR_STDOUT   pour ">"
** - NO_REDIR       si aucun opérateur reconnu ou chaîne invalide
*/
t_redirection_type	get_redirection_type(char *str)
{
	if (!str || !*str)
		return (NO_REDIR);
	if (str[0] == '<' && str[1] == '<')
		return (REDIR_HEREDOC);
	if (str[0] == '>' && str[1] == '>')
		return (REDIR_APPEND);
	if (str[0] == '<')
		return (REDIR_STDIN);
	if (str[0] == '>')
		return (REDIR_STDOUT);
	return (NO_REDIR);
}

/*
** Retourne 1 si le caractère à str[index] correspond à une
** redirection valide hors quotes, 0 sinon.
*/
int	is_redirection_valid(char *str, int index, int in_single_quote,
		int in_double_quote)
{
	t_redirection_type	type;

	if (in_single_quote || in_double_quote)
		return (0);
	type = get_redirection_type(&str[index]);
	if (type != NO_REDIR)
		return (1);
	return (0);
}

/*
** Retourne le nombre de caractères à sauter après avoir trouvé
** une redirection dans la chaîne str à l'index donné.
** (1 pour < ou >, 2 pour << ou >>)
*/
int	get_redirection_step(char *str, int index)
{
	t_redirection_type	type;

	type = get_redirection_type(&str[index]);
	if (type == REDIR_HEREDOC || type == REDIR_APPEND)
		return (2);
	return (1);
}

/*
** Parcourt la ligne de commande 'str' et compte le nombre total
** d'opérateurs de redirection (<, >, <<, >>), en ignorant ceux
** qui se trouvent à l’intérieur de quotes simples ou doubles.
**
** Retourne le nombre total de redirections valides trouvées.
*/
int	count_redirects(char *str)
{
	int	index;
	int	redirect_count;
	int	in_single_quote;
	int	in_double_quote;

	index = 0;
	redirect_count = 0;
	in_single_quote = 0;
	in_double_quote = 0;
	while (str[index])
	{
		update_quote_state(str[index], &in_single_quote, &in_double_quote);
		if (is_redirection_valid(str, index, in_single_quote, in_double_quote))
		{
			redirect_count++;
			index += get_redirection_step(str, index);
			continue ;
		}
		index++;
	}
	return (redirect_count);
}
