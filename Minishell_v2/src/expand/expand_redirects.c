/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:05:12 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 15:53:25 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static int	has_unquoted_whitespace(char *str)
{
	int	in_single;
	int	in_double;
	int	i;

	if (!str)
		return (0);
	in_single = 0;
	in_double = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (str[i] == '"' && !in_single)
			in_double = !in_double;
		else if (!in_single && !in_double && ft_is_whitespace(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	redirect_is_ambiguous(char *raw, char *expanded, int quoted)
{
	if (quoted)
		return (0);
	if (!expanded[0] || has_unquoted_whitespace(expanded))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(raw, 2);
		ft_putendl_fd(": ambiguous redirect", 2);
		return (1);
	}
	return (0);
}

static int	expand_single_redirect_file(char **file, t_list *lst_env)
{
	char	*expanded;
	int		quoted;

	if (!file || !*file)
		return (0);
	quoted = has_quotes(*file);
	expanded = expand_string(*file, lst_env);
	if (!expanded)
		return (-1);
	if (redirect_is_ambiguous(*file, expanded, quoted))
	{
		free(expanded);
		free(*file);
		*file = NULL;
		return (-1);
	}
	free(*file);
	*file = expanded;
	return (0);
}

int	expand_redirections(t_cmd *node_cmd, t_list *lst_env)
{
	int	i;

	if (!node_cmd || !node_cmd->redirect)
		return (0);
	i = 0;
	while (i < node_cmd->nb_redirect)
	{
		if (expand_single_redirect_file(&node_cmd->redirect[i].files,
				lst_env) == -1)
			return (-1);
		i++;
	}
	return (0);
}
