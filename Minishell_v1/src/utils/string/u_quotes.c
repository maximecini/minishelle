/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_quotes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:40:05 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/29 15:19:51 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Traite une chaîne contenant potentiellement des quotes non fermées.
** Si une quote simple ou double est ouverte, lit des lignes supplémentaires
** jusqu'à fermeture via read_multiline_if_needed.
** Sinon, retourne une copie de la chaîne.
**
** Paramètres :
**   - str : chaîne d'entrée
**
** Retour :
**   - nouvelle chaîne allouée corrigée (à libérer par l’appelant)
*/
char	*process_quotes(char *str)
{
	int	quotes_is_valide;

	quotes_is_valide = check_unclosed_quotes(str);
	if (quotes_is_valide == UNCLOSED_SINGLE_QUOTE)
		return (read_multiline_if_needed(str, '\''));
	else if (quotes_is_valide == UNCLOSED_DOUBLE_QUOTE)
		return (read_multiline_if_needed(str, '"'));
	else
		return (ft_strdup(str));
}

/*
** Vérifie si la chaîne `s` contient un contexte où une expansion de variable
** (indiquée par $) est valide dans des guillemets doubles.
**
** Retourne 1 si la chaîne est dans un contexte de guillemets doubles,
** ou contient un $, 0 sinon.
*/
int	is_in_dquote(const char *s)
{
	int	i;
	int	flag_dollar;

	flag_dollar = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			flag_dollar = 1;
		if (s[i] == '\'')
			return (0);
		if (s[i] == '\"' && flag_dollar == 0)
			return (1);
		i++;
	}
	if (flag_dollar)
		return (1);
	return (0);
}

/*
** Indique si un caractère `c` est une quote qui doit être ignorée dans
** le contexte courant (défini par les flags in_single et in_double).
**
** Retour :
**
	- 1 si la quote doit être ignorée (c'est-à-dire si c est quote
**	  simple hors double quotes,ou quote double hors simple quotes),
**	  0 sinon.
*/
int	is_quote_to_skip(char c, int in_single, int in_double)
{
	int	ret;

	ret = 0;
	if (c == '\'' && !in_double)
		ret = 1;
	if (c == '"' && !in_single)
		ret = 1;
	return (ret);
}

/*
** Met à jour l'état des guillemets simples et doubles en fonction
** du caractère courant.
** - Bascule l'état de quote simple si on rencontre un ' hors double quote.
** - Bascule l'état de quote double si on rencontre un " hors simple quote.
**
** Paramètres :
**   - current_char       : caractère analysé
**   - inside_single_quote: pointeur vers état quote simple
**   - inside_double_quote: pointeur vers état quote double
*/
void	update_quote_state(char current_char, int *inside_single_quote,
		int *inside_double_quote)
{
	if (current_char == '\'' && !*inside_double_quote)
		*inside_single_quote = !*inside_single_quote;
	else if (current_char == '"' && !*inside_single_quote)
		*inside_double_quote = !*inside_double_quote;
}

/*
** Vérifie si une chaîne contient des quotes non fermées.
**
** Retourne :
**   - UNCLOSED_DOUBLE_QUOTE si une quote double est ouverte
**   - UNCLOSED_SINGLE_QUOTE si une quote simple est ouverte
**   - UNCLOSED_NONE si aucune quote non fermée n’est détectée
*/
int	check_unclosed_quotes(char *line)
{
	int	i;
	int	in_single;
	int	in_double;

	i = 0;
	in_single = 0;
	in_double = 0;
	while (line[i])
		update_quote_state(line[i++], &in_single, &in_double);
	if (in_double)
		return (UNCLOSED_DOUBLE_QUOTE);
	else if (in_single)
		return (UNCLOSED_SINGLE_QUOTE);
	return (UNCLOSED_NONE);
}
