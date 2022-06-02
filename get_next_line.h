/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:29:31 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/02 02:03:44 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);
int ft_strlen(char *str);
char *ft_substr(char *str, char *end);
char *ft_strchr(char *str);
char *ft_strjoin(char *s1, char *s2);

#endif