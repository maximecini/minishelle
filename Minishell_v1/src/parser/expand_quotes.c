/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:37:26 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/29 15:19:59 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * Remplace la première occurrence d'une variable (ex: $VAR) dans une chaîne
 * par sa valeur donnée.
 * @param input       La chaîne d'entrée où chercher la variable
 * @param var_name    Le nom de la variable à remplacer (sans le '$')
 * @param var_value   La valeur à utiliser pour remplacer (ou "" si NULL)
 * @return Une nouvelle chaîne avec la variable remplacée,
	ou NULL en cas d'erreur.
 * Note : la mémoire retournée doit être libérée par l'appelant.
 */
char	*replace_variable_in_string(char *input, char *var_name, char *value)
{
	char	*search_token;
	char	*result;

	search_token = malloc(ft_strlen(var_name) + 2);
	if (!search_token)
		return (NULL);
	ft_strcpy(search_token, "$");
	ft_strcat(search_token, var_name);
	if (!value)
		value = "";
	result = ft_replace_str(input, search_token, value);
	free(search_token);
	return (result);
}

/**
 * Détermine le contexte de citation (quotes) à une position donnée
 * dans une chaîne.Parcourt la chaîne de 0 jusqu'à `pos`

	* (exclu) et garde en mémoire si on est à l'intérieur de quotes simples doubles.
 * - Si à la position `pos`, on est dans des quotes simples → retourne 1
 * - Si dans des quotes doubles → retourne 2
 * - Sinon → retourne
 * @param str   La chaîne d'entrée à analyser.
 * @param pos   La position dans la chaîne à examiner.
 * @return      1 si à l'intérieur de quotes simples,
 *              2 si à l'intérieur de quotes doubles,
 *              0 sinon.
 */
int	get_quote_context(char *str, int pos)
{
	int	i;
	int	in_single;
	int	in_double;

	i = 0;
	in_single = 0;
	in_double = 0;
	while (i < pos)
	{
		if (str[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (str[i] == '"' && !in_single)
			in_double = !in_double;
		i++;
	}
	if (in_single)
		return (1);
	else if (in_double)
		return (2);
	return (0);
}
