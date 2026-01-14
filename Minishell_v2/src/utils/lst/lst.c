/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:47:33 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:47:36 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	process_word(t_cmd **node_cmd, int *index, char *word)
{
	(*node_cmd)->cmd[*index] = ft_strdup(word);
	(*index)++;
}

int	process_token_redirect(t_cmd **node_cmd, t_token *lst_token, int *j)

{
	int		should_expand;
	char	*cleaned_eof;

	if (!lst_token->value)
		return (0);
	if (!(*node_cmd)->redirect)
		return (1);
	(*node_cmd)->redirect[*j].type = lst_token->type;
	if (lst_token->type == HEREDOC)
	{
		(*node_cmd)->redirect[*j].is_heredoc = 1;
		cleaned_eof = remove_quotes_from_delimiter(lst_token->value,
				&should_expand);
		(*node_cmd)->redirect[*j].eof = cleaned_eof;
		(*node_cmd)->redirect[*j].expand_heredoc = should_expand;
		(*node_cmd)->redirect[*j].files = NULL;
	}
	else
		(*node_cmd)->redirect[*j].files = ft_strdup(lst_token->value);
	(*j)++;
	return (1);
}

int	count_redirect(t_list *lst_token)
{
	int		i;
	t_token	*tok;

	i = 0;
	while (lst_token && ((t_token *)lst_token->content)->type != PIPE)
	{
		tok = (t_token *)lst_token->content;
		if (is_redirection(tok->type))
		{
			i++;
			if (i > MAX_REDIRECTS)
			{
				ft_putstr_fd("minishell: maximum redirections exceeded\n", 2);
				return (-1);
			}
		}
		lst_token = lst_token->next;
	}
	return (i);
}

int	count_cmd_words(t_list *lst_token)
{
	int		i;
	t_token	*tok;

	i = 0;
	while (lst_token && ((t_token *)lst_token->content)->type != PIPE)
	{
		tok = (t_token *)lst_token->content;
		if (tok->type == WORD)
			i++;
		lst_token = lst_token->next;
	}
	return (i);
}

void	next_cmd_lst(t_list **lst_token)
{
	while (*lst_token && ((t_token *)(*lst_token)->content)->type != PIPE)
		*lst_token = (*lst_token)->next;
	if (*lst_token && ((t_token *)(*lst_token)->content)->type == PIPE)
		*lst_token = (*lst_token)->next;
}
