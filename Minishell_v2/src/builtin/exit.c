/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:05:53 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/10/16 15:03:06 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/function.h"

static int	is_numeric_argument(char *arg)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
			sign = -1;
		i++;
	}
	if (!arg[i])
		return (0);
	return (is_numeric_body_valid(&arg[i], sign));
}

static void	print_exit_numeric_error(char *arg)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
}

static int	handle_exit_arguments(t_cmd *node_cmd, int *should_exit)
{
	char	*arg;
	int		exit_code;
	int		argc;

	*should_exit = 1;
	arg = node_cmd->cmd[1];
	if (!is_numeric_argument(arg))
	{
		print_exit_numeric_error(arg);
		*should_exit = 1;
		return (2);
	}
	argc = node_cmd->cmd_count;
	if (argc > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		*should_exit = 0;
		return (1);
	}
	exit_code = ft_atoi(arg);
	return (exit_code & 0xFF);
}

int	exit_builtin(t_cmd *node_cmd, t_list **lst_env, t_list **lst_cmd)
{
	int	should_exit;
	int	exit_code;

	(void)lst_env;
	(void)lst_cmd;
	if (node_cmd->cmd[1])
	{
		exit_code = handle_exit_arguments(node_cmd, &should_exit);
		if (!should_exit)
			return (-1000 - exit_code);
		return (exit_code);
	}
	return (0);
}
