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

char	*ft_strjoin(char const *s1, char const *s2,int	len)
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
	if (!s1)
	{
		while (s2[++i] && s2[i] != '\n' && i < len)
			s[i] = s2[i];
		s[i] = s2[i];
		if (s2[i])
			s[i + 1] = '\0';
		return (s);
	}
	while (s1[++j])
		s[j] = s1[j];
	while (s2[++i] && s2[i] != '\n'  && i < len)
		s[i + j] = s2[i];
	s[i + j] = s2[i];
	if (s2[i])
			s[i + j + 1] = '\0';
	return (s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
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