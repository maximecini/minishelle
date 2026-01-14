/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_cmd_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:00:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:25:36 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

/*
** Copie un argument s'il est gardé
*/
static void	copy_kept_arg(t_cmd *node_cmd, int read_idx, int write_idx)
{
	if (write_idx != read_idx)
	{
		node_cmd->cmd[write_idx] = node_cmd->cmd[read_idx];
		if (node_cmd->cmd_quoted)
			node_cmd->cmd_quoted[write_idx] = node_cmd->cmd_quoted[read_idx];
	}
}

/*
** Compacte le tableau cmd en retirant les arguments vides/NULL
*/
static void	compact_cmd_array(t_cmd *node_cmd)
{
	int	read_idx;
	int	write_idx;
	int	was_quoted;

	read_idx = 0;
	write_idx = 0;
	while (node_cmd->cmd[read_idx])
	{
		was_quoted = (node_cmd->cmd_quoted
				&& node_cmd->cmd_quoted[read_idx]);
		if (node_cmd->cmd[read_idx][0] != '\0' || was_quoted)
		{
			copy_kept_arg(node_cmd, read_idx, write_idx);
			write_idx++;
		}
		else
			free(node_cmd->cmd[read_idx]);
		read_idx++;
	}
	node_cmd->cmd[write_idx] = NULL;
	if (node_cmd->cmd_count > write_idx)
		node_cmd->cmd_count = write_idx;
}

/*
** Initialise le tableau cmd_quoted si nécessaire
*/
static int	init_cmd_quoted(t_cmd *node_cmd)
{
	if (!node_cmd->cmd_quoted)
	{
		node_cmd->cmd_quoted = ft_calloc(node_cmd->cmd_capacity, sizeof(int));
		if (!node_cmd->cmd_quoted)
			return (0);
	}
	return (1);
}

/*
** Trim tous les arguments d'une commande
*/
void	trim_command_args(t_cmd *node_cmd)
{
	int	i;
	int	was_quoted;

	if (!node_cmd || !node_cmd->cmd)
		return ;
	if (!init_cmd_quoted(node_cmd))
		return ;
	i = 0;
	while (node_cmd->cmd[i])
	{
		node_cmd->cmd[i] = remove_quotes_trim_internal(node_cmd->cmd[i],
				&was_quoted);
		if (!node_cmd->cmd[i])
			node_cmd->cmd[i] = ft_strdup("");
		node_cmd->cmd_quoted[i] = was_quoted;
		i++;
	}
	compact_cmd_array(node_cmd);
}
