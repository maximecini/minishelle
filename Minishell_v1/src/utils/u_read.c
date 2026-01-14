/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 08:53:21 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/28 10:56:26 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

/*
** Affiche un prompt simple ">" et lit une ligne depuis l'entrée standard.
** Retourne la ligne lue (allouée dynamiquement), ou NULL en cas d'erreur.
** Met à jour `g_last_status` (probablement code de statut global).
**
** Remarque : TODO rajouter le nom dans le prompt (actuellement ">" seul).
*/
char	*prompt_and_read_line(void)
{
	char	*line;

	write(1, ">", 1);
	line = get_next_line(STDIN_FILENO, '\n');
	if (!line)
		return (NULL);
	return (line);
}

int	acces_file(char *cmd)
{
	struct stat	st;

	if (access(cmd, F_OK) == -1)
		return (127);
	if (access(cmd, R_OK) == -1)
		return (126);
	if (stat(cmd, &st) == -1)
		return (126);
	if (S_ISDIR(st.st_mode))
		return (126);
	return (0);
}
