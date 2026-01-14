/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:11:59 by thodavid          #+#    #+#             */
/*   Updated: 2025/07/31 14:53:48 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

int	pwd(void)
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
