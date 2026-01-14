/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_multilin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:18:20 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/26 20:01:10 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Supprime `nb_caracter` caractères depuis la fin de la chaîne `line`.
** Remplace le premier caractère à supprimer par '\0' pour tronquer la chaîne.
**
** Paramètres :
**  - line        : chaîne à modifier
**  - nb_caracter : nombre de caractères à supprimer depuis la fin
**
** Retour :
**  - 1 toujours (à améliorer en cas d'erreur)
*/
static int	delete_caracter(char *line, size_t nb_caracter)
{
	size_t	len;
	size_t	delete_pos;
	int		i;

	len = ft_strlen(line);
	delete_pos = len - nb_caracter;
	i = 0;
	while (line[i])
	{
		if ((size_t)i == delete_pos)
			line[i] = '\0';
		i++;
	}
	return (1);
}

static void	setup_sigint_multiline(struct sigaction *old_sa)
{
	struct sigaction	new_sa;

	new_sa.sa_handler = handle_sigint_multiline;
	sigemptyset(&new_sa.sa_mask);
	new_sa.sa_flags = 0;
	sigaction(SIGINT, &new_sa, old_sa);
}

static char	*read_until_quote_closed(char *line)
{
	char	*add;
	char	*tmp;

	while (check_unclosed_quotes(line))
	{
		add = prompt_and_read_line();
		if (!add)
			return (free(line), NULL);
		tmp = ft_strjoin(line, add, 1, 1);
		if (!tmp)
			return (NULL);
		line = ft_strjoin(tmp, "\n", 1, 0);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*read_multiline_if_needed(char *initial_line, char quote_type)
{
	char				*line;
	struct sigaction	old_sa;

	if (!initial_line || (quote_type != '\'' && quote_type != '"'))
		return (NULL);
	setup_sigint_multiline(&old_sa);
	line = ft_strjoin(initial_line, "\n", 0, 0);
	if (!line)
		return (NULL);
	line = read_until_quote_closed(line);
	sigaction(SIGINT, &old_sa, NULL);
	if (!line)
		return (NULL);
	delete_caracter(line, 1);
	return (line);
}
