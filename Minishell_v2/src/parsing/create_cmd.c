/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:51:54 by simon             #+#    #+#             */
/*   Updated: 2025/10/16 23:44:21 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

t_cmd	*init_new_cmd(int nb_command)
{
	t_cmd	*node_cmd;

	node_cmd = ft_calloc(1, sizeof(t_cmd));
	if (!node_cmd)
		return (NULL);
	node_cmd->outfile = nb_command;
	node_cmd->pid = -1;
	node_cmd->cmd = NULL;
	node_cmd->status = 0;
	return (node_cmd);
}

void	update_cmd(t_list *lst_cmd)
{
	t_list	*current;
	t_list	*next;
	t_cmd	*cmd_curr;
	t_cmd	*cmd_next;

	current = lst_cmd;
	next = NULL;
	while (current)
	{
		cmd_curr = (t_cmd *)current->content;
		next = current->next;
		if (next)
		{
			cmd_next = (t_cmd *)next->content;
			cmd_next->infile = cmd_curr->outfile;
		}
		if (!next)
			cmd_curr->outfile = STDOUT_FILENO;
		current = next;
	}
}

int	fill_node(t_list **lst_cmd, t_list **lst_token)
{
	t_cmd	*node_cmd;
	t_list	*token_cursor;
	t_list	*token_head;

	token_head = *lst_token;
	token_cursor = *lst_token;
	while (*lst_cmd)
	{
		node_cmd = (t_cmd *)(*lst_cmd)->content;
		if (!fill_lst_node(&token_cursor, &node_cmd))
			return (0);
		next_cmd_lst(&token_cursor);
		lst_cmd = &(*lst_cmd)->next;
	}
	*lst_token = token_head;
	return (1);
}

static int	add_cmd_node(t_list **lst_cmd, int nb_command)
{
	t_cmd	*node_cmd;
	t_list	*new_node;

	node_cmd = init_new_cmd(nb_command);
	if (!node_cmd)
		return (0);
	new_node = ft_lstnew(node_cmd);
	if (!new_node)
		return (free(node_cmd), 0);
	ft_lstadd_back(lst_cmd, new_node);
	return (1);
}

int	create_lst_cmd(t_list *lst_token, t_list **lst_cmd)
{
	int		nb_command;
	int		cmd_count;

	nb_command = 3;
	cmd_count = 0;
	*lst_cmd = NULL;
	while (lst_token)
	{
		if (!(*lst_cmd) || ((t_token *)lst_token->content)->type == PIPE)
		{
			if (++cmd_count > MAX_PIPELINE_CMDS)
			{
				ft_putstr_fd("minishell: maximum pipeline length exceeded\n", 2);
				return (0);
			}
			if (!add_cmd_node(lst_cmd, nb_command))
				return (0);
		}
		nb_command += 1;
		lst_token = lst_token->next;
	}
	update_cmd(*lst_cmd);
	return (1);
}
