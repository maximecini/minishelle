/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:53:28 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/15 19:53:28 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	*join_key_value(t_env *env_item)
{
	char	*temp;

	if (!env_item->key)
		return (NULL);
	temp = ft_strjoin(env_item->key, "=", 0, 0);
	if (!temp)
		return (NULL);
	if (!env_item->value)
		return (temp);
	return (ft_strjoin(temp, env_item->value, 1, 0));
}

static void	free_partial_env(char **env_array, int count)
{
	int	index;

	index = 0;
	while (index < count)
	{
		free(env_array[index]);
		index++;
	}
	free(env_array);
}

char	**env_list_to_array(t_list *lst_env)
{
	int		count;
	char	**env_array;
	int		index;
	t_env	*env_item;

	count = ft_lstsize(lst_env);
	env_array = ft_calloc(count + 1, sizeof(char *));
	if (!env_array)
		return (NULL);
	index = 0;
	while (lst_env && index < count)
	{
		env_item = (t_env *)lst_env->content;
		env_array[index] = join_key_value(env_item);
		if (!env_array[index])
		{
			free_partial_env(env_array, index);
			return (NULL);
		}
		lst_env = lst_env->next;
		index++;
	}
	return (env_array);
}
