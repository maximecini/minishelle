/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_redirect_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:52:42 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/29 16:22:48 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Fonction principale de parsing de redirection :
** cherche une redirection dans 'str' à partir de '*pos',
** la parse et remplit la structure 'r'.
** Retourne 1 si redirection trouvée et traitée,
** 0 si rien trouvé, -1 en cas d’erreur mémoire.
*/
int	parse_redirect(char *str, int *pos, t_redirect *r)
{
	t_redirection_type	type;
	int					index;

	index = find_next_redir(str, *pos, &type);
	if (index == -1)
		return (0);
	*pos = index;
	return (handle_redir(str, pos, r, type));
}

/*
** Gère les redirections pour une commande.
*/
// process_redirections moved to u_redirect_process.c

/*
** Alloue un tableau pour stocker les redirections.
*/
static t_redirect	*alloc_redirects(int count)
{
	t_redirect	*res;

	res = malloc(sizeof(t_redirect) * count);
	if (!res)
		return (NULL);
	return (res);
}

/*
** Analyse une ligne pour extraire les redirections.
** Remplit un tableau de t_redirect.
*/
t_redirect	*check_redirect(char *line, int *redir_count)
{
	t_redirect	*redirects;
	int			cursor;
	int			current_index;
	int			parse_result;

	cursor = 0;
	current_index = 0;
	*redir_count = count_redirects(line);
	if (*redir_count == 0)
		return (NULL);
	redirects = alloc_redirects(*redir_count);
	if (!redirects)
		return (NULL);
	while (line[cursor] && current_index < *redir_count)
	{
		parse_result = parse_redirect(line, &cursor, &redirects[current_index]);
		if (parse_result == -1)
			return (free_redirects(redirects, current_index), NULL);
		if (parse_result == 1)
			current_index++;
		else
			cursor++;
	}
	return (redirects);
}
