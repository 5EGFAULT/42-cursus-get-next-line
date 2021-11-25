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

char	*set_rest_to_str(char **rest)
{
	char	*s;
	char	*tmp;

	s = NULL;
	if (*rest)
	{
		s = ft_strjoin(s, *rest, ft_strlen(*rest));
		tmp = *rest;
		if (ft_strchr(s, '\n'))
		{
			*rest = ft_substr(*rest, BUFFER_SIZE);
		}
		else
		{
			*rest = NULL;
		}
		free(tmp);
	}
	return (s);
}

int	loop_checks(char *buf, char **rest, char **s, int len)
{
	char		*tmp;

	buf[len] = '\0';
	tmp = *s;
	*s = ft_strjoin(*s, buf, len);
	free(tmp);
	if (!*s)
	{
		free(buf);
		free(*rest);
		return (1);
	}
	if (ft_strchr(*s, '\n'))
	{
		*rest = ft_substr(buf, len);
		free(buf);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*s;
	char		*buf;
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
	len = 1;
	while (len > 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len > 0 && loop_checks(buf, &rest, &s, len))
			return (s);
	}
	free(buf);
	return (s);
}
