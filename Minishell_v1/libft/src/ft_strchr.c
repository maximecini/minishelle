/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:58:03 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 20:53:32 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Recherche la première occurrence d'un caractère dans une chaîne de
 * 	caractères.
 *
 * La fonction `ft_strchr` recherche la première occurrence du caractère `c` 
 * dans la chaîne de caractères `s`. Elle retourne un pointeur vers la 
 * première occurrence trouvée de `c`,ou `NULL` si le caractère n'est pas 
 * trouvé dans la chaîne. Si `c` est le caractère nul (`'\0'`),la 
 * fonction retourne un pointeur vers la fin de la chaîne `s`.
 *
 * @param s La chaîne de caractères dans laquelle rechercher.
 * @param c Le caractère à rechercher dans la chaîne.
 * 
 * @return Un pointeur vers la première occurrence de `c` 
 * 	dans la chaîne, ou `NULL` si `c` n'est pas trouvé.
 * 
 * @note Cette fonction est équivalente à la fonction standard `strchr` 
 * 	de la bibliothèque C.
 */
char	*ft_strchr(const char *s, int n)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)n)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)n == 0)
		return ((char *)s);
	return (0);
}
