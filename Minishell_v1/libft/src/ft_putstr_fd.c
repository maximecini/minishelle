/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:37:40 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:04:45 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Écrit une chaîne de caractères sur un descripteur de fichier.
 *
 * La fonction `ft_putstr_fd` écrit la chaîne de caractères `s` sur le
 * descripteur de fichier spécifié (`fd`). Elle parcourt la chaîne et écrit
 * chaque caractère individuellement sur le descripteur, permettant d'afficher
 * la chaîne dans des fichiers ou dans des flux de sortie comme la sortie
 * standard ou d'erreur.
 *
 * @param s La chaîne de caractères à écrire.
 * @param fd Le descripteur de fichier sur lequel écrire la chaîne.
 *
 * @return Aucune valeur de retour. La chaîne est écrite directement sur le
 * 	descripteur de fichier.
 *
 * @note Cette fonction est souvent utilisée pour afficher des chaînes
 * 	dans des flux de sortie différents ou pour écrire dans des fichiers.
 */
void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
