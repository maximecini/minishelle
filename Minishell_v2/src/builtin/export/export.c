/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:59:28 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 15:27:15 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static int	validate_export_arg(char *arg)
{
	if (!arg || !arg[0])
	{
		ft_putstr_fd("export: `': not a valid identifier\n", 2);
		return (1);
	}
	if (arg[0] == '-')
	{
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': invalid option\n", 2);
		return (2);
	}
	return (0);
}

static int	apply_export_update(char *arg, t_list **lst_env)
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

static int	handle_entry(char *arg, t_list **lst_env)
{
	int	validation;

	validation = validate_export_arg(arg);
	if (validation)
		return (validation);
	return (apply_export_update(arg, lst_env));
}

static int	collect_export_errors(t_cmd *node, t_list **lst_env)
{
	int	i;
	int	error_code;
	int	ret;

	i = 1;
	error_code = 0;
	while (node->cmd[i])
	{
		ret = handle_entry(node->cmd[i], lst_env);
		if (ret != 0)
		{
			if (ret == 2)
				error_code = 2;
			else if (error_code != 2)
				error_code = 1;
		}
		i++;
	}
	return (error_code);
}

int	export(t_cmd *node, t_list **lst_env)
{
	int	error_code;

	if (!node || !node->cmd || !node->cmd[0])
		return (1);
	if (!node->cmd[1])
		return (export_print(lst_env));
	error_code = collect_export_errors(node, lst_env);
	node->status = error_code;
	return (error_code);
}
