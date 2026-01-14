/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc_clean.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:15:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/10/15 19:53:43 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

/*
** Détecte si une chaîne contient des quotes (pour heredoc EOF)
** Retourne 1 si des quotes sont présentes, 0 sinon
*/
int	has_quotes(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

/*
** Expanse une ligne de heredoc selon POSIX
** N'expanse PAS dans heredoc si EOF avait des quotes
** IMPORTANT: Ne fait que l'expansion, pas de trim/quote removal
*/
char	*expand_heredoc_line(char *line, t_list *lst_env, int should_expand)
{
	char	*expanded;

	if (!line)
		return (NULL);
	if (!should_expand)
		return (ft_strdup(line));
	expanded = expand_string_heredoc(line, lst_env);
	if (!expanded)
		return (ft_strdup(line));
	return (expanded);
}

/*
** Ancien nom pour compatibilité - À SUPPRIMER si non utilisé ailleurs
** Cette fonction ne devrait PAS trim dans heredoc
*/
char	*expand_heredoc_content(char *content, t_list *lst_env)
{
	return (expand_string_heredoc(content, lst_env));
}
