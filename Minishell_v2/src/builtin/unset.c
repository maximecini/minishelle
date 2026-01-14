/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:46:38 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 15:15:11 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/function.h"

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

static void	free_env_node(t_env *env)
{
	if (!env)
		return ;
	if (env->key)
		free(env->key);
	if (env->value)
		free(env->value);
	free(env);
}

static void	remove_current_node(t_list **lst, t_list *prev, t_list *cur)
{
	t_list	*next;

	if (!lst || !cur)
		return ;
	next = cur->next;
	if (prev)
		prev->next = next;
	else
		*lst = next;
	free_env_node((t_env *)cur->content);
	free(cur);
}

static void	unset_one(t_list **lst, char *key)
{
	t_list	*cur;
	t_list	*prev;
	t_env	*env;

	if (!lst || !*lst || !key)
		return ;
	prev = NULL;
	cur = *lst;
	while (cur)
	{
		env = (t_env *)cur->content;
		if (env && env->key && !ft_strcmp(env->key, key))
		{
			remove_current_node(lst, prev, cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

int	unset(t_cmd *node, t_list **lst_env)
{
	int	i;

	if (!node || !lst_env)
		return (1);
	i = 1;
	while (node->cmd[i])
	{
		if (node->cmd[i][0] == '-' && node->cmd[i][1])
		{
			ft_putstr_fd("bash: unset: -", 2);
			ft_putchar_fd(node->cmd[i][1], 2);
			ft_putendl_fd(": invalid option", 2);
			ft_putendl_fd("unset: usage: unset [-f] [-v] [-n] [name ...]", 2);
			return (2);
		}
		if (is_valid(node->cmd[i]))
			unset_one(lst_env, node->cmd[i]);
		i++;
	}
	return (0);
}
