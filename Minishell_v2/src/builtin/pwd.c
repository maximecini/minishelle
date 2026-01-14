/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:47:20 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 15:11:58 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/function.h"

static int	validate_pwd_options(t_cmd *node_cmd)
{
	int		i;

	if (!node_cmd || !node_cmd->cmd)
		return (0);
	i = 1;
	while (node_cmd->cmd[i])
	{
		if (node_cmd->cmd[i][0] == '-' && node_cmd->cmd[i][1])
		{
			ft_putstr_fd("bash: pwd: ", 2);
			ft_putstr_fd(node_cmd->cmd[i], 2);
			ft_putendl_fd(": invalid option", 2);
			ft_putendl_fd("pwd: usage: pwd [-LP]", 2);
			return (2);
		}
		i++;
	}
	return (0);
}

static int	print_current_directory(void)
{
	char	*path;

	path = NULL;
	path = getcwd(path, 1024);
	if (path)
	{
		printf("%s\n", path);
		free(path);
		return (0);
	}
	free(path);
	return (1);
}

int	pwd(t_cmd *node_cmd)
{
	int	status;

	status = validate_pwd_options(node_cmd);
	if (status)
		return (status);
	return (print_current_directory());
}
