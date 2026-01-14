/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:19:40 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:19:24 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

t_token	redir_type(int token_type, char *type, char *value, int *skip_next)
{
	t_token	token;
	int		len_type;

	len_type = ft_strlen(type);
	token.type = token_type;
	*skip_next = 0;
	if ((len_type == 2 && (token_type == 3 || token_type == 4))
		|| (len_type == 1 && (token_type == 1 || token_type == 2)))
	{
		token.value = value;
		if (value != NULL)
			*skip_next = 1;
	}
	else
	{
		if (token_type == REDIR_APPEND || token_type == HEREDOC)
			token.value = type + 2;
		else
			token.value = type + 1;
	}
	return (token);
}

t_token	create_token(char *type, char *value, int *skip_next)
{
	t_token	token;

	*skip_next = 0;
	if (type == NULL)
	{
		token.type = EOL;
		token.value = NULL;
		return (token);
	}
	if (type[0] == '<' && type[1] == '<')
		return (redir_type(HEREDOC, type, value, skip_next));
	else if (type[0] == '>' && type[1] == '>')
		return (redir_type(REDIR_APPEND, type, value, skip_next));
	else if (type[0] == '<')
		return (redir_type(REDIR_IN, type, value, skip_next));
	else if (type[0] == '>')
		return (redir_type(REDIR_OUT, type, value, skip_next));
	else if (type[0] == '|')
		token.type = PIPE;
	else
		token.type = WORD;
	token.value = type;
	return (token);
}

static t_token	*create_special_token(char **tab, int *i)
{
	t_token	*token_ptr;

	token_ptr = malloc(sizeof(t_token));
	if (!token_ptr)
		return (NULL);
	token_ptr->value = tab[*i + 2];
	token_ptr->type = REDIR_OUT;
	*i += 2;
	return (token_ptr);
}

static t_token	*create_normal_token(char **tab, int i, int *skip_next)
{
	t_token	*token_ptr;

	token_ptr = malloc(sizeof(t_token));
	if (!token_ptr)
		return (NULL);
	*token_ptr = create_token(tab[i], tab[i + 1], skip_next);
	return (token_ptr);
}

int	create_list_token(t_list **lst_token, char **tab)
{
	int		i;
	int		skip_next;
	t_token	*token_ptr;

	i = 0;
	skip_next = 0;
	while (tab[i])
	{
		if (tab[i][0] == '>' && tab[i + 1] && tab[i + 1][0] == '|')
			token_ptr = create_special_token(tab, &i);
		else
			token_ptr = create_normal_token(tab, i, &skip_next);
		if (!token_ptr)
			return (ft_lstclear(lst_token, free_node_token_content), 0);
		if (!add_token_to_list(lst_token, token_ptr))
			return (0);
		if (skip_next)
			i += 2;
		else
			i++;
	}
	return (1);
}
