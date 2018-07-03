/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:56:46 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/21 13:56:48 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift(int key, void *param)
{
	if (key == 126)
	{
		((t_mbase*)param)->shift_y -= 15;
		draw(*(((t_mbase*)param)->arr_point), (*(t_mbase*)param));
	}
	else if (key == 125)
	{
		((t_mbase*)param)->shift_y += 15;
		draw(*(((t_mbase*)param)->arr_point), (*(t_mbase*)param));
	}
	else if (key == 123)
	{
		((t_mbase*)param)->shift_x -= 15;
		draw(*(((t_mbase*)param)->arr_point), (*(t_mbase*)param));
	}
	else if (key == 124)
	{
		((t_mbase*)param)->shift_x += 15;
		draw(*(((t_mbase*)param)->arr_point), (*(t_mbase*)param));
	}
	((t_mbase*)param)->shift_x = 0;
	((t_mbase*)param)->shift_y = 0;
}

void	ft_zoom(int key, void *param)
{
	if (key == 119 && ((t_mbase*)param)->zoom_ind != 0)
	{
		((t_mbase*)param)->zoom_ind--;
		((t_mbase*)param)->zoom = 2;
		draw_div(*(((t_mbase*)param)->arr_point), (*(t_mbase*)param));
	}
	else if (key == 115)
	{
		((t_mbase*)param)->zoom_ind++;
		((t_mbase*)param)->zoom = 2;
		draw(*(((t_mbase*)param)->arr_point), (*(t_mbase*)param));
	}
	((t_mbase*)param)->zoom = 1;
}

int		deal_key(int key, void *param)
{
	mlx_clear_window(((t_mbase*)param)->mlx_ptr, ((t_mbase*)param)->win_ptr);
	if (key == 53)
		exit(0);
	else if (key >= 123 && key <= 126)
		shift(key, param);
	else if ((key == 119 && ((t_mbase*)param)->zoom_ind != 0) || key == 115)
		ft_zoom(key, param);
	else
		draw(*(((t_mbase*)param)->arr_point), (*(t_mbase*)param));
	return (0);
}
