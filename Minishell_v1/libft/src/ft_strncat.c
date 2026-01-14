/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:32:15 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/09/30 20:07:36 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	length;

	length = ft_strlen(dest);
	i = 0;
	while (src[i] && i < nb)
	{
		dest[length] = src[i];
		length ++;
		i++;
	}
	dest[length] = '\0';
	return (dest);
}

/*int	main()
{
	char  str[] = "default\0";	
	char  str1[] = "default\0";	
	printf("%s\n", strncat(str, "manger\0", 0));	
	printf("%s\n", ft_strncat(str1, "salut\0", 0));	
}*/
