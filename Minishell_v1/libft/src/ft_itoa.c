/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:36:48 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/03/11 14:40:12 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convertit un entier en chaîne de caractères.
 *
 * La fonction `itoa` prend un entier `n` et le convertit en une chaîne
 * de caractères représentant ce nombre. La chaîne retournée est allouée
 * dynamiquement et doit être libérée après utilisation. Cette fonction gère
 * également les nombres négatifs.
 *
 * @param n L'entier à convertir en chaîne de caractères.
 *
 * @return La chaîne de caractères représentant l'entier, ou NULL
 * 	si l'allocation échoue.
 *
 * @note La fonction gère les entiers négatifs en ajoutant un signe '-'
 * 	au début de la chaîne.La chaîne retournée doit être libérée manuellement
 * 	après utilisation avec `free()`.
 */

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = ft_nbrlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

void	ft_itoa_to_buf(int n, char *buf)
{
	int		len;
	long	nb;

	nb = n;
	len = ft_nbrlen(n);
	buf[len] = '\0';
	if (nb < 0)
	{
		buf[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		buf[0] = '0';
	while (nb > 0)
	{
		buf[--len] = (nb % 10) + '0';
		nb /= 10;
	}
}
