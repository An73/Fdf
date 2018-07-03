/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:40:04 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/21 14:40:06 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_point **arr_point, t_mbase base)
{
	int		y;
	int		x;

	y = 0;
	num_mult(&arr_point, base);
	while (y < base.y)
	{
		x = 0;
		while (x < base.x)
		{
			if (x + 1 < base.x)
				brezen(arr_point[y][x], arr_point[y][x + 1], base);
			if (y + 1 < base.y)
				brezen(arr_point[y][x], arr_point[y + 1][x], base);
			x++;
		}
		y++;
	}
}

void	draw_div(t_point **arr_point, t_mbase base)
{
	int		y;
	int		x;

	y = 0;
	num_div(&arr_point, base);
	while (y < base.y)
	{
		x = 0;
		while (x < base.x)
		{
			if (x + 1 < base.x)
				brezen(arr_point[y][x], arr_point[y][x + 1], base);
			if (y + 1 < base.y)
				brezen(arr_point[y][x], arr_point[y + 1][x], base);
			x++;
		}
		y++;
	}
}
