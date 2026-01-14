/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:10:26 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/26 21:16:05 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
** Recherche la première occurrence de la sous-chaîne `to_find` dans la
** chaîne `str`.
** Si `to_find` est une chaîne vide, la fonction retourne `str`.
** Sinon, elle parcourt `str` caractère par caractère et compare à `to_find`.
** Lorsqu’un caractère de `str` correspond au premier caractère de `to_find`,
** elle appelle `verify_str` pour vérifier que toute la sous-chaîne correspond.
**
** Si la sous-chaîne est trouvée, la fonction retourne un pointeur
** vers le début de cette occurrence dans `str`.
** Si elle n’est pas trouvée, la fonction retourne NULL.
**
** @param str : chaîne dans laquelle chercher
** @param to_find : sous-chaîne à trouver
**
** @return pointeur vers la première occurrence de `to_find` dans `str`,
**         ou NULL si elle n’y figure pas.
*/
int	verify_str(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (to_find[0] == '\0')
		return (str);
	while (*str)
	{
		if (*str == to_find[0] && verify_str(str, to_find))
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}

/*int main(int argc, char **argv) {
	if (argc == 3)
		{
		printf("%s\n" ,  ft_strstr(argv[1], argv[2]));
			printf("%s\n" ,  strstr(argv[1], argv[2]));
	}
	return (0);
}*/
