/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:53:03 by aoudin            #+#    #+#             */
/*   Updated: 2017/01/23 19:07:01 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_destroy(void)
{
	exit(0);
}

void		ft_print_usage(void)
{
	ft_putendl("FDF CONTROLS : \n\n");
	ft_putendl("Move with arrows");
	ft_putendl("Zoom/Dezoom with [+],[-]");
	ft_putendl("Rotate left/right with [/],[*]");
	ft_putendl("Incline/Decline with [Home], [End]");
	ft_putendl("Modify height with [Page up],[Page down]");
	ft_putendl("Reset display with [Space]");
	ft_putendl("Exit program with [Esc]");
}

void		ft_init_image(t_windata *t_fdf)
{
	HEIGHT = (t_fdf->ymax * 70 < 1300) ? (t_fdf->ymax * 80) : 1300;
	WIDTH = (t_fdf->xmax * 50 < 2400) ? (t_fdf->xmax * 50) : 2400;
	ZOOM = (t_fdf->ymax < 30) ? 20 : 10;
	MOVUD = 0;
	MOVLR = 0;
	MOVALT = 1;
	ANGLE = 1;
	INCLI = 1;
	ft_print_usage();
	t_fdf->mlx = mlx_init();
	t_fdf->win = mlx_new_window(t_fdf->mlx, WIDTH, HEIGHT, FILENAME);
	t_fdf->img = mlx_new_image(t_fdf->mlx, WIDTH, HEIGHT);
	t_fdf->data = mlx_get_data_addr(t_fdf->img, &t_fdf->bpp, &t_fdf->size_line,
			&t_fdf->endian);
}

void		ft_f5(t_windata *t_fdf)
{
	mlx_destroy_image(t_fdf->mlx, t_fdf->img);
	t_fdf->img = mlx_new_image(t_fdf->mlx, WIDTH, HEIGHT);
	t_fdf->data = mlx_get_data_addr(t_fdf->img, &t_fdf->bpp, &t_fdf->size_line,
			&t_fdf->endian);
}

void		ft_reset_position(t_windata *t_fdf)
{
	MOVALT = 1;
	ZOOM = (t_fdf->ymax < 30) ? 20 : 10;
	MOVUD = 0;
	MOVLR = 0;
	ANGLE = 1;
	INCLI = 1;
}
