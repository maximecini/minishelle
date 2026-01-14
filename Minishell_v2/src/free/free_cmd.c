/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:10:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 16:07:36 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static void	free_command_array(char **cmd)
{
	int	index;

	if (!cmd)
		return ;
	index = 0;
	while (cmd[index])
	{
		free(cmd[index]);
		index++;
	}
	free(cmd);
}

static void	free_redirect_entries(t_cmd *node_cmd)
{
	int	index;

	if (!node_cmd->redirect)
		return ;
	index = 0;
	while (index < node_cmd->nb_redirect)
	{
		free(node_cmd->redirect[index].files);
		free(node_cmd->redirect[index].eof);
		index++;
	}
	free(node_cmd->redirect);
}

void	free_node_cmd_content(void *content)
{
	t_cmd	*node_cmd;

	node_cmd = (t_cmd *)content;
	if (!node_cmd)
		return ;
	free_command_array(node_cmd->cmd);
	free(node_cmd->cmd_quoted);
	free_redirect_entries(node_cmd);
	free(node_cmd);
}
