/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:58:19 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 19:25:57 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*get_env_var_value(char *var_name, t_element **lst_env)
{
	t_element	**target;
	t_node_env	*node_env;
	char		*var_value;

	target = get_lst_key(lst_env, var_name);
	var_value = "";
	if (target && *target)
	{
		node_env = (t_node_env *)(*target)->content;
		if (node_env->value)
			var_value = node_env->value;
	}
	return (var_value);
}

static char	*expand_normal_variable(char *arg, char *temp, t_element **lst_env)
{
	char	*var_env;
	char	*var_value;
	char	*new_arg;

	var_env = extract_env_var_name(temp);
	if (!var_env)
		return (NULL);
	var_value = get_env_var_value(var_env, lst_env);
	new_arg = replace_variable_in_string(arg, var_env, var_value);
	free(var_env);
	return (new_arg);
}

static char	*expand_status_variable(char *arg)
{
	char	*var_env;
	char	*var_value;
	char	*new_arg;

	var_env = ft_strdup("?");
	var_value = ft_itoa(g_last_status);
	new_arg = replace_variable_in_string(arg, var_env, var_value);
	free(var_env);
	free(var_value);
	return (new_arg);
}

char	*process_single_expansion(char **arg, char **temp, t_element **lst_env)
{
	char	*new_arg;
	char	*old_arg;
	int		pos;

	pos = *temp - *arg;
	old_arg = *arg;
	if ((*temp)[1] == '?')
		new_arg = expand_status_variable(*arg);
	else
	{
		new_arg = expand_normal_variable(*arg, *temp, lst_env);
		if (!new_arg)
			return (NULL);
	}
	if (new_arg)
	{
		*arg = new_arg;
		free(old_arg);
		*temp = *arg + pos;
	}
	return (new_arg);
}
