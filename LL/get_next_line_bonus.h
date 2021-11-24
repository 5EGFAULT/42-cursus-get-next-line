/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:29:31 by asouinia          #+#    #+#             */
/*   Updated: 2021/11/21 14:29:33 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H 
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*rest;
	int				fd;
	struct s_list	*next;
}				t_list;

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char const *s2, int len);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, size_t len);
char	*get_next_line(int fd);

#endif