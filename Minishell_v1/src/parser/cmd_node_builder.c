/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_node_builder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:16:41 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 19:24:42 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_element	*add_node(char **split_command, t_element **node_lst,
		t_redirect *redirect, int nb_redirect)
{
	t_node_cmd	*cmd_struct;
	t_element	*new_node;

	cmd_struct = malloc(sizeof(t_node_cmd));
	if (!cmd_struct)
		return (NULL);
	cmd_struct->cmd = split_command;
	cmd_struct->redirect = redirect;
	cmd_struct->nb_redirect = nb_redirect;
	new_node = ft_lstnew(cmd_struct);
	if (!new_node)
	{
		free(cmd_struct);
		return (NULL);
	}
	ft_lstadd_back(node_lst, new_node);
	return (new_node);
}

int	create_command_node(char *cmd, t_element **node_lst, int nb_redirect,
		t_redirect *redirect)
{
	char		**split_cmd;
	t_element	*lst;

	lst = NULL;
	split_cmd = split_smart(cmd, ' ');
	if (!split_cmd)
		return (0);
	lst = add_node(split_cmd, node_lst, redirect, nb_redirect);
	if (!lst)
		return (0);
	return (1);
}

char	*clean_line(const char *line, int s_quote, int d_quote,
		size_t write_index)
{
	char		*clean_line;
	size_t		line_len;
	size_t		i;
	t_char_copy	copy;

	line_len = ft_strlen(line);
	clean_line = malloc(line_len + 1);
	if (!clean_line)
		return (NULL);
	i = 0;
	copy.write_index = write_index;
	while (line[i])
	{
		update_quote_state(line[i], &s_quote, &d_quote);
		if (!s_quote && !d_quote && is_redirection_to_skip(line, &i))
			continue ;
		copy.read_index = i;
		copy.in_quotes = (s_quote || d_quote);
		append_char_preserve_quotes(clean_line, line, &copy);
		i++;
	}
	if (copy.write_index > 0 && clean_line[copy.write_index - 1] == ' ')
		copy.write_index--;
	clean_line[copy.write_index] = '\0';
	return (clean_line);
}
