/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_lst_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:43:38 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/26 19:45:27 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*build_env_string(t_node_env *node_env)
{
	char	*cpy;
	char	*temp;

	if (!node_env->key || !node_env->value)
		return (NULL);
	cpy = ft_strjoin(node_env->key, "=", 0, 0);
	if (!cpy)
		return (NULL);
	temp = ft_strjoin(cpy, node_env->value, 1, 0);
	if (!temp)
	{
		free(cpy);
		return (NULL);
	}
	return (temp);
}

static int	fill_env_array(t_element *lst_env, char **str, int nb)
{
	int			i;
	t_node_env	*node_env;
	char		*env_str;

	i = 0;
	while (i < nb && lst_env)
	{
		if (!lst_env->content)
		{
			lst_env = lst_env->next;
			continue ;
		}
		node_env = (t_node_env *)lst_env->content;
		env_str = build_env_string(node_env);
		if (!env_str)
		{
			lst_env = lst_env->next;
			continue ;
		}
		str[i++] = env_str;
		lst_env = lst_env->next;
	}
	if (i != nb)
		return (-1);
	return (0);
}

char	**cpy_lst_to_tab(t_element *lst_env)
{
	char	**str;
	int		nb;

	nb = count_lst_valide(lst_env);
	str = malloc(sizeof(char *) * (nb + 1));
	if (!str)
		return (NULL);
	if (fill_env_array(lst_env, str, nb) == -1)
	{
		ft_free_split(str);
		return (NULL);
	}
	str[nb] = NULL;
	return (str);
}
