/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 08:59:07 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/27 21:57:49 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	*copy_next_line(char buffer[BUFFER_SIZE], char tmp[BUFFER_SIZE],
		char c)
{
	char	*temp;

	temp = ft_strchr(buffer, c);
	if (temp)
	{
		ft_strlcpy(tmp, temp + 1, BUFFER_SIZE);
		return (tmp);
	}
	return (NULL);
}

static char	*get_line(char buffer[BUFFER_SIZE + 1], char **line, int fd, char c)
{
	int	i;
	int	bytes_read;

	if (!*line)
		return (NULL);
	i = 1;
	while (i && (!ft_strchr(*line, c)))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(*line), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		*line = ft_strjoin(*line, buffer, 1, 0);
		if (!*line)
			return (NULL);
		if (ft_strchr(buffer, c))
			break ;
	}
	return (*line);
}

static char	*print_line(char *line, char c)
{
	char	*tmp;
	int		i;
	int		j;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != c)
	{
		i++;
	}
	if (line[i] == c)
		i++;
	tmp = malloc((i + 1) * sizeof(char));
	if (!tmp)
		return (free(line), NULL);
	j = 0;
	while (j < i)
	{
		tmp[j] = line[j];
		j++;
	}
	tmp[i] = '\0';
	free(line);
	return (tmp);
}

char	*get_next_line(int fd, char c)
{
	static char	rmd[FD_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (fd > FD_MAX || fd < 0)
		return (NULL);
	if (rmd[fd][0])
	{
		line = ft_strdup(rmd[fd]);
		if (!line)
			return (NULL);
		if (line && !ft_strchr(line, c))
			rmd[fd][0] = '\0';
	}
	else
		line = ft_strdup("\0");
	line = get_line(rmd[fd], &line, fd, c);
	rmd[fd][0] = '\0';
	if (!line)
		return (free(line), rmd[fd][0] = '\0', NULL);
	copy_next_line(line, rmd[fd], c);
	line = print_line(line, c);
	if (!line || !line[0])
		return (free(line), rmd[fd][0] = '\0', NULL);
	return (line);
}

// int main()
// {
// 	int 	fd;
// 	int 	fd2;
// 	char	*line;

// 	// fd = open("get_next_line.h", O_RDONLY);
// 	// fd2 = open("get_next_line.c", O_RDONLY);

// 	// while (1)
// 	// {
// 	// 	line = get_next_line(fd);
// 	// 	printf("1>%s", line);
// 	// 	if (!line)
// 	// 		break ;
// 	// 	free(line);
// 	// }
// 	// while (1)
// 	// {
// 	// 	line = get_next_line(fd2);
// 	// 	printf("2>%s", line);
// 	// 	if (!line)
// 	// 		break ;
// 	// 	free(line);
// 	// }
// 	// close (fd);
// 	// close (fd2);
// 	fd = open("get_next_line.h", O_RDONLY);
// 	fd2 = open("get_next_line.c", O_RDONLY);
// 	fd2 = dup2(fd2, 100);
// 	fd2 = 100;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		printf("1>%s", line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("2>%s", line);
// 		if (!line)
// 			break ;
// 		free(line);
// 	}
// }
