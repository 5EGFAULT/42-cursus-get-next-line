/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:29:20 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/02 02:42:15 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
// char *get_saved(char **save)
//{

//}

char *get_line(char **save, char *buff, char *line, int fd)
{
	char *tmp[2];
	char *end;
	int len;

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

char *get_next_line(int fd)
{
	char *line;
	char *buff;
	static char *save;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff || fd < 0)
		return (NULL);
	line = NULL;
	line = get_line(&save, buff, line, fd);
	free(buff);
	free(save);
	return (line);
}
