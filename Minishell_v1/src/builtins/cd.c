/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:55:07 by thodavid          #+#    #+#             */
/*   Updated: 2025/07/31 19:38:17 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

int	cd(char **args, t_element **lst_env)
{
	char	*oldpwd;
	char	*pwd;
	int		argc;

	argc = 0;
	while (args[argc])
		argc++;
	if (argc > 2)
		return (ft_putendl_fd("minishell: cd: too many arguments", 2), (1));
	oldpwd = getcwd(NULL, 0);
	if (oldpwd == NULL)
		return (chdir("/home"), (perror("cd"), 0));
	update_nodes_env(*lst_env, "OLDPWD", oldpwd, "=");
	if (!args[1] || !ft_strcmp(args[1], "~"))
		chdir("/home");
	else if (chdir(args[1]) != 0)
		return (perror("cd"), (1));
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (perror("cd"), free(oldpwd), (1));
	update_nodes_env(*lst_env, "PWD", pwd, "=");
	free(oldpwd);
	free(pwd);
	return (0);
}
