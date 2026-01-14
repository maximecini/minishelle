/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 00:00:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/10/16 15:04:12 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/function.h"

/*
** Vérifie si un argument est un flag -n valide
** Le flag -n peut être répété : -n, -nn, -nnn, -nnnnnn, etc.
** Si l'argument était quoté, ce n'est pas un flag
** Retourne 1 si c'est un flag -n valide, 0 sinon
*/
static int	is_n_flag(char *arg)
{
	int	i;

	if (!arg || arg[0] != '-')
		return (0);
	if (arg[1] != 'n')
		return (0);
	i = 1;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

/*
** Fonction builtin echo
** Affiche les arguments séparés par des espaces
** Option -n : supprime le saut de ligne final
** L'option -n peut être répétée plusieurs fois (ex: echo -n -nnn -nn hello)
** Retourne toujours 0 (succès)
*/
int	echo(t_cmd *node_cmd)
{
	int	i;
	int	newline;
	int	fd;

	if (!node_cmd || !node_cmd->cmd)
		return (0);
	newline = 1;
	i = 0;
	fd = STDOUT_FILENO;
	while (node_cmd->cmd[i++])
	{
		if (!is_n_flag(node_cmd->cmd[i]))
			break ;
		newline = 0;
	}
	while (node_cmd->cmd[i])
	{
		ft_putstr_fd(node_cmd->cmd[i], fd);
		if (node_cmd->cmd[i + 1])
			ft_putstr_fd(" ", fd);
		i++;
	}
	if (newline)
		ft_putstr_fd("\n", fd);
	return (0);
}
