/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 18:13:21 by aoudin            #+#    #+#             */
/*   Updated: 2017/01/24 15:44:06 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void			ft_create_struct(int fd, char *map)
{
	t_windata		*t_fdf;

	if (!(t_fdf = (t_windata*)ft_memalloc(sizeof(t_windata))))
		return (exit(0));
	FILENAME = map;
	ft_parsefdf(t_fdf, fd);
	ft_init_image(t_fdf);
	mlx_loop_hook(t_fdf->mlx, ft_display, t_fdf);
	mlx_hook(t_fdf->win, KeyPress, KeyPressMask, ft_hookevent, t_fdf);
	mlx_hook(t_fdf->win, DestroyNotify, Button1MotionMask, ft_destroy, NULL);
	mlx_loop(t_fdf->mlx);
	ft_free_struct(t_fdf);
}

int					main(int ac, char **av)
{
	int		fd;
	int		ret;

	if (ac != 2)
		ft_putendl("Usage : ./fdf <map>");
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd > 0)
			ft_create_struct(fd, av[1]);
		else
			ft_putendl("Invalid file");
		close(fd);
	}
	return (0);
}
