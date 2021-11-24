/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:45:09 by asouinia          #+#    #+#             */
/*   Updated: 2021/11/24 22:45:11 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char const *s2, int len);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, size_t len);
char	*get_next_line(int fd);

#endif