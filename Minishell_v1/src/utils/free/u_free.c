/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 08:40:23 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/27 18:37:30 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_commands(char **commands)
{
	int	i;

	i = 0;
	if (!commands)
		return ;
	while (commands[i])
	{
		free(commands[i]);
		i++;
	}
	free(commands);
}

void	free_lst(t_element **lst_env, t_element **lst_cmd)
{
	ft_lstclear(lst_cmd, free_node_cmd_content);
	ft_lstclear(lst_env, free_node_env_content);
}
