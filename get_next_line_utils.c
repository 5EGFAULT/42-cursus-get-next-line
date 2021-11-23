/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:29:43 by asouinia          #+#    #+#             */
/*   Updated: 2021/11/21 14:29:44 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char *s1, char const *s2,int len)
{
	char	*s;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s2)
		return (0);
	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (0);
	while (s1 && s1[++j])
		s[j] = s1[j];
	if (!s1)
		j++;
	while (s2[++i]  && len > i)
	{
		s[i + j] = s2[i];
		if(s2[i] == '\n')
		{
			i++;
			break ;
		}
	}
	s[i + j] = '\0';
	// printf("{%s}",s);
	// printf("{{%s}}",s2);
	return (s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((char) c == s[i])
			return ((char *)(s + i));
		i++;
	}
	if ((char) c == s[i])
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_substr(char *s, size_t len)
{
	char	*res;
	int		i;
	int		start;

	start = -1;
	i = -1;
	while (s[++start] && s[start] != '\n')
		;
	++start;
	if (s && (size_t)start < ft_strlen(s))
	{
		res = (char *)malloc(len + 1);
		if (!(res))
			return (0);
		while (s[++i + start] && (size_t) i + start < len)
			res[i] = s[i + start];
		res[i] = '\0';
		return (res);
	}
	return (0);
}