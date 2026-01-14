/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 16:35:26 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 16:10:38 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	free_node_token_content(void *content)
{
	t_token	*token;

	token = (t_token *)content;
	if (!token)
		return ;
	free(token);
}

int	free_all(t_list **lst_token, char **tab, char *line)
{
	ft_lstclear(lst_token, free_node_token_content);
	ft_free_split(tab);
	free(line);
	return (1);
}

void	cleanup_prompt_state(t_list **lst_token, t_list **lst_cmd, char ***tab)
{
	if (lst_token)
		ft_lstclear(lst_token, free_node_token_content);
	if (lst_cmd)
		ft_lstclear(lst_cmd, free_node_cmd_content);
	if (tab && *tab)
	{
		ft_free_split(*tab);
		*tab = NULL;
	}
}

int	free_all_with_cmd(t_list **lst_token, t_list **lst_cmd, char **tab,
		char *line)
{
	ft_lstclear(lst_token, free_node_token_content);
	if (lst_cmd)
		ft_lstclear(lst_cmd, free_node_cmd_content);
	ft_free_split(tab);
	free(line);
	return (1);
}

void	free_node_env_content(void *content)
{
	t_env	*node;

	node = (t_env *)content;
	if (!node)
		return ;
	if (node->key)
		free(node->key);
	if (node->value)
		free(node->value);
	free(node);
}
