/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:10:09 by dkotenko          #+#    #+#             */
/*   Updated: 2017/12/14 19:41:38 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/includes/libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft(t_list **temp, t_list **wanted, char *str, int fd)
{
	char	*sw;

	if (*temp == NULL)
	{
		*temp = ft_lstnew(str, ft_strlen(str) + 1);
		(*temp)->content_size = fd;
		*wanted = *temp;
	}
	else if (*wanted && ((int)(*wanted)->content_size) == fd && str != NULL)
	{
		sw = (*wanted)->content;
		(*wanted)->content = ft_strjoin((*wanted)->content, str);
		free(sw);
	}
	else
	{
		*wanted = *temp;
		while (*wanted && ((int)(*wanted)->content_size) != fd)
			*wanted = (*wanted)->next;
		if (*wanted)
			return ;
		ft_lstadd(temp, ft_lstnew(str, ft_strlen(str) + 1));
		(*temp)->content_size = fd;
	}
}

int		number_n(t_list **wanted)
{
	int		i;

	i = 0;
	while (((char*)(*wanted)->content)[i] != '\0')
	{
		if (((char*)(*wanted)->content)[i] == '\n')
		{
			if ((((char*)(*wanted)->content)[i + 1] != '\0'))
				return (1);
		}
		i++;
	}
	return (0);
}

void	move(int *num, t_list **wanted, int *len)
{
	num[0] = 0;
	if (num[1] > 0)
		num[0] = 1;
	if ((num[1] > 0 && *wanted != NULL))
	{
		if (ft_strchr((*wanted)->content, '\n') != NULL)
			*len = ft_strchr((*wanted)->content, '\n') - \
		((char*)(*wanted)->content) + 1;
		ft_bzero((*wanted)->content, *len);
		ft_memmove((*wanted)->content, &((*wanted)->content[*len]), \
			ft_strlen(&((*wanted)->content[*len])) + 1);
		num[0] = 1;
	}
}

void	line_f(int *len, t_list **wanted, char **line)
{
	if (*wanted != NULL && ft_strchr((*wanted)->content, '\n') != NULL)
		*len = ft_strchr((*wanted)->content, '\n') - (char*)(*wanted)->content;
	else if (*wanted != NULL)
		*len = ft_strchr((*wanted)->content, '\0') - (char*)(*wanted)->content;
	if (*wanted != NULL)
		*line = ft_strsub((*wanted)->content, 0, *len);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*temp;
	t_list			*wanted;
	char			str[BUFF_SIZE + 1];
	int				len;
	int				num[2];

	len = 0;
	wanted = NULL;
	ft_bzero(&str, BUFF_SIZE + 1);
	num[1] = read(fd, &str, BUFF_SIZE);
	if (temp != NULL)
		ft(&temp, &wanted, str, fd);
	if (num[1] == -1)
		return (-1);
	move(num, &wanted, &len);
	if (num[1] > 0)
		ft(&temp, &wanted, str, fd);
	while (num[1] > 0 && ft_strchr(wanted->content, '\n') == NULL)
	{
		ft_bzero(&str, BUFF_SIZE + 1);
		num[1] = read(fd, &str, BUFF_SIZE);
		ft(&temp, &wanted, str, fd);
	}
	line_f(&len, &wanted, line);
	return (num[0]);
}
