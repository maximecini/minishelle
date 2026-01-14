/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:45:47 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:04:43 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
 * @brief Écrit une chaîne de caractères suivie d'un saut de ligne sur un
 * 	descripteur de fichier.
 *
 * La fonction `ft_putendl_fd` écrit la chaîne de caractères `s` suivie d'un
 * caractère de nouvelle ligne (`\n`) sur le descripteur de fichier
 * donné (`fd`).
 * Cela permet d'afficher des lignes de texte dans des fichiers ou sur la sortie
 * standard/erreur selon le descripteur passé en paramètre.
 *
 * @param s La chaîne de caractères à écrire.
 * @param fd Le descripteur de fichier sur lequel écrire la chaîne et le
 * 	saut de ligne.
 *
 * @return Aucune valeur de retour. La chaîne et le saut de ligne sont
 * 	écrits directement sur le descripteur de fichier.
 *
 * @note Cette fonction est souvent utilisée pour afficher des lignes
 * 	de texte dans des flux de sortie différents de `stdout`
 * 	ou pour écrire dans des fichiers.
 */
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
