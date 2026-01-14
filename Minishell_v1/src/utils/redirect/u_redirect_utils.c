/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_redirect_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:42:03 by thodavid          #+#    #+#             */
/*   Updated: 2025/07/29 16:11:39 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Parcourt la chaîne 'str' depuis 'start' à la recherche d'un opérateur
** de redirection (<, >, <<, >>) en ignorant les parties entre quotes.
** Si trouvé, remplit 'type' avec le type de redirection et retourne l'index.
** Sinon, retourne -1.
*/
int	find_next_redir(char *str, int start, t_redirection_type *type)
{
	int	i;
	int	in_single;
	int	in_double;

	i = start;
	in_single = 0;
	in_double = 0;
	while (str[i])
	{
		update_quote_state(str[i], &in_single, &in_double);
		if (!in_single && !in_double)
		{
			*type = get_redirection_type(&str[i]);
			if (*type != NO_REDIR)
				return (i);
		}
		i++;
	}
	return (-1);
}

/*
** Gère une redirection trouvée dans 'str' à la position '*pos'.
** Remplit la structure 'r' avec le type et le nom du fichier cible.
** Avance '*pos' à la fin de la redirection. Retourne 1 si ok,
	-1 en cas d'erreur.
*/
int	handle_redir(char *str, int *pos, t_redirect *r, t_redirection_type type)
{
	int	i;

	r->type = type;
	if (type == REDIR_HEREDOC || type == REDIR_APPEND)
		i = *pos + 2;
	else
		i = *pos + 1;
	*pos = i;
	skip_spaces(str, pos);
	r->filename = extract_word(&str[*pos]);
	r->heredoc_filename = NULL;
	if (!r->filename)
		return (-1);
	r->file = 0;
	r->delimiteur = extract_word(&str[*pos]);
	r->here_doc_fd = 0;
	while (str[*pos] && !is_sep(str[*pos]))
		(*pos)++;
	return (1);
}
