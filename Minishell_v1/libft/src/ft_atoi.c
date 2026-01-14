/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:35:53 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/02/10 14:09:21 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Convertit une chaîne de caractères en un entier.*
 *
 * La fonction `atoi` prend une chaîne de caractères représentant un nombre
 * et renvoie sa valeur entière. Elle ignore les espaces blancs au début de
 * la chaîne et gère les signes négatifs ou positifs. Si la chaîne ne représente
 * pas un nombre valide, le comportement est indéfini, et la fonction renvoie 0.
 *
 * @param str La chaîne de caractères à convertir.
 *
 * @return L'entier correspondant à la chaîne de caractères. Si la chaîne
 *         est invalide ou vide, 0 est retourné.
 *
 * @note Cette fonction ne gère pas les erreurs comme le dépassement de capacité
 *       (overflow). Les résultats sont indéfinis pour des chaînes qui dépassent
 *       la capacité d'un entier.
 */
long	ft_atoi(const char *str)
{
	int		i;
	long	result;
	long	indice;

	i = 0;
	result = 0;
	indice = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			indice = -indice;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + ((str[i] - 48));
		i++;
	}
	return (result * indice);
}
