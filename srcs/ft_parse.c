/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:07:48 by aoudin            #+#    #+#             */
/*   Updated: 2017/01/24 15:40:41 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				ft_free_struct(t_windata *t_fdf)
{
	int		a;
	int		b;

	a = -1;
	while (++a < YMAX)
	{
		b = -1;
		while (++b < t_fdf->xmax)
			free(t_fdf->tab[a][b]);
		free(t_fdf->tab[a]);
	}
	mlx_destroy_image(t_fdf->mlx, t_fdf->img);
	t_fdf->mlx = NULL;
	t_fdf->win = NULL;
	t_fdf->img = NULL;
	free(t_fdf);
}

static int			ft_calc_x(char *str)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (str[i++])
	{
		if (str[i] == '\t')
			str[i] = ' ';
	}
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != ' ' && str[i])
		{
			x++;
			while (str[i] != ' ' && str[i])
				i++;
		}
	}
	return (x);
}

void				ft_parsefdf(t_windata *t_fdf, int fd)
{
	char	*line;

	t_fdf->ymax = 0;
	t_fdf->map = ft_strnew(BUFF_SIZE);
	while (get_next_line(fd, &line))
	{
		!t_fdf->xmax ? t_fdf->xmax = ft_calc_x(line) : 0;
		if (t_fdf->xmax != ft_calc_x(line) || !t_fdf->xmax)
			ft_exit(1);
		t_fdf->map = ft_strjoinfree(t_fdf->map, line);
		t_fdf->map = ft_strjoinfree(t_fdf->map, "\n");
		t_fdf->ymax++;
		free(line);
	}
	ft_splitmap(t_fdf);
	free(t_fdf->map);
}

static void			ft_display_bis(t_windata *t_fdf)
{
	K = 0;
	while (t_fdf->tab[++K])
	{
		I = K - 1;
		J = -1;
		while (t_fdf->tab[K][++J])
		{
			L = J;
			t_fdf->z2 = ft_atoi(t_fdf->tab[K][J]);
			t_fdf->z1 = ft_atoi(t_fdf->tab[I][J]);
			ft_get_color(t_fdf);
			ft_paint_color(t_fdf, MOVALT * ((Z1 > Z2) ? Z1 : Z2));
			ft_algo(t_fdf);
		}
	}
}

int					ft_display(t_windata *t_fdf)
{
	I = -1;
	while (t_fdf->tab[++I])
	{
		K = I;
		L = 0;
		while (t_fdf->tab[I][++L])
		{
			J = L - 1;
			t_fdf->z2 = ft_atoi(t_fdf->tab[I][L]);
			t_fdf->z1 = ft_atoi(t_fdf->tab[I][J]);
			ft_get_color(t_fdf);
			ft_paint_color(t_fdf, MOVALT * ((Z1 > Z2) ? Z1 : Z2));
			ft_algo(t_fdf);
		}
	}
	ft_display_bis(t_fdf);
	mlx_put_image_to_window(t_fdf->mlx, t_fdf->win, t_fdf->img, 0, 0);
	return (0);
}
