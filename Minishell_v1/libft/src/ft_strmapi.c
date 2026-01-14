/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:08:44 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/15 13:13:58 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Applique une fonction à chaque caractère d'une chaîne avec son index.
 *
 * La fonction `ft_strmapi` parcourt la chaîne de caractères `s` et applique
 * la fonction `f` à chaque caractère de la chaîne, en passant l'index du
 * caractère et le caractère lui-même comme arguments à la fonction `f`.
 * La fonction retourne une nouvelle chaîne où chaque caractère a été
 * transformé par `f`.
 * La mémoire pour la nouvelle chaîne est allouée dynamiquement et doit être
 * libérée après utilisation.
 *
 * @param s La chaîne de caractères à parcourir.
 * @param f La fonction à appliquer à chaque caractère, prenant deux arguments:
 * 	l'index et le caractère.
 *
 * @return Une nouvelle chaîne avec les caractères transformés, ou `NULL`
 * 	si l'allocation échoue.
 *
 * @note La fonction alloue dynamiquement la mémoire pour la nouvelle chaîne.
 * 	Il est donc nécessaire de libérer cette mémoire une fois qu'elle
 * 	n'est plus utilisée.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	unsigned int	l;

	l = ft_strlen(s);
	str = (char *)malloc((l + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
