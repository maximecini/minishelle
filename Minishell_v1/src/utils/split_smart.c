/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_smart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:55:43 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 13:48:28 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

/*
** Alloue un tableau de chaînes de caractères pour stocker
** les segments extraits, avec un espace pour un pointeur NULL final.
**
** Paramètre :
**   - max_size : nombre maximal d’éléments attendus
**
** Retour :
**   - pointeur vers le tableau alloué (initialisé à NULL),
**     ou NULL en cas d’échec d’allocation
*/
static char	**alloc_result_array(size_t max_size)
{
	char	**result;

	result = malloc(sizeof(char *) * (max_size + 1));
	if (!result)
		return (NULL);
	ft_bzero(result, sizeof(char *) * (max_size + 1));
	return (result);
}

/*
** Remplit le tableau `result` avec les segments extraits de `input`
** en séparant selon `sep` uniquement si ce séparateur est *hors* quotes.
** Les segments extraits sont trimés (espaces en début/fin supprimés).
**
** Paramètres :
**   - input  : chaîne source
**   - result : tableau de chaînes à remplir (doit être alloué)
**   - sep    : caractère séparateur
**
** Retour :
**   - nombre de segments extraits
*/
static int	fill_segments(const char *input, char **result, char sep)
{
	t_split_state	s;

	s.i = 0;
	s.start = 0;
	s.count = 0;
	s.sq = 0;
	s.dq = 0;
	while (input[s.i])
	{
		update_quote_state(input[s.i], &s.sq, &s.dq);
		if (is_unquoted(input[s.i], s.sq, s.dq, sep))
		{
			result[s.count] = copy_trimmed_segment(input, s.start, s.i);
			if (!result[s.count++])
				return (-1);
			s.start = s.i + 1;
		}
		s.i++;
	}
	result[s.count] = copy_trimmed_segment(input, s.start, s.i);
	if (!result[s.count])
		return (-1);
	result[++s.count] = NULL;
	return (s.count);
}

/*
** Fonction principale : split une chaîne `input` avec un séparateur `sep`,
** en respectant les quotes (les séparateurs entre quotes sont ignorés).
**
** Alloue et retourne un tableau de chaînes (NULL-terminé),
** ou NULL en cas d’erreur.
**
** Paramètres :
**   - input : chaîne à splitter
**   - sep   : caractère séparateur
**
** Retour :
**   - tableau de segments alloué, ou NULL en cas d’erreur
*/
char	**split_smart(const char *input, char sep)
{
	size_t	len;
	char	**result;

	len = ft_strlen(input);
	result = alloc_result_array(len + 1);
	if (!result)
		return (NULL);
	if (fill_segments(input, result, sep) < 0)
		return (ft_free_split(result), NULL);
	return (result);
}
