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

#include "get_next_line_bonus.h"

void	lstdelete(t_list *lst, t_list *node)
{
	while (lst && lst->next != node)
		lst = lst->next;
	if (lst)
	{
		free(node->rest);
		lst->next = node->next;
		free(node);
	}
}

t_list	*lstnew(int fd)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->fd = fd;
	tmp->rest = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_list	*get_rest_for_fd(int fd, int create, t_list *lst)
{
	if (!lst && create)
	{
		lst = lstnew(fd);
		if (!lst)
			return (NULL);
		return (lst);
	}
	while (lst && lst->next)
	{
		if (lst->next->fd == fd)
			return (lst->next);
		lst = lst->next;
	}
	if (lst && !lst->next && create)
	{
		lst->next = lstnew(fd);
		if (!lst->next)
			return (NULL);
	}
	return (NULL);
}

char	*process_string(char **rest, char *buffer, char *s, int len)
{
	char	*tmp;

	buffer[len] = '\0';
	if (!s)
	{
		s = ft_strjoin("", buffer, ft_strlen(buffer));
		if (ft_strchr(s, '\n'))
		{
			tmp = *rest;
			*rest = ft_substr(buffer, ft_strlen(buffer));
			free(tmp);
		}
	}
	else
	{
	s = ft_strjoin(s, buffer, len);
	if (ft_strchr(s, '\n'))
	{
		tmp = *rest;
		*rest = ft_substr(buffer, ft_strlen(buffer));
		free(tmp);
	}
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static t_list	*lstrest = NULL;
	char			buffer[BUFFER_SIZE + 1];
	char			*s;
	t_list			*node;
	int				len;

	s = NULL;
	len = 0;
	node = get_rest_for_fd(fd, 1, lstrest);
	if (!node)
		return (NULL);
	if (node->rest)
		s = process_string(&node->rest, node->rest, s, ft_strlen(node->rest));
	if (!ft_strchr(s, '\n'))
		len = read(fd, buffer, BUFFER_SIZE);
	while (len > 0)
	{
		s = process_string(&node->rest, buffer, s, len);
		if (ft_strchr(s, '\n'))
			break ;
		len = read(fd, buffer, BUFFER_SIZE);
	}
	if (!node->rest)
		lstdelete(lstrest, node);
	return (s);
}
