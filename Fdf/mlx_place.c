/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:34:02 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/17 12:34:04 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	brezen(t_point one, t_point two, t_mbase base)
{
	t_brzn	brez;

	brez.dx = abs(two.x - one.x);
	brez.dy = abs(two.y - one.y);
	brez.sx = one.x < two.x ? 1 : -1;
	brez.sy = one.y < two.y ? 1 : -1;
	brez.error = brez.dx - brez.dy;
	mlx_pixel_put(base.mlx_ptr, base.win_ptr, two.x, two.y, 0x2ecc71);
	while (one.x != two.x || one.y != two.y)
	{
		mlx_pixel_put(base.mlx_ptr, base.win_ptr, one.x, one.y, 0x2ecc71);
		brez.error2 = brez.error * 2;
		if (brez.error2 > -brez.dy)
		{
			brez.error -= brez.dy;
			one.x += brez.sx;
		}
		else
		{
			brez.error += brez.dx;
			one.y += brez.sy;
		}
	}
}

void	num_mult(t_point ***arr_point, t_mbase base)
{
	int y;
	int x;

	y = 0;
	while (y < base.y)
	{
		x = 0;
		while (x < base.x)
		{
			(*arr_point)[y][x].x = (*arr_point)[y][x].x\
			* base.zoom + base.shift_x;
			(*arr_point)[y][x].y = (*arr_point)[y][x].y\
			* base.zoom + base.shift_y;
			x++;
		}
		y++;
	}
}

void	num_div(t_point ***arr_point, t_mbase base)
{
	int y;
	int x;

	y = 0;
	while (y < base.y)
	{
		x = 0;
		while (x < base.x)
		{
			(*arr_point)[y][x].x = (*arr_point)[y][x].x\
			/ base.zoom + base.shift_x;
			(*arr_point)[y][x].y = (*arr_point)[y][x].y\
			/ base.zoom + base.shift_y;
			x++;
		}
		y++;
	}
}

void	mlx_place(t_point **arr_point, t_mbase base)
{
	base.zoom = 30;
	base.shift_x = 200;
	base.shift_y = 200;
	num_mult(&arr_point, base);
	rotate_z(&arr_point, base, -0.3);
	rotate_x(&arr_point, base, -1.1);
	base.zoom = 1;
	base.arr_point = &arr_point;
	base.mlx_ptr = mlx_init();
	base.win_ptr = mlx_new_window(base.mlx_ptr,\
		base.window_x, base.window_y, "FDF");
	draw((*base.arr_point), base);
	base.zoom = 1;
	base.shift_x = 0;
	base.shift_y = 0;
	base.zoom_ind = 0;
	mlx_key_hook(base.win_ptr, deal_key, (void*)&base);
	mlx_loop(base.mlx_ptr);
}
