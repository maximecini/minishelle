/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:57:20 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/23 16:36:00 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Recherche la dernière occurrence d'un caractère dans une chaîne
 * 	de caractères.
 *
 * La fonction `ft_strrchr` recherche la dernière occurrence du caractère `c`
 * dans la chaîne `s`.Elle retourne un pointeur vers la dernière occurrence
 * trouvée de `c` dans la chaîne, ou `NULL`si le caractère n'est pas trouvé.
 * Si `c` est le caractère nul (`'\0'`), la fonction retourne un pointeur vers
 * la fin de la chaîne `s`.
 *
 * @param s La chaîne de caractères dans laquelle rechercher.
 * @param c Le caractère à rechercher dans la chaîne.
 *
 * @return Un pointeur vers la dernière occurrence de `c` d
 * ans la chaîne, ou `NULL` si `c` n'est pas trouvé.
 *
 * @note Cette fonction permet de trouver la dernière occurrence d'un caractère,
 * ce qui est utile lorsqu'on souhaite analyser une chaîne de droite à gauche ou
 * traiter des cas où une même valeur peut apparaître plusieurs fois
 * dans la chaîne.
 */

char	*ft_strrchr(const char *string, int searchedChar)
{
	int	l;

	l = 0;
	l = ft_strlen(string);
	while (l + 1)
	{
		if (string[l] == (unsigned char)searchedChar)
			return ((char *)&string[l]);
		l--;
	}
	return (0);
}
