/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:37:59 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 15:53:25 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static int	expand_one_command(t_cmd *node_cmd, t_list *lst_env)
{
	if (!node_cmd)
		return (0);
	if (expand_command_args(node_cmd, lst_env) == -1)
		return (-1);
	if (expand_redirections(node_cmd, lst_env) == -1)
		return (-1);
	return (0);
}

int	expand(t_list **lst_cmd, t_list *lst_env)
{
	t_list	*current;

	if (!lst_cmd || !*lst_cmd)
		return (0);
	current = *lst_cmd;
	while (current)
	{
		if (expand_one_command((t_cmd *)current->content, lst_env) == -1)
			return (-1);
		current = current->next;
	}
	return (0);
}
