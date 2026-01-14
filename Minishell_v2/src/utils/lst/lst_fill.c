/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 00:00:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/10/16 23:44:30 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static int	init_cmd_array(t_cmd **node_cmd, int word_count)
{
	(*node_cmd)->cmd_count = word_count;
	(*node_cmd)->cmd_capacity = word_count + 1;
	(*node_cmd)->cmd = ft_calloc(word_count + 1, sizeof(char *));
	if (!(*node_cmd)->cmd)
		return (0);
	return (1);
}

static int	init_redirect_array(t_cmd **node_cmd)
{
	if ((*node_cmd)->nb_redirect > 0)
	{
		(*node_cmd)->redirect = ft_calloc((*node_cmd)->nb_redirect,
				sizeof(t_redirect));
		if (!(*node_cmd)->redirect)
			return (0);
	}
	else
		(*node_cmd)->redirect = NULL;
	return (1);
}

static int	process_tokens_loop(t_list **lst_token, t_cmd **node_cmd,
		int *i, int *j)
{
	t_token	*node_token;

	while (*lst_token && ((t_token *)(*lst_token)->content)->type != PIPE)
	{
		node_token = (t_token *)(*lst_token)->content;
		if (node_token->type == WORD)
			process_word(node_cmd, i, node_token->value);
		else if (is_redirection(node_token->type))
		{
			if (!process_token_redirect(node_cmd, node_token, j))
				return (0);
		}
		*lst_token = (*lst_token)->next;
	}
	return (1);
}

int	fill_lst_node(t_list **lst_token, t_cmd **node_cmd)
{
	int		i;
	int		j;
	int		word_count;

	i = 0;
	j = 0;
	(*node_cmd)->nb_redirect = count_redirect(*lst_token);
	if ((*node_cmd)->nb_redirect == -1)
		return (0);
	word_count = count_cmd_words(*lst_token);
	if (!init_cmd_array(node_cmd, word_count))
		return (0);
	if (!init_redirect_array(node_cmd))
		return (0);
	if (!process_tokens_loop(lst_token, node_cmd, &i, &j))
		return (0);
	return (1);
}
