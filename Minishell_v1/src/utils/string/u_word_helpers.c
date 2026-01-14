/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_word_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:03:33 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 19:39:24 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Ajoute un caractère depuis `src` à `dst` à la position indiquée,
** en évitant d'insérer plusieurs espaces consécutifs.
**
** Paramètres :
**  - dst  : chaîne destination modifiable
**  - src  : chaîne source en lecture
**  - copy : pointeur vers la structure contenant les index
*/
void	append_char_once(char *dst, const char *src, t_char_copy *copy)
{
	if (src[copy->read_index] == ' ')
	{
		if (copy->write_index > 0 && dst[copy->write_index - 1] != ' ')
			dst[copy->write_index++] = ' ';
	}
	else
		dst[copy->write_index++] = src[copy->read_index];
}

/*
** Initialise l'état des variables pour le traitement des quotes.
**
** Paramètre :
**  - state : pointeur vers la structure d'état des quotes
*/
void	init_quote_state(t_quote_state *state)
{
	state->src_idx = 0;
	state->dst_idx = 0;
	state->in_single = 0;
	state->in_double = 0;
}

/*
** Traite un caractère quote à ignorer dans la sanitisation.
** Met à jour l'état des quotes et avance l'index source.
**
** Paramètres :
**  - str   : chaîne source
**  - state : pointeur vers la structure d'état des quotes
*/
void	process_quote_to_skip(const char *str, t_quote_state *state)
{
	update_quote_state(str[state->src_idx], &state->in_single,
		&state->in_double);
	state->src_idx++;
}

/*
** Traite un caractère normal dans la sanitisation.
** Met à jour l'état des quotes si nécessaire et copie le caractère.
**
** Paramètres :
**  - str   : chaîne source
**  - word  : chaîne destination
**  - state : pointeur vers la structure d'état des quotes
*/
void	process_normal_char(const char *str, char *word, t_quote_state *state)
{
	if (is_quote(str[state->src_idx]))
		update_quote_state(str[state->src_idx], &state->in_single,
			&state->in_double);
	word[state->dst_idx++] = str[state->src_idx++];
}

/*
** Vérifie si un caractère est une quote simple ou double.
**
** Paramètre :
**  - c : caractère à tester
**
** Retour :
**  - 1 si c est une quote simple ou double, 0 sinon
*/
int	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}
