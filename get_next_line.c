/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:29:20 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/02 17:06:36 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_saved(char **save)
{
	char	*line;
	char	*tmp;
	char	*end;

	if (!save)
		return (NULL);
	end = ft_strchr(*save);
	tmp = *save;
	line = ft_substr(*save, end);
	*save = ft_substr(end, NULL);
	free(tmp);
	return (line);
}

char	*get_line(char **save, char *buff, char *line, int fd)
{
	char	*tmp[2];
	char	*end;
	int		len;

	len = read(fd, buff, BUFFER_SIZE);
	while (len > 0)
	{
		buff[len] = '\0';
		end = ft_strchr(buff);
		tmp[0] = ft_substr(buff, end);
		tmp[1] = ft_substr(end, NULL);
		*save = tmp[1];
		line = ft_strjoin(line, tmp[0]);
		if (end)
			return (line);
		len = read(fd, buff, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	line = get_saved(&save);
	if (ft_strchr(line))
		return (free(buff), line);
	line = get_line(&save, buff, line, fd);
	return (free(buff), line);
}
