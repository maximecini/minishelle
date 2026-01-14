/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:12:11 by thodavid          #+#    #+#             */
/*   Updated: 2025/07/23 09:45:51 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static int	is_valid(const char *s)
{
	if (!s || (!ft_isalpha(*s) && *s != '_'))
		return (0);
	++s;
	while (*s)
	{
		if (!ft_isalnum(*s) && *s != '_')
			return (0);
		++s;
	}
	return (1);
}

static void	unset_one(t_element **lst, char *key)
{
	t_element	*cur;
	t_node_env	*env;

	if (!lst || !*lst || !key)
		return ;
	cur = *lst;
	while (cur)
	{
		env = (t_node_env *)cur->content;
		if (env && ft_strcmp(env->key, key) == 0)
		{
			if (cur->prev)
				cur->prev->next = cur->next;
			else
				*lst = cur->next;
			if (cur->next)
				cur->next->prev = cur->prev;
			free(env->key);
			free(env->value);
			free(env);
			free(cur);
			return ;
		}
		cur = cur->next;
	}
}

int	unset(t_node_cmd *node, t_element **lst_env)
{
	int	i;
	int	err;

	if (!node || !lst_env)
		return (1);
	err = 0;
	i = 1;
	while (node->cmd[i])
	{
		if (!is_valid(node->cmd[i]))
		{
			err = 1;
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(node->cmd[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
		}
		else
			unset_one(lst_env, node->cmd[i]);
		i++;
	}
	return (err);
}
