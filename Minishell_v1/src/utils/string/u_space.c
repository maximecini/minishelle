/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_space.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 08:04:43 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 13:48:38 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Copie un segment de la chaîne source `src` à partir de l'index `start`,
** sur une longueur `len`.
** Alloue dynamiquement une nouvelle chaîne terminée par '\0'.
** Retourne NULL si l’allocation échoue.
**
** Paramètres :
**  - src   : chaîne source
**  - start : index de début dans src
**  - len   : longueur à copier
**
** Retour :
**  - nouvelle chaîne allouée contenant le segment copié
*/
char	*copy_segment(const char *src, size_t start, size_t len)
{
	char	*copy;
	size_t	i;

	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = src[start + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*
** Avance l’index `i` dans la chaîne `str` tant que les caractères
** sont des espaces.
**
** Paramètres :
**  - str : chaîne source
**  - i   : position initiale dans la chaîne
**
** Retour :
**  - nouvelle position après avoir sauté les espaces
*/
int	skip_whitespace(char *str, int i)
{
	while (str[i] && is_whitespace(str[i]))
		i++;
	return (i);
}

/*
** Vérifie si un caractère est un espace blanc (espace,
	tabulation ou saut de ligne).
**
** Paramètre :
**  - c : caractère à tester
**
** Retour :
**  - 1 si c est un espace blanc, 0 sinon
*/
int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/*
** Copie un segment de la chaîne `input` entre les indices `start` et `end`,
** en supprimant les espaces en début et fin de segment.
** Utilise `trim_segment` pour ajuster les indices, puis `copy_segment`
** pour réaliser la copie.
**
** Paramètres :
**  - input : chaîne source
**  - start : indice de début du segment initial
**  - end   : indice de fin du segment initial
**
** Retour :
**  - nouvelle chaîne allouée contenant le segment nettoyé
*/
char	*copy_trimmed_segment(const char *input, size_t start, size_t end)
{
	while (start < end && input[start] == ' ')
		start++;
	while (end > start && input[end - 1] == ' ')
		end--;
	return (copy_segment(input, start, end - start));
}

/*
** Avance la position pointée par `pos` tant que le caractère à cette
** position est un espace.
**
** Paramètres :
**  - str : chaîne source
**  - pos : pointeur vers la position à avancer
*/
void	skip_spaces(char *str, int *pos)
{
	while (str[*pos] == ' ')
		(*pos)++;
}
