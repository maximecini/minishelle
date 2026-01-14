/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_free_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:00:31 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/28 10:55:48 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_list(t_element *node_lst)
{
	t_element	*temp;
	t_node_cmd	*cmd;

	while (node_lst)
	{
		temp = node_lst;
		cmd = (t_node_cmd *)node_lst->content;
		if (cmd)
		{
			free_commands(cmd->cmd);
			free(cmd);
		}
		node_lst = node_lst->next;
		free(temp);
	}
}

/*
** Libère les redirections en cas d'erreur.
*/
void	free_redirects(t_redirect *arr, int n)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i < n)
	{
		free(arr[i].filename);
		free(arr[i].delimiteur);
		i++;
	}
	free(arr);
}

void	free_node_cmd_content(void *content)
{
	t_node_cmd	*node;
	int			i;

	node = (t_node_cmd *)content;
	if (node->cmd)
	{
		i = 0;
		while (node->cmd[i])
			free(node->cmd[i++]);
		free(node->cmd);
	}
	if (node->redirect)
	{
		i = 0;
		while (i < node->nb_redirect)
		{
			free(node->redirect[i].filename);
			free(node->redirect[i].delimiteur);
			if (node->redirect[i].heredoc_filename)
				free(node->redirect[i].heredoc_filename);
			i++;
		}
		free(node->redirect);
	}
	free(node);
}

void	free_node_env_content(void *content)
{
	t_node_env	*node;

	node = (t_node_env *)content;
	if (!node)
		return ;
	if (node->key)
		free(node->key);
	if (node->value)
		free(node->value);
	free(node);
}

void	free_list_custom(t_element *lst, void (*free_content)(void *))
{
	t_element	*tmp;

	while (lst)
	{
		tmp = lst->next;
		if (free_content)
			free_content(lst->content);
		free(lst);
		lst = tmp;
	}
}
