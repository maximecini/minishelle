/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bultin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:05:34 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/26 21:05:48 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	builtin_error(char *builtin, char *message, char *token)
{
	ft_putstr_fd("minishell: ", 2);
	if (builtin)
		ft_putstr_fd(builtin, 2);
	else
		ft_putstr_fd("unknown_builtin", 2);
	ft_putstr_fd(": ", 2);
	if (message)
		ft_putstr_fd(message, 2);
	else
		ft_putstr_fd("error", 2);
	if (token)
	{
		ft_putstr_fd(" `", 2);
		ft_putstr_fd(token, 2);
		ft_putstr_fd("`", 2);
	}
	ft_putendl_fd("", 2);
	return (1);
}
