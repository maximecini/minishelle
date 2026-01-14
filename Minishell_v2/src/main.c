/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:00:51 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/17 14:05:53 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int			g_last_status = 0;

static void	setup_interactive_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ctrl_c_handler);
}

int	minishell(t_list *lst_token, t_list *lst_env, char **tab, char **env)
{
	t_list	*lst_cmd;

	lst_cmd = NULL;
	init_env(&lst_env, env);
	setup_interactive_signals();
	if (!process_shell_loop(&lst_token, &lst_cmd, &tab, &lst_env))
	{
		rl_clear_history();
		ft_lstclear(&lst_env, free_node_env_content);
		return (0);
	}
	rl_clear_history();
	ft_lstclear(&lst_env, free_node_env_content);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_list	*lst_token;
	t_list	*lst_env;
	char	**tab;

	if (isatty(0) == 0 || isatty(1) == 0)
	{
		write(1, "CANONT PIPE A MINISHER\n", 23);
		return (0);
	}
	(void)ac;
	(void)av;
	lst_token = NULL;
	lst_env = NULL;
	tab = NULL;
	minishell(lst_token, lst_env, tab, env);
	return (0);
}
