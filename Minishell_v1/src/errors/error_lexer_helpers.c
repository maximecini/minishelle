/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_lexer_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:32:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 19:36:28 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Initialise l'état du parsing des erreurs de syntaxe.
**
** Paramètre :
**  - state : pointeur vers la structure d'état
*/
void	init_syntax_state(t_syntax_state *state)
{
	state->index = 0;
	state->in_single_quote = 0;
	state->in_double_quote = 0;
}

/*
** Vérifie si le caractère actuel doit être ignoré (quotes ou espaces).
**
** Paramètres :
**  - input : chaîne d'entrée
**  - state : pointeur vers la structure d'état
**
** Retour :
**  - 1 si le caractère doit être ignoré, 0 sinon
*/
int	should_skip_char(char *input, t_syntax_state *state)
{
	update_quote_state(input[state->index], &state->in_single_quote,
		&state->in_double_quote);
	if (input[state->index] == '\'' || input[state->index] == '"')
		return (1);
	if (state->in_single_quote || state->in_double_quote)
		return (1);
	if (input[state->index] == ' ' || (input[state->index] >= 9
			&& input[state->index] <= 13))
		return (1);
	return (0);
}

/*
** Traite un token trouvé et vérifie s'il est valide.
**
** Paramètres :
**  - input : chaîne d'entrée
**  - state : pointeur vers la structure d'état
**
** Retour :
**  - 1 si une erreur de syntaxe est détectée, 0 sinon
*/
int	process_token(char *input, t_syntax_state *state)
{
	char	*current_token;
	int		current_token_len;

	current_token = identify_operator(input, state->index);
	if (!current_token)
	{
		state->index++;
		return (0);
	}
	current_token_len = ft_strlen(current_token);
	if (is_operator_invalid(input, state->index, current_token,
			current_token_len))
		return (1);
	state->index += current_token_len;
	return (0);
}
