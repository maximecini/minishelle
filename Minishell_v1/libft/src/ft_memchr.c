/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:29:18 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:04:50 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Recherche un octet spécifique dans une zone mémoire.
 *
 * La fonction `ft_memchr` parcourt une zone mémoire et recherche la
 * première occurrence de l'octet spécifié. Elle renvoie un pointeur
 * vers la première occurrence trouvée, ou `NULL` si l'octet n'est pas trouvé
 * dans la zone mémoire.
 *
 * @param s Le pointeur vers la zone mémoire à explorer.
 * @param c L'octet à rechercher dans la zone mémoire (unsigned char).
 * @param n Le nombre d'octets à examiner.
 *
 * @return Un pointeur vers la première occurrence de l'octet `c` dans
 * 	la zone mémoire,
 *         ou `NULL` si l'octet n'est pas trouvé.
 *
 * @note Cette fonction est équivalente à la fonction standard `memchr`
 * de la bibliothèque C.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;

	ps = (unsigned char *)s;
	while (n--)
	{
		if (*ps == (unsigned char)c)
			return ((void *)ps);
		ps++;
	}
	return (NULL);
}
