/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:24:48 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/08/01 12:22:39 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	cleanup_resources(t_element **node_lst, char *new_line,
		char **nodes)
{
	free_list(*node_lst);
	free(new_line);
	ft_free_split(nodes);
}

static char	**validate_and_split_line(char *line, char **new_line)
{
	char	**nodes;

	*new_line = process_quotes(line);
	if (!*new_line)
		return (NULL);
	nodes = split_smart(*new_line, '|');
	if (!nodes)
		return (free(*new_line), (NULL));
	return (nodes);
}

static int	process_single_node(char *node, t_element **node_lst)
{
	t_redirect	*redirect;
	char		*cmd;
	int			count;

	if (str_is_space(node))
		return (0);
	redirect = check_redirect(node, &count);
	if (redirect && !redirect->filename)
		return (0);
	if (redirect == NULL && count > 0)
		return (0);
	cmd = clean_line(node, 0, 0, 0);
	if (!cmd)
		return (0);
	if (!create_command_node(cmd, node_lst, count, redirect))
	{
		free(cmd);
		return (0);
	}
	free(cmd);
	return (1);
}

// Fonction principale refactorisée
t_element	*build_command_list(char *line, t_element **node_lst)
{
	char	**nodes;
	char	*new_line;
	int		i;

	if (!line)
		return (NULL);
	nodes = validate_and_split_line(line, &new_line);
	if (!nodes)
		return (*node_lst);
	i = 0;
	while (nodes[i])
	{
		if (!process_single_node(nodes[i], node_lst))
			return (cleanup_resources(node_lst, new_line, nodes), (NULL));
		i++;
	}
	ft_free_split(nodes);
	free(new_line);
	return (*node_lst);
}
