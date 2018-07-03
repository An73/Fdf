/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:23:24 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/16 16:23:26 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		numb_elem(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_array(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	error_e(int check, char ***arr)
{
	if (check != 0 && check != numb_elem(*arr))
	{
		ft_printf("Found wrong line length. Exiting.\n");
		exit(1);
	}
}

void	rewrite(int yx[2], char ***arr, t_point ***arr_point, t_mbase *base)
{
	(*arr_point)[yx[0]][yx[1]].x = yx[1];
	(*arr_point)[yx[0]][yx[1]].y = yx[0];
	(*arr_point)[yx[0]][yx[1]].z = ft_atoi((*arr)[yx[1]]);
	if ((*arr_point)[yx[0]][yx[1]].z)
		(*arr_point)[yx[0]][yx[1]].z *= base->hight;
}

void	entry_point(t_point ***arr_point, int fd, t_mbase *base)
{
	char	*str;
	char	**arr;
	int		yx[2];
	int		check;

	yx[0] = 0;
	check = 0;
	while (get_next_line(fd, &str))
	{
		arr = ft_strsplit(str, ' ');
		error_e(check, &arr);
		check = numb_elem(arr);
		(*arr_point)[yx[0]] = (t_point*)malloc(sizeof(t_point) * check);
		yx[1] = -1;
		while (++yx[1] < check)
			rewrite(yx, &arr, arr_point, base);
		yx[0]++;
		free(str);
		free_array(arr);
	}
	free(str);
	(*base).x = check;
}
