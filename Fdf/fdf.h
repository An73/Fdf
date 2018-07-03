/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:42:42 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/16 15:42:44 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H
# include "./libft/includes/libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>

typedef	struct		s_point
{
	int		x;
	int		y;
	int		z;
}					t_point;

typedef	struct		s_mbase
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_point ***arr_point;
	int		y;
	int		x;
	int		zoom;
	int		shift_x;
	int		shift_y;
	int		zoom_ind;
	int		window_x;
	int		window_y;
	int		hight;
}					t_mbase;

typedef	struct		s_brzn
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		error;
	int		error2;
}					t_brzn;

void				entry_point(t_point ***arr_point, int fd, t_mbase *base);
void				mlx_place(t_point **arr_point, t_mbase base);
void				rotate_z(t_point ***arr_point,\
	t_mbase base, long double deg);
void				rotate_x(t_point ***arr_point,\
	t_mbase base, long double deg);
int					deal_key(int key, void *param);
void				draw_div(t_point **arr_point, t_mbase base);
void				draw(t_point **arr_point, t_mbase base);
void				brezen(t_point one, t_point two, t_mbase base);
void				num_mult(t_point ***arr_point, t_mbase base);
void				num_div(t_point ***arr_point, t_mbase base);

#endif
