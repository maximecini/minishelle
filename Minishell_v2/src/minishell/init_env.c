/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:00:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 14:53:40 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	if_print_exit(void)
{
	if (isatty(STDIN_FILENO))
		printf("exit\n");
	return (1);
}

static void	add_uid_if_missing(t_list **lst_env)
{
	char	*uid_str;
	char	*uid_var;

	if (get_lst_key(lst_env, "UID"))
		return ;
	uid_str = ft_itoa(getuid());
	if (!uid_str)
		return ;
	uid_var = ft_strjoin("UID=", uid_str, 0, 1);
	if (uid_var)
	{
		add_back_nodes_env(lst_env, uid_var, 0);
		free(uid_var);
	}
}

static void	add_default_path(t_list **lst_env)
{
	if (get_lst_key(lst_env, "PATH"))
		return ;
	add_back_nodes_env(lst_env,
		"PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",
		0);
}

void	init_env(t_list **lst_env, char **env)
{
	if (env && *env)
		cpy_tab_to_lst(lst_env, env);
	add_uid_if_missing(lst_env);
	add_default_path(lst_env);
}
