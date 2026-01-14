/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:28:49 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:04:34 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
 * @brief Écrit un caractère sur un descripteur de fichier.
 *
 * La fonction `ft_putchar_fd` écrit un caractère spécifié (`c`) sur le
 * descripteur de fichier donné (`fd`). Cette fonction est utile pour
 *  afficher des caractères dans des fichiers ou dans la sortie standard
 * (ou erreur), en fonction du descripteur passé en paramètre.
 *
 * @param c Le caractère à écrire.
 * @param fd Le descripteur de fichier sur lequel écrire le caractère.
 *
 * @return Aucune valeur de retour. Le caractère est écrit directement sur le
 * 	descripteur de fichier.
 *
 * @note Cette fonction est souvent utilisée pour écrire sur des fichiers ou
 * 	pour afficher des caractères dans des flux de sortie différents de `stdout`
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
