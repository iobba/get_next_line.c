/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:05:30 by iobba             #+#    #+#             */
/*   Updated: 2022/11/08 09:58:57 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int	ft_strchr_nl(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read(char *left, int fd)
{
	char	*string;
	ssize_t	r;

	string = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!string)
		return (NULL);
	r = read(fd, string, BUFFER_SIZE);
	while (r >= 0)
	{	
		string[r] = '\0';
		left = ft_strjoin(left, string);
		if (!r || ft_strchr_nl(left))
		{
			free(string);
			return (left);
		}
		r = read(fd, string, BUFFER_SIZE);
	}
	free(string);
	free(left);
	left = NULL;
	return (NULL);
}

char	*ft_fill_line(char *left)
{
	char	*line;
	int		i;

	i = 0;
	while (left[i] && left[i] != '\n')
		i++;
	if (left[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (left[i] && left[i] != '\n')
	{
		line[i] = left[i];
		i++;
	}
	if (left[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_update_left(char *left)
{
	char	*ptr;
	int		i;
	int		size;

	i = 0;
	while (left[i] && left[i] != '\n')
		i++;
	if (left[i] == '\0')
	{
		free(left);
		return (NULL);
	}
	size = ft_strlen(left) - i;
	ptr = malloc(size * sizeof(char));
	if (!ptr)
		return (NULL);
	i++;
	ft_strlcpy(ptr, left + i, size);
	free(left);
	left = NULL;
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*left[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!left[fd])
	{
		left[fd] = malloc(1 * sizeof(char));
		if (!left[fd])
			return (NULL);
		*left[fd] = '\0';
	}
	left[fd] = ft_read(left[fd], fd);
	if (!left[fd])
		return (NULL);
	if (left[fd][0] == '\0')
	{
		free(left[fd]);
		left[fd] = NULL;
		return (NULL);
	}
	line = ft_fill_line(left[fd]);
	left[fd] = ft_update_left(left[fd]);
	return (line);
}
