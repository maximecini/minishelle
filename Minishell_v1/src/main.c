/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:07:31 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/08/01 12:46:25 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	g_last_status = 0;

int	is_authorized_char(char c)
{
	return ((c >= 32 && c <= 126) || c == '\n' || c == '\t' || c == '\r');
}

int	handle_line(char *line, t_element **lst_cmd, t_element **lst_env)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_authorized_char(line[i]))
			return (printf("Syntax error: unauthorized character \n"), (1));
		i++;
	}
	if (has_syntax_error(line) || is_point(line))
		return ((2));
	if (!build_command_list(line, lst_cmd))
	{
		free(line);
		free_list(*lst_cmd);
		*lst_cmd = NULL;
		return (0);
	}
	expand(*lst_cmd, lst_env);
	execution(*lst_cmd, lst_env);
	ft_lstclear(lst_cmd, free_node_cmd_content);
	free(line);
	return (0);
}

int	minishell(char **env, t_element *lst_cmd, t_element *lst_env)
{
	char	*line;
	int		result;

	lst_cmd = NULL;
	lst_env = NULL;
	(signal(SIGQUIT, SIG_IGN), signal(SIGINT, handle_sigint_parent));
	if (env && *env)
		cpy_tab_to_lst(&lst_env, env);
	while (1)
	{
		line = readline("Minishell$ ");
		if (!line)
		{
			if (isatty(STDIN_FILENO))
				ft_printf("exit\n");
			break ;
		}
		if (ft_strlen(line))
			add_history(line);
		result = handle_line(line, &lst_cmd, &lst_env);
		if (result)
			break ;
	}
	return (free(line), ft_lstclear(&lst_env, free_node_env_content), result);
}

int	main(int ac, char **av, char **env)
{
	t_element	*lst_cmd;
	t_element	*lst_env;

	(void)ac;
	(void)av;
	lst_cmd = NULL;
	lst_env = NULL;
	return (minishell(env, lst_cmd, lst_cmd));
}
