/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:10:54 by aoudin            #+#    #+#             */
/*   Updated: 2017/01/24 16:01:54 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_exit(int i)
{
	if (i == 1)
		ft_putendl("map error");
	exit(0);
}

void			ft_paint_color(t_windata *t_fdf, int z)
{
	if (!COL)
	{
		if (z >= 100)
			COL = mlx_get_color_value(t_fdf->mlx, 0xFFFFFF);
		if (z < 100 && z >= 60)
			COL = mlx_get_color_value(t_fdf->mlx, 0x663300);
		if (z < 60 && z >= 40)
			COL = mlx_get_color_value(t_fdf->mlx, 0x990000);
		if (z < 40 && z >= 20)
			COL = mlx_get_color_value(t_fdf->mlx, 0x339933);
		if (z < 20 && z > 0)
			COL = mlx_get_color_value(t_fdf->mlx, 0x94BF8B);
		if (z < 0 && z >= -20)
			COL = mlx_get_color_value(t_fdf->mlx, 0xACDBFB);
		if (z < -20 && z >= -40)
			COL = mlx_get_color_value(t_fdf->mlx, 0x3300CC);
		if (z < -40)
			COL = mlx_get_color_value(t_fdf->mlx, 0x330066);
		if (z == 0)
			COL = mlx_get_color_value(t_fdf->mlx, 0x0978AB);
	}
}

void			ft_get_color(t_windata *t_fdf)
{
	int			a;
	char		*color;
	char		*hex_tmp;

	a = 0;
	color = 0;
	while (t_fdf->tab[I][J][a] != ',' && t_fdf->tab[I][J][a])
		a++;
	if (t_fdf->tab[I][J][a] == ',')
	{
		color = ft_strsub(t_fdf->tab[I][J], a + 3, 6);
		if (!(hex_tmp = ft_convert_base(color, BHEX, BDEC)))
			exit(0);
		COL = ft_atoi(hex_tmp);
		free(hex_tmp);
		free(color);
	}
	else
		COL = 0;
}

int				ft_hookevent(int keycode, t_windata *t_fdf)
{
	if (keycode == 53)
	{
		ft_free_struct(t_fdf);
		exit(0);
	}
	ft_f5(t_fdf);
	if (keycode == 24 || keycode == 69)
		ZOOM += (ZOOM < 200) ? 1 : 0;
	if (keycode == 27 || keycode == 78)
		ZOOM -= (ZOOM > 0) ? 1 : 0;
	if (keycode == 126 || keycode == 125)
		MOVUD += (keycode == 126) ? -20 : 20;
	if (keycode == 123 || keycode == 124)
		MOVLR += (keycode == 123) ? -20 : 20;
	if (keycode == 116 || keycode == 121)
		MOVALT += (keycode == 116) ? 1 : -1;
	if (keycode == 75 || keycode == 67)
		ANGLE += (keycode == 75) ? 0.1 : -0.1;
	if (keycode == 115 || keycode == 119)
		INCLI += (keycode == 119) ? 0.1 : -0.1;
	keycode == 49 ? ft_reset_position(t_fdf) : 0;
	return (0);
}
