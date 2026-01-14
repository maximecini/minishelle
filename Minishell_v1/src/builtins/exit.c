/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:05:53 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 14:49:58 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <unistd.h>

static int	is_numeric_argument(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	print_exit_numeric_error(char *arg)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
}

static int	handle_exit_arguments(t_node_cmd *node_cmd)
{
	char	*arg;
	int		exit_code;

	arg = node_cmd->cmd[1];
	if (!is_numeric_argument(arg))
	{
		print_exit_numeric_error(arg);
		return (2);
	}
	if (node_cmd->cmd[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	exit_code = ft_atoi(arg);
	return (exit_code & 0xFF);
}

int	exit_builtin(t_node_cmd *node_cmd, t_element **lst_env, t_element **lst_cmd)
{
	(void)lst_env;
	(void)lst_cmd;
	ft_putstr_fd("exit\n", 2);
	if (node_cmd->cmd[1])
		return (handle_exit_arguments(node_cmd));
	return (0);
}
