/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:15:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/10/06 00:22:17 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

/*
** Vérifie si un caractère peut faire partie d'un nom de variable
*/
static int	is_valid_var_char(char c)
{
	return (ft_isalnum(c) || c == '_');
}

/*
** Obtient la valeur d'une variable d'environnement par son nom
** Gère le cas spécial de $? pour le code de retour
*/
char	*get_env_value(char *var_name, t_list *lst_env)
{
	t_list	**target;
	t_env	*env_node;

	if (!var_name)
		return (NULL);
	if (ft_strcmp(var_name, "?") == 0)
	{
		target = get_lst_key(&lst_env, "?");
		if (target && *target)
		{
			env_node = (t_env *)(*target)->content;
			if (env_node->value)
				return (ft_strdup(env_node->value));
		}
		return (ft_strdup("0"));
	}
	target = get_lst_key(&lst_env, var_name);
	if (target && *target)
	{
		env_node = (t_env *)(*target)->content;
		if (env_node->value)
			return (ft_strdup(env_node->value));
	}
	return (NULL);
}

/*
** Extrait le nom d'une variable depuis une chaîne (après le $)
** Gère le cas spécial de $? et les paramètres positionnels ($0-$9)
*/
char	*extract_var_name(char *str, int *len)
{
	int	i;

	i = 0;
	if (str[i] == '$')
		i++;
	if (str[i] == '?')
	{
		*len = 2;
		return (ft_strdup("?"));
	}
	if (ft_isdigit(str[i]))
	{
		*len = 2;
		return (NULL);
	}
	while (str[i] && is_valid_var_char(str[i]))
		i++;
	*len = i;
	if (i <= 1)
		return (NULL);
	return (ft_substr(str, 1, i - 1));
}
