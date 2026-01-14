/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:04:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 19:30:43 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	expand_all_variables_in_arg(char **arg, t_element **lst_env)
{
	char	*temp;
	int		pos;
	int		quote_context;

	temp = *arg;
	while (ft_strchr(temp, '$'))
	{
		temp = ft_strchr(temp, '$');
		pos = temp - *arg;
		quote_context = get_quote_context(*arg, pos);
		if (quote_context == 1 || temp[1] == '\0' || ft_strchr("\"': \t\n",
				temp[1]))
		{
			temp++;
			continue ;
		}
		if (!process_single_expansion(arg, &temp, lst_env))
			temp++;
	}
	return (0);
}

static int	post_process_argument(char **arg)
{
	char	*old_arg;

	old_arg = *arg;
	*arg = sanitize_word_quotes(*arg, ft_strlen(*arg));
	if (!*arg)
		return (-1);
	free(old_arg);
	return (0);
}

static int	process_single_argument(char **arg, t_element **lst_env)
{
	if (expand_all_variables_in_arg(arg, lst_env) == -1)
		return (-1);
	if (post_process_argument(arg) == -1)
		return (-1);
	return (0);
}

static int	process_command_arguments(t_node_cmd *node_cmd, t_element **lst_env)
{
	int	i;
	int	argc;
	int	shift_count;

	i = 0;
	while (node_cmd->cmd[i])
	{
		if (process_single_argument(&node_cmd->cmd[i], lst_env) == -1)
			return (-1);
		i++;
	}
	argc = i;
	i = 0;
	while (i < argc)
	{
		if (node_cmd->cmd[i] && node_cmd->cmd[i][0] == '\0')
		{
			free(node_cmd->cmd[i]);
			shift_count = 1;
			ft_shift_argv(&argc, &node_cmd->cmd[i], shift_count);
		}
		else
			i++;
	}
	return (0);
}

int	expand(t_element *lst_cmd, t_element **lst_env)
{
	t_node_cmd	*node_cmd;

	while (lst_cmd)
	{
		node_cmd = (t_node_cmd *)lst_cmd->content;
		if (process_command_arguments(node_cmd, lst_env) == -1)
			return (-1);
		lst_cmd = lst_cmd->next;
	}
	return (0);
}
