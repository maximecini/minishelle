/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:51:14 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 11:28:40 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmp(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	find(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!cmp(set, s1[i]))
			break ;
		i++;
	}
	return (i);
}

static int	find_back(char const *s1, char const *set)
{
	const char	*end;

	end = s1 + ft_strlen(s1);
	while (end > s1)
	{
		if (!cmp(set, *(end - 1)))
			break ;
		end--;
	}
	return ((int)(end - s1));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s;
	int		min;
	int		max;

	if (!s1 || !set)
		return (0);
	min = find(s1, set);
	max = find_back(s1, set);
	if (max < min)
		new_s = ft_strdup("\0");
	else
	{
		new_s = (char *)malloc((max - min + 1) * sizeof(char));
		if (!new_s)
			return (0);
		s1 = s1 + min;
		ft_strlcpy(new_s, s1, (size_t)max - min + 1);
	}
	return (new_s);
}
