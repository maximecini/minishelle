/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_word.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:40:02 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 19:23:10 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Ajoute un caractère depuis `src` à `dst` à la position indiquée,
** en préservant tous les espaces quand on est à l'intérieur de guillemets.
**
** Paramètres :
**  - dst   : chaîne destination modifiable
**  - src   : chaîne source en lecture
**  - copy  : pointeur vers la structure contenant les index et l'état des quotes
*/
void	append_char_preserve_quotes(char *dst, const char *src,
		t_char_copy *copy)
{
	if (src[copy->read_index] == ' ')
	{
		if (copy->in_quotes)
			dst[copy->write_index++] = ' ';
		else if (copy->write_index > 0 && dst[copy->write_index - 1] != ' ')
			dst[copy->write_index++] = ' ';
	}
	else
		dst[copy->write_index++] = src[copy->read_index];
}

/*
** Calcule la longueur du mot à extraire dans la chaîne `str`.
** Un mot est délimité par un séparateur (espace ou fin de chaîne),
** sauf si ce séparateur est à l'intérieur de quotes simples ou doubles.
**
** Paramètre :
**  - str : chaîne source
**
** Retour :
**  - longueur du mot trouvé
*/
static size_t	get_word_length(const char *str)
{
	size_t	i;
	int		in_single;
	int		in_double;

	i = 0;
	in_single = 0;
	in_double = 0;
	while (str[i])
	{
		update_quote_state(str[i], &in_single, &in_double);
		if (!in_single && !in_double && is_sep(str[i]))
			break ;
		i++;
	}
	return (i);
}

/*
** Alloue la mémoire pour le mot et initialise l'état des quotes.
**
** Paramètres :
**  - len   : longueur du mot à allouer
**  - state : pointeur vers la structure d'état des quotes
**
** Retour :
**  - pointeur vers la mémoire allouée, ou NULL si échec
*/
static char	*allocate_and_init(size_t len, t_quote_state *state)
{
	char	*word;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	init_quote_state(state);
	return (word);
}

/*
** Copie un mot de longueur `len` depuis `str` dans une nouvelle chaîne.
** Supprime les quotes simples et doubles en respectant leur contexte
** (n'enlève que les quotes délimitant réellement une zone protégée).
**
** Paramètres :
**  - str : chaîne source
**  - len : longueur du mot à copier
**
** Retour :
**  - nouvelle chaîne allouée contenant le mot "nettoyé", ou NULL si échec
*/
char	*sanitize_word_quotes(const char *str, size_t len)
{
	char			*word;
	t_quote_state	state;

	word = allocate_and_init(len, &state);
	if (!word)
		return (NULL);
	while (state.src_idx < len)
	{
		if (is_quote_to_skip(str[state.src_idx], state.in_single,
				state.in_double))
		{
			process_quote_to_skip(str, &state);
			continue ;
		}
		process_normal_char(str, word, &state);
	}
	word[state.dst_idx] = '\0';
	return (word);
}

/*
** Extrait un mot de la chaîne `str`.
** Utilise `get_word_length` pour déterminer la longueur,
** puis `sanitize_word_quotes` pour obtenir le mot nettoyé.
**
** Paramètre :
**  - str : chaîne source
**
** Retour :
**  - nouvelle chaîne allouée contenant le mot, ou NULL si erreur
*/
char	*extract_word(const char *str)
{
	size_t	word_len;
	char	*word;

	if (!str)
		return (NULL);
	word_len = get_word_length(str);
	if (!word_len)
		return (NULL);
	word = sanitize_word_quotes(str, word_len);
	return (word);
}
