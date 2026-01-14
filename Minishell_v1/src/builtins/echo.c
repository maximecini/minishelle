/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:02:30 by thodavid          #+#    #+#             */
/*   Updated: 2025/07/31 18:14:32 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

int	is_flag(char *s)
{
	int	i;

	i = 0;
	if (s[i] != '-')
		return (0);
	i++;
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	is_flag_n(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (str == NULL || *str == '\0' || ft_strlen(str) < 2)
		return (0);
	else if (is_flag(str))
		return (1);
	else
		return (0);
}

int	echo(t_node_cmd *node_cmd)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	while (node_cmd->cmd[i] && is_flag_n(node_cmd->cmd[i]))
	{
		newline = 0;
		i++;
	}
	while (node_cmd->cmd[i])
	{
		printf("%s", node_cmd->cmd[i]);
		if (node_cmd->cmd[i + 1])
			printf(" ");
		i++;
	}
	if (newline)
		printf("\n");
	return (0);
}
