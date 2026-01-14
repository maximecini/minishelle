/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:39:18 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/01 14:24:28 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatène deux chaînes de caractères en allouant une nouvelle mémoire.
 *
 * Cette fonction prend deux chaînes `s1` et `s2`, les concatène et retourne
 * une nouvelle chaîne allouée dynamiquement. Elle permet également de libérer
 * `s1`et/ou `s2` selon les valeurs de `f1` et `f2`.
 *
 * @param s1 Première chaîne de caractères.
 * @param s2 Deuxième chaîne de caractères.
 * @param f1 Si différent de 0, libère `s1` après la concaténation.
 * @param f2 Si différent de 0, libère `s2` après la concaténation.
 *
 * @return Un pointeur vers la nouvelle chaîne concaténée, ou `NULL` en
 * cas d'erreur.
 */

static char	*handle_null_s1(char *s2, int f2)
{
	char	*new_s;

	new_s = ft_strdup(s2);
	if (f2 && s2)
		free(s2);
	return (new_s);
}

static char	*handle_null_s2(char *s1, int f1)
{
	char	*new_s;

	new_s = ft_strdup(s1);
	if (f1 && s1)
		free(s1);
	return (new_s);
}

static char	*join_and_free(char *s1, char *s2, int f1, int f2)
{
	char	*new_s;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_s = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s1, len_s1 + 1);
	ft_strlcat(new_s, s2, len_s1 + len_s2 + 1);
	if (f1 && s1)
		free(s1);
	if (f2 && s2)
		free(s2);
	return (new_s);
}

char	*ft_strjoin(char *s1, char *s2, int f1, int f2)
{
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (handle_null_s1(s2, f2));
	if (!s2)
		return (handle_null_s2(s1, f1));
	return (join_and_free(s1, s2, f1, f2));
}
