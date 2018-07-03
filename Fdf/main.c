/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:40:59 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/16 15:41:06 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**write_point(char *argv, t_mbase *base)
{
	int		fd;
	int		num;
	char	*str;
	t_point	**arr_point;

	num = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("No file %s\n", argv);
		exit(1);
	}
	while (get_next_line(fd, &str))
	{
		num++;
		free(str);
	}
	(*base).y = num;
	arr_point = (t_point**)malloc(sizeof(t_point*) * num);
	close(fd);
	free(str);
	return (arr_point);
}

void		hight_set(int argc, char **argv, t_mbase *base)
{
	if (argc == 3)
		base->hight = ft_atoi(argv[2]);
	else
		base->hight = ft_atoi(argv[4]);
	if (base->hight > 100 || base->hight < -100)
	{
		ft_printf("ERROR: height > 100 or height < -100\n");
		exit(1);
	}
}

void		window_set(char **argv, t_mbase *base)
{
	int		w;

	w = ft_atoi(argv[2]);
	if (w >= 500 && w <= 2500)
		base->window_x = w;
	else
	{
		ft_printf("ERROR: window width < 500 or > 2500\n");
		exit(1);
	}
	w = ft_atoi(argv[3]);
	if (w >= 500 && w <= 2500)
		base->window_y = w;
	else
	{
		ft_printf("ERROR: window height < 500 or > 2500\n");
		exit(1);
	}
}

int			main(int argc, char **argv)
{
	t_point		**arr_point;
	t_mbase		base;
	int			fd;

	base.hight = 2;
	base.window_x = 1200;
	base.window_y = 1000;
	if (argc == 1 || argc > 5)
	{
		ft_printf("Usage : ./fdf <filename> <window width> \
<window height> <hight>\n");
		exit(1);
	}
	else if (argc == 3 || argc == 5)
		hight_set(argc, argv, &base);
	if (argc >= 4)
		window_set(argv, &base);
	arr_point = write_point(argv[1], &base);
	fd = open(argv[1], O_RDONLY);
	entry_point(&arr_point, fd, &base);
	mlx_place(arr_point, base);
}
