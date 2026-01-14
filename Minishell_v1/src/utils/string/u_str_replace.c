/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_str_replace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:44:26 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/26 18:49:24 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Fonction pour compter le nombre d’occurrences d’un caractère
** donné dans une chaîne de caractères.
**
** Paramètres :
**   - str    : chaîne de caractères à parcourir (doit être non-NULL)
**   - search : caractère à chercher dans la chaîne
**
** Retour :
**   - nombre d’occurrences de `search` dans `str`
*/
static size_t	count_char_occurrences(char *str, char search)
{
	size_t	count;
	char	*temp;

	count = 0;
	temp = str;
	while (*temp)
	{
		if (*temp == search)
			count++;
		temp++;
	}
	return (count);
}

/*
** Calcule la nouvelle longueur d’une chaîne après remplacement
** d’un caractère par une chaîne donnée.
**
** Paramètres :
**   - str    : chaîne d’entrée
**   - search : caractère à remplacer
**   - replace: chaîne de remplacement
**
** Retour :
**   - longueur de la nouvelle chaîne (sans le '\0')
*/
static size_t	calculate_char_new_length(char *str, char search, char *replace)
{
	size_t	str_len;
	size_t	replace_len;
	size_t	nb_occurence;
	size_t	new_len;

	str_len = ft_strlen(str);
	replace_len = ft_strlen(replace);
	nb_occurence = count_char_occurrences(str, search);
	new_len = str_len - nb_occurence + (replace_len * nb_occurence);
	return (new_len);
}

/*
** Remplace toutes les occurrences d’un caractère dans `str`
** par la chaîne `replace`, et écrit le résultat dans `new_str`.
**
** Paramètres :
**   - new_str: buffer où écrire la nouvelle chaîne (pré-alloué)
**   - str    : chaîne source
**   - search : caractère à remplacer
**   - replace: chaîne de remplacement
**
** Retour :
**   - rien (le résultat est écrit dans `new_str`)
*/
static void	perform_char_replacement(char *new_str, char *str, char search,
		char *replace)
{
	size_t	replace_len;
	char	*res;
	char	*temp_str;

	replace_len = ft_strlen(replace);
	res = new_str;
	temp_str = str;
	while (*temp_str)
	{
		if (*temp_str == search)
		{
			ft_memcpy(res, replace, replace_len);
			res += replace_len;
			temp_str++;
		}
		else
			*res++ = *temp_str++;
	}
	*res = '\0';
}

/*
** Fonction principale : remplace toutes les occurrences
** d’un caractère par une chaîne donnée. Alloue une nouvelle chaîne.
**
** Paramètres :
**   - str    : chaîne source
**   - search : caractère à remplacer
**   - replace: chaîne de remplacement
**
** Retour :
**   - nouvelle chaîne allouée (à libérer par l’appelant),
	ou NULL en cas d’erreur
*/
char	*ft_replace_char(char *str, char search, char *replace)
{
	char	*new_str;
	size_t	new_str_len;

	if (!str || !replace)
		return (NULL);
	new_str_len = calculate_char_new_length(str, search, replace);
	new_str = malloc((new_str_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	perform_char_replacement(new_str, str, search, replace);
	return (new_str);
}

/*
** Wrapper : choisit automatiquement entre remplacement
** de caractère unique ou de sous-chaîne, selon la longueur de `search`.
**
** Paramètres :
**   - str    : chaîne source
**   - search : caractère ou sous-chaîne à remplacer
**   - replace: chaîne de remplacement
**
** Retour :
**   - nouvelle chaîne allouée (à libérer par l’appelant),
	ou NULL en cas d’erreur
*/
char	*ft_replace_auto(char *str, char *search, char *replace)
{
	if (!str || !search || !replace)
		return (NULL);
	if (ft_strlen(search) == 1)
		return (ft_replace_char(str, search[0], replace));
	return (ft_replace_str(str, search, replace));
}
