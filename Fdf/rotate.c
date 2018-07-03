/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 17:47:49 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/21 17:47:50 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_x(t_point ***arr_point, t_mbase base, long double deg)
{
	int		y;
	int		x;
	int		l;

	y = 0;
	while (y < base.y)
	{
		x = 0;
		while (x < base.x)
		{
			l = (*arr_point)[y][x].z;
			(*arr_point)[y][x].y = (*arr_point)[y][x].y *\
			cos(deg) + (*arr_point)[y][x].z * sin(deg);
			(*arr_point)[y][x].z = (*arr_point)[y][x].z *\
			cos(deg) - l * sin(deg);
			x++;
		}
		y++;
	}
}

void		rotate_z(t_point ***arr_point, t_mbase base, long double deg)
{
	int		y;
	int		x;
	int		l;

	y = 0;
	while (y < base.y)
	{
		x = 0;
		while (x < base.x)
		{
			l = (*arr_point)[y][x].x;
			(*arr_point)[y][x].x = l * cos(deg) +\
			(*arr_point)[y][x].y * sin(deg);
			(*arr_point)[y][x].y = (*arr_point)[y][x].y *\
			cos(deg) - l * sin(deg);
			x++;
		}
		y++;
	}
}
