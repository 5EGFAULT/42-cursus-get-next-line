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

char	*get_next_line(int fd)
{
	char	*s;
	char	*buf;
	int		i;
	int		len;
	char	*tmp;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	s = NULL;
	len = read(fd, buf, BUFFER_SIZE);
	while (len > 0)
	{
		i = -1;
		buf[len] = '\0';
		tmp = s;
		s = ft_strjoin(s, buf,len);
		if (!s)
		{
			free(tmp);
			return (NULL);
		}
		if (ft_strchr(buf, '\n'))
			break ;
			free(tmp);
		len = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (s);
}
