/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_checks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 07:42:32 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/17 12:04:55 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Vérifie si un caractère est un séparateur (espace ou fin de chaîne).
**
** Paramètres :
**   - c : caractère à tester
**
** Retour :
**   - 1 si le caractère est un séparateur, 0 sinon
*/
int	is_sep(char c)
{
	return (c == ' ' || c == '\0');
}

/*
** Vérifie si un caractère `c` est égal à `sep`, *et* qu'il n'est pas
** à l'intérieur de guillemets simples ou doubles.
**
** Paramètres :
**   - c  : caractère à tester
**   - sq : indicateur "dans simple quote" (1 si oui)
**   - dq : indicateur "dans double quote" (1 si oui)
**   - sep: séparateur attendu
**
** Retour :
**   - 1 si c == sep et pas dans des quotes, 0 sinon
*/
int	is_unquoted(char c, int sq, int dq, char sep)
{
	return (c == sep && !sq && !dq);
}

/*
** Compte le nombre de redirections simples ('<' ou '>') dans la ligne.
** Ne compte que celles qui ne font pas partie d’un double opérateur
** (pas précédées ni suivies par le même caractère).
**
** Paramètres :
**   - line : chaîne à analyser
**
** Retour :
**   - nombre de redirections simples trouvées
*/
int	is_simple_redirect(char *line)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (line[i])
	{
		if ((line[i] == '<') && line[i + 1] != '<' && line[i - 1] != '<')
			c++;
		if ((line[i] == '>') && line[i + 1] != '>' && line[i - 1] != '>')
			c++;
		i++;
	}
	return (c);
}

/*
** Compte le nombre de redirections doubles ('<<' ou '>>') dans la ligne.
**
** Paramètres :
**   - line : chaîne à analyser
**
** Retour :
**   - nombre de redirections doubles trouvées
*/
int	is_double_redirect(char *line)
{
	int	i;
	int	c;
	int	j;

	i = 1;
	j = 0;
	c = 0;
	while (line[i])
	{
		if (line[j] == '>' && line[i] == '>')
			c++;
		if (line[j] == '<' && line[i] == '<')
			c++;
		j = i;
		i++;
	}
	return (c);
}

/*
** Analyse le caractère à la position `index` dans `input` pour identifier
** un opérateur logique ou de redirection.
**
** Paramètres :
**   - input : chaîne source à analyser
**   - index : position actuelle dans la chaîne
**
** Retour :
**   - une chaîne constante représentant l’opérateur trouvé
**     ("||", ">>", "<<", "|", ">", "<", "&", ";")
**   - NULL si aucun opérateur reconnu à cette position
*/
char	*identify_operator(const char *input, int index)
{
	if (input[index] == '|' && input[index + 1] == '|')
		return (OR);
	if (input[index] == '>' && input[index + 1] == '>')
		return (APPEND);
	if (input[index] == '<' && input[index + 1] == '<')
		return (HEREDOC);
	if (input[index] == '|')
		return (PIPE);
	if (input[index] == '>')
		return (REDIR_OUT);
	if (input[index] == '<')
		return (REDIR_IN);
	if (input[index] == '&')
		return ("&");
	if (input[index] == ';')
		return (";");
	return (NULL);
}
