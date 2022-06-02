/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:29:43 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/02 16:00:59 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_substr(char *str, char *end)
{
	char	*substr;
	int		i;

	if (!str || !*str)
		return (NULL);
	i = 0;
	while (str && str[i] && str + i != end)
		i++;
	substr = (char *)malloc(sizeof(char) * (i + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (str && str[i] && str + i != end)
	{
		substr[i] = str[i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strchr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (str + i + 1);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (free(s1), free(s2), NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (str);
}
