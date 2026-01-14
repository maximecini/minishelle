/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_cmd_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:00:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:25:36 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

/*
** Libère une redirection invalide
*/
static void	free_invalid_redirect(t_cmd *node_cmd, int i)
{
	if (node_cmd->redirect[i].files)
		free(node_cmd->redirect[i].files);
	if (node_cmd->redirect[i].eof)
		free(node_cmd->redirect[i].eof);
}

/*
** Copie une redirection valide
*/
static void	copy_valid_redirect(t_cmd *node_cmd, int i, int j)
{
	if (j != i)
		node_cmd->redirect[j] = node_cmd->redirect[i];
}

/*
** Traite une redirection pendant le trim
*/
static int	process_redirect_trim(t_cmd *node_cmd, int i, int j, int *ignored)
{
	if (node_cmd->redirect[i].is_heredoc)
	{
		copy_valid_redirect(node_cmd, i, j);
		return (1);
	}
	if (node_cmd->redirect[i].files)
	{
		node_cmd->redirect[i].files = remove_quotes_trim_internal(
				node_cmd->redirect[i].files, ignored);
		if (node_cmd->redirect[i].files && node_cmd->redirect[i].files[0])
		{
			copy_valid_redirect(node_cmd, i, j);
			return (1);
		}
		else
			free_invalid_redirect(node_cmd, i);
	}
	return (0);
}

/*
** Trim les redirections après expansion
*/
void	trim_redirections(t_cmd *node_cmd)
{
	int	i;
	int	j;
	int	ignored;

	if (!node_cmd || !node_cmd->redirect)
		return ;
	i = 0;
	j = 0;
	while (i < node_cmd->nb_redirect)
	{
		if (process_redirect_trim(node_cmd, i, j, &ignored))
			j++;
		i++;
	}
	node_cmd->nb_redirect = j;
}
