/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:29:20 by asouinia          #+#    #+#             */
/*   Updated: 2021/11/21 14:29:21 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
/**
getting reste of previous buffer read

*/

char	*set_rest_to_str(char **rest)
{
	char 	*s;
	char	*tmp;

	s = NULL;
	if (*rest)
	{
		s = ft_strjoin(s, *rest,ft_strlen(*rest));
		
		tmp = *rest;
		free(tmp);
		if (ft_strchr(s, '\n'))
		{
			*rest = ft_substr(*rest, BUFFER_SIZE);
		}
		else
		{
			*rest = NULL;
		}
	}
	return (s);
}

char	*get_next_line(int fd)
{
	char		*s;
	char		*buf;
	char		*tmp;
	int			len;
	static char	*rest = NULL;

	s = NULL;
	if (rest)
		s = set_rest_to_str(&rest);
	if (rest)
		return (s);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	len = read(fd, buf, BUFFER_SIZE);
	while (len > 0)
	{
		tmp = s;
		s = ft_strjoin(s, buf,len);
		free(tmp);
		if (!s)
		{
			free(buf);
			free(rest);
			return (NULL);
		}
		if (ft_strchr(s, '\n'))
		{
			rest = ft_substr(buf, len);
			free(buf);
			return (s);
		}
		len = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (NULL);
}

