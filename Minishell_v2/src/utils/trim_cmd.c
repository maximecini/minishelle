/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:30:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/10/16 17:25:37 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

/*
** Wrapper pour remove_quotes_trim_internal
*/
char	*remove_quotes_and_trim(char *str)
{
	int	dummy;

	return (remove_quotes_trim_internal(str, &dummy));
}

/*
** Fonction principale de trim (alias pour clarté)
*/
char	*trim_string(char *str)
{
	return (remove_quotes_and_trim(str));
}

/*
** Version qui ne libère pas l'original (pour heredoc EOF)
*/
char	*trim_string_copy(char *str)
{
	char	*copy;

	if (!str)
		return (NULL);
	copy = ft_strdup(str);
	if (!copy)
		return (NULL);
	return (remove_quotes_and_trim(copy));
}

/*
** Fonction principale pour trim toutes les commandes
*/
int	trim_commands(t_list **lst_cmd)
{
	t_cmd	*node_cmd;
	t_list	*current;

	if (!lst_cmd || !*lst_cmd)
		return (0);
	current = *lst_cmd;
	while (current)
	{
		node_cmd = (t_cmd *)current->content;
		if (node_cmd)
		{
			trim_command_args(node_cmd);
			trim_redirections(node_cmd);
		}
		current = current->next;
	}
	return (0);
}
