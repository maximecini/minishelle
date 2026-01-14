/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:46:51 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 15:08:32 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/function.h"

static char	*get_env_var(t_list *lst_env, char *key)
{
	t_env	*env;

	while (lst_env)
	{
		env = (t_env *)lst_env->content;
		if (env && env->key && !ft_strcmp(env->key, key))
			return (env->value);
		lst_env = lst_env->next;
	}
	return (NULL);
}

static int	validate_cd_args(char **args)
{
	if (args[1] && args[1][0] == '-' && args[1][1] == '-' && args[1][2])
	{
		ft_putstr_fd("bash: cd: --", 2);
		ft_putendl_fd(": invalid option", 2);
		ft_putendl_fd("cd: usage: cd [-L|[-P [-e]] [-@]] [dir]", 2);
		return (2);
	}
	if (args[1] && args[2])
	{
		ft_putendl_fd("minishell: cd: too many arguments", 2);
		return (1);
	}
	return (0);
}

static int	change_directory(char **args, t_list **lst_env, char *oldpwd)
{
	char	*target;

	if (args[1] && !ft_strcmp(args[1], "-"))
	{
		target = get_env_var(*lst_env, "OLDPWD");
		if (!target)
		{
			ft_putendl_fd("bash: cd: OLDPWD not set", 2);
			return (free(oldpwd), 1);
		}
		if (chdir(target) != 0)
			return (perror("cd"), free(oldpwd), 1);
		printf("%s\n", target);
	}
	else if (!args[1] || !ft_strcmp(args[1], "~") || !ft_strcmp(args[1], "--"))
		chdir("/home");
	else if (chdir(args[1]) != 0)
		return (perror("cd"), free(oldpwd), 1);
	return (0);
}

static int	update_pwd_variables(t_list **lst_env, char *oldpwd)
{
	char	*pwd;

	update_nodes_env(*lst_env, "OLDPWD", oldpwd, "=");
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (perror("cd"), free(oldpwd), 1);
	update_nodes_env(*lst_env, "PWD", pwd, "=");
	free(oldpwd);
	free(pwd);
	return (0);
}

int	cd(char **args, t_list **lst_env)
{
	char	*oldpwd;
	int		status;
	int		validation;

	validation = validate_cd_args(args);
	if (validation)
		return (validation);
	oldpwd = getcwd(NULL, 0);
	if (oldpwd == NULL)
		return (chdir("/home"), (perror("cd"), 0));
	status = change_directory(args, lst_env, oldpwd);
	if (status)
		return (status);
	return (update_pwd_variables(lst_env, oldpwd));
}
