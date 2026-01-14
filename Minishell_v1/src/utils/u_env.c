/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:13:32 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/30 16:14:50 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * Extrait le nom d'une variable d'environnement dans une chaîne.
 * Recherche la première occurrence d'un '$' dans `str` et récupère
 * les caractères suivants qui forment un identifiant valide
 * (alphanumérique ou '_').
 * Exemple : "Hello $USER!" → renvoie "USER"
 * @param str    La chaîne d'entrée à analyser
 * @return Une chaîne allouée contenant le nom de la variable (sans le '$'),
 *			ou NULL si aucun nom de variable valide n'est trouvé.
 *			La mémoire retournée doit être libérée par l'appelant.
 */

char	*get_env_var_start(char *str)
{
	char	*dollar_pos;

	dollar_pos = ft_strchr(str, '$');
	if (!dollar_pos || !dollar_pos[1])
		return (NULL);
	return (dollar_pos + 1);
}

char	*extract_env_var_name_from(char *start)
{
	char	*result;
	int		name_len;
	int		k;

	name_len = 0;
	while (start[name_len])
	{
		if (is_whitespace(start[name_len]) || (!ft_isalnum(start[name_len])
				&& start[name_len] != '_'))
			break ;
		name_len++;
	}
	result = malloc(sizeof(char) * (name_len + 1));
	if (!result)
		return (NULL);
	k = 0;
	while (k < name_len)
	{
		result[k] = start[k];
		k++;
	}
	result[k] = '\0';
	return (result);
}

char	*extract_env_var_name(char *str)
{
	char	*start;

	start = get_env_var_start(str);
	if (!start)
		return (NULL);
	return (extract_env_var_name_from(start));
}

/*
** Extrait la valeur (partie après '=') d'une chaîne `s` de la forme "KEY=VALUE".
**
** Paramètre :
**  - s : chaîne à analyser
**
** Retour :
**  - chaîne dupliquée de la valeur (après '='),
	ou NULL si pas de '=' ou valeur vide
*/
char	*get_value(char *s)
{
	char	*value;

	if (!s)
		return (NULL);
	value = ft_strchr(s, '=');
	if (!value || !*(value + 1))
		return (NULL);
	return (ft_strdup(value + 1));
}

/*
** Extrait la clé (partie avant '=') d'une chaîne `s` de la forme "KEY=VALUE".
**
** Paramètre :
**  - s : chaîne à analyser
**
** Retour :
**  - nouvelle chaîne allouée contenant la clé,
	ou NULL en cas d’erreur ou absence de chaîne
*/
char	*get_key(char *s)
{
	int		i;
	char	*key;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	key = malloc(sizeof(char) * (i + 1));
	if (!key)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '=')
	{
		key[i] = s[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}
