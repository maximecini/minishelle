/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_str_replace_substring.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:45:09 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/26 18:49:14 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Vérifie que les paramètres pour un remplacement de sous-chaîne
** sont valides.
**
** Paramètres :
**   - str    : chaîne source
**   - search : sous-chaîne à remplacer
**   - replace: sous-chaîne de remplacement
**
** Retour :
**   - 1 si les paramètres sont valides, 0 sinon
*/
static int	validate_str_params(char *str, char *search, char *replace)
{
	if (!str || !search || !replace)
		return (0);
	if (ft_strlen(search) == 0)
		return (0);
	return (1);
}

/*
** Compte le nombre d’occurrences d’une sous-chaîne dans une chaîne.
**
** Paramètres :
**   - str    : chaîne source
**   - search : sous-chaîne à chercher
**
** Retour :
**   - nombre d’occurrences trouvées
*/
static size_t	count_str_occurrences(char *str, char *search)
{
	size_t	count;
	size_t	search_len;
	char	*temp;

	count = 0;
	search_len = ft_strlen(search);
	temp = str;
	while (*temp)
	{
		if (!ft_strncmp(temp, search, search_len))
		{
			count++;
			temp += search_len;
		}
		else
			temp++;
	}
	return (count);
}

/*
** Calcule la nouvelle longueur d’une chaîne après remplacement
** d’une sous-chaîne par une autre.
**
** Paramètres :
**   - str    : chaîne source
**   - search : sous-chaîne à remplacer
**   - replace: sous-chaîne de remplacement
**
** Retour :
**   - longueur de la nouvelle chaîne (sans le '\0')
*/
static size_t	calculate_str_new_length(char *str, char *search, char *replace)
{
	size_t	str_len;
	size_t	search_len;
	size_t	replace_len;
	size_t	nb_occurence;
	size_t	new_len;

	str_len = ft_strlen(str);
	search_len = ft_strlen(search);
	replace_len = ft_strlen(replace);
	nb_occurence = count_str_occurrences(str, search);
	new_len = str_len - (search_len * nb_occurence) + (replace_len
			* nb_occurence);
	return (new_len);
}

/*
** Remplace toutes les occurrences d’une sous-chaîne dans `str`
** par une autre sous-chaîne, et écrit le résultat dans `new_str`.
**
** Paramètres :
**   - new_str: buffer où écrire la nouvelle chaîne (pré-alloué)
**   - str    : chaîne source
**   - search : sous-chaîne à remplacer
**   - replace: sous-chaîne de remplacement
**
** Retour :
**   - rien (le résultat est écrit dans `new_str`)
*/
static void	perform_str_replacement(char *new_str, char *str, char *search,
		char *replace)
{
	size_t	search_len;
	size_t	replace_len;
	char	*res;
	char	*temp_str;

	search_len = ft_strlen(search);
	replace_len = ft_strlen(replace);
	res = new_str;
	temp_str = str;
	while (*temp_str)
	{
		if (!ft_strncmp(temp_str, search, search_len))
		{
			ft_memcpy(res, replace, replace_len);
			res += replace_len;
			temp_str += search_len;
		}
		else
			*res++ = *temp_str++;
	}
	*res = '\0';
}

/*
** Fonction principale : remplace toutes les occurrences
** d’une sous-chaîne par une autre. Alloue une nouvelle chaîne.
**
** Paramètres :
**   - str    : chaîne source
**   - search : sous-chaîne à remplacer
**   - replace: sous-chaîne de remplacement
**
** Retour :
**   - nouvelle chaîne allouée (à libérer par l’appelant),
	ou NULL en cas d’erreur
*/
char	*ft_replace_str(char *str, char *search, char *replace)
{
	char	*new_str;
	size_t	new_str_len;

	if (!validate_str_params(str, search, replace))
		return (NULL);
	new_str_len = calculate_str_new_length(str, search, replace);
	new_str = malloc((new_str_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	perform_str_replacement(new_str, str, search, replace);
	return (new_str);
}
