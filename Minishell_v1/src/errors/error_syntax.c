/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:41:48 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/26 20:42:52 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Vérifie si l’opérateur `&` ou ; est invalide.
** Retourne 1 si une erreur est détectée, sinon 0.
*/
int	is_ampersand_invalid(char *operator)
{
	if (operator[0] == '&')
		return (print_syntax_error("&"));
	if (operator[0] == ';')
		return (print_syntax_error(";"));
	return (0);
}

/*
** Vérifie si l’opérateur `||` est mal utilisé.
** Retourne 1 si une erreur est détectée, sinon 0.
*/
int	is_or_operator_invalid(char *operator)
{
	if (operator[0] == '|' && operator[1] == '|')
		return (print_syntax_error("||"));
	return (0);
}

/*
** Vérifie si une redirection (`>`, `>>`, `<`,
	`<<`) est syntaxiquement invalide.
** Elle est invalide s’il n’y a rien après ou s’il y a un autre opérateur.
*/
int	is_redirection_invalid(char *input, int pos, int operator_len)
{
	char	*next_token;

	pos = skip_whitespace(input, pos + operator_len);
	next_token = identify_operator(input, pos);
	if (!input[pos] || next_token)
	{
		if (next_token)
			return (print_syntax_error(next_token));
		return (print_syntax_error("newline"));
	}
	return (0);
}

/*
** Vérifie si un pipe (`|`) est mal utilisé.
** - Pipe seul au début
** - Pipe suivi d’un autre pipe
** - Pipe sans rien derrière
*/
int	is_pipe_invalid(char *input, int pos, int operator_len)
{
	char	*next_token;

	if (pos == 0)
		return (print_syntax_error("|"));
	pos = skip_whitespace(input, pos + operator_len);
	next_token = identify_operator(input, pos);
	if (!input[pos] || (next_token && next_token[0] == '|'))
		return (print_syntax_error("|"));
	return (0);
}

/*
** Vérifie si l’opérateur trouvé à la position `pos` dans `input` est invalide.
** Utilise le contenu de l’opérateur (`operator`) et sa longueur (`operator_len`)
** pour déterminer s’il viole une règle de syntaxe.
** Retourne 1 si l’opérateur est invalide, 0 sinon.
*/
int	is_operator_invalid(char *input, int pos, char *operator, int operator_len)
{
	if (is_ampersand_invalid(operator))
		return (1);
	if (is_or_operator_invalid(operator))
		return (1);
	if (operator[0] == '>' || operator[0] == '<')
		return (is_redirection_invalid(input, pos, operator_len));
	if (operator[0] == '|')
		return (is_pipe_invalid(input, pos, operator_len));
	return (0);
}
