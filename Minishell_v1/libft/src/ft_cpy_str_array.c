/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_str_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:50:24 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/26 21:11:25 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** copy_string_array - copie un tableau de chaînes de caractères
** @src: tableau source à copier
** @count: nombre d’éléments à ajouter (hors NULL final)
**
** Alloue un nouveau tableau, duplique chaque chaîne de @src,
** et ajoute un pointeur NULL final.
** Retourne le nouveau tableau ou NULL en cas d’échec.
*/
char	**copy_string_array(char **src, int count)
{
	char	**dest;
	int		index;
	int		src_len;
	int		total_size;

	src_len = ft_array_len(src);
	total_size = src_len + count;
	dest = malloc(sizeof(char *) * (total_size + 1));
	if (!dest)
		return (NULL);
	ft_bzero(dest, sizeof(char *) * (total_size + 1));
	index = 0;
	while (src[index])
	{
		dest[index] = ft_strdup(src[index]);
		if (!dest[index])
		{
			ft_free_split(dest);
			return (NULL);
		}
		index++;
	}
	return (dest);
}

char	**cpy_tab(char **tab_char, int value, int free_tab)
{
	int		i;
	char	**cpy_tab;
	size_t	len_cp_tab;

	len_cp_tab = 0;
	while (tab_char[len_cp_tab])
		len_cp_tab++;
	len_cp_tab += value;
	cpy_tab = malloc(sizeof(char *) * (len_cp_tab + 1));
	if (!cpy_tab)
		return (NULL);
	i = 0;
	while (tab_char[i])
	{
		cpy_tab[i] = ft_strdup(tab_char[i]);
		if (!cpy_tab[i++])
			return (NULL);
	}
	while (i < (int)len_cp_tab)
		cpy_tab[i++] = NULL;
	cpy_tab[i] = NULL;
	if (free_tab)
		ft_free_split(tab_char);
	return (cpy_tab);
}
