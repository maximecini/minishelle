/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:53:47 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/03 15:14:15 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Écrit un entier sur un descripteur de fichier.
 *
 * La fonction `ft_putnbr_fd` convertit l'entier `n` en une chaîne de
 * caractères et l'écrit sur le descripteur de fichier donné (`fd`). Si
 * l'entier est négatif, un signe `-` est écrit avant le nombre. La fonction
 * gère aussi les entiers zéro et les autres cas de manière appropriée.
 *
 * @param n L'entier à écrire.
 * @param fd Le descripteur de fichier sur lequel écrire l'entier.
 *
 * @return Aucune valeur de retour. L'entier est écrit directement sur
 * 	le descripteur de fichier.
 *
 * @note Cette fonction est souvent utilisée pour afficher des entiers
 * dans des flux de sortie différents de `stdout`, comme `stderr`, ou pour
 * écrire des entiers dans des fichiers.
 */
int	ft_putnbr_fd(int nbr)
{
	long	number;
	long	size_digit;
	long	curent;

	number = nbr;
	if (number < 0)
	{
		number *= -1;
		write(1, "-", 1);
	}
	curent = ft_digitlen(number, 10);
	size_digit = ft_base_power(number, 10);
	if (nbr < 0)
		curent++;
	while (size_digit > 0)
	{
		ft_putchar_fd((number / size_digit) % 10, 1);
		size_digit /= 10;
	}
	return (curent);
}
