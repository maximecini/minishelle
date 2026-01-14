/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:58:24 by thodavid          #+#    #+#             */
/*   Updated: 2025/07/09 10:05:51 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	update_env(char **env, char *cmd)
{
	int		i;
	char	*key;
	char	*tmp_key;

	key = get_key(cmd);
	i = 1;
	while (env[i])
	{
		tmp_key = get_key(env[i]);
		if (!ft_strcmp(key, tmp_key))
		{
			free(env[i]);
			env[i] = ft_strdup(cmd);
			break ;
		}
		free(tmp_key);
		i++;
	}
	free(key);
}

static int	export_print(t_element **lst_env)
{
	t_element	*cpy;

	cpy = ft_lstcpy(*lst_env, free_node_env_content);
	if (!cpy)
		return (1);
	ft_sort_lst(cpy, cmp_key);
	print_lst_env(cpy);
	ft_lstclear(&cpy, NULL);
	return (0);
}

static int	handle_entry(char *arg, t_element **lst_env)
{
	char	*key;
	char	*val;
	char	*eq;

	eq = ft_strchr(arg, '=');
	key = get_key(arg);
	val = get_value(arg);
	if (get_error_export(arg))
	{
		free(key);
		free(val);
		return (1);
	}
	if (!get_lst_key(lst_env, key))
		add_back_nodes_env(lst_env, arg, 1);
	else
		update_nodes_env(*lst_env, key, val, eq);
	free(key);
	free(val);
	return (0);
}

int	export(t_node_cmd *node, t_element **lst_env)
{
	int	i;
	int	error_occurred;

	error_occurred = 0;
	if (!node || !node->cmd)
		return (1);
	if (ft_array_len(node->cmd) == 1)
		return (export_print(lst_env));
	i = 1;
	while (node->cmd[i])
	{
		if (handle_entry(node->cmd[i], lst_env) != 0)
			error_occurred = 1;
		++i;
	}
	if (error_occurred)
		return (1);
	return (0);
}
