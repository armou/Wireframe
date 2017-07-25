/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:02:40 by aoudin            #+#    #+#             */
/*   Updated: 2017/01/23 16:57:41 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		ft_write_data(t_windata *t_fdf)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;

	r = COL >> 0;
	g = COL >> 8;
	b = COL >> 16;
	DATA[t_fdf->y1 * t_fdf->size_line + t_fdf->x1 * (BPP / 8)] = r;
	DATA[t_fdf->y1 * t_fdf->size_line + t_fdf->x1 * (BPP / 8) + 1] = g;
	DATA[t_fdf->y1 * t_fdf->size_line + t_fdf->x1 * (BPP / 8) + 2] = b;
}

static	void	ft_bresenham(t_windata *t_fdf)
{
	int i;

	i = -1;
	while (++i <= t_fdf->longest)
	{
		ft_write_data(t_fdf);
		t_fdf->numerator += t_fdf->shortest;
		if (!(t_fdf->numerator < t_fdf->longest))
		{
			t_fdf->numerator -= t_fdf->longest;
			t_fdf->x1 += DX1;
			t_fdf->y1 += DY1;
		}
		else
		{
			t_fdf->x1 += DX2;
			t_fdf->y1 += DY2;
		}
	}
}

static void		ft_launch_algo(t_windata *t_fdf)
{
	DX1 = 0;
	DY1 = 0;
	DX2 = 0;
	DY2 = 0;
	DX1 = ((t_fdf->x2 - t_fdf->x1) < 0) ? -1 : 1;
	DY1 = ((t_fdf->y2 - t_fdf->y1) < 0) ? -1 : 1;
	DX2 = ((t_fdf->x2 - t_fdf->x1) < 0) ? -1 : 1;
	t_fdf->longest = abs(t_fdf->x2 - t_fdf->x1);
	t_fdf->shortest = abs(t_fdf->y2 - t_fdf->y1);
	if (!(t_fdf->longest > t_fdf->shortest))
	{
		t_fdf->longest = abs(t_fdf->y2 - t_fdf->y1);
		t_fdf->shortest = abs(t_fdf->x2 - t_fdf->x1);
		DY2 = ((t_fdf->y2 - t_fdf->y1) < 0) ? -1 : 1;
		DX2 = 0;
	}
	t_fdf->numerator = t_fdf->longest >> 1;
	ft_bresenham(t_fdf);
}

void			ft_algo(t_windata *t_fdf)
{
	t_fdf->x1 = ZOOM * (J * cos(ANGLE) - I * sin(ANGLE)) + (WIDTH / 2 + MOVLR);
	t_fdf->y1 = ZOOM * (INCLI * (J * sin(ANGLE) + I * cos(ANGLE)))
		- (Z1 * MOVALT) + (HEIGHT / 8 + MOVUD);
	t_fdf->x2 = ZOOM * (L * cos(ANGLE) - K * sin(ANGLE)) + (WIDTH / 2 + MOVLR);
	t_fdf->y2 = ZOOM * (INCLI * (L * sin(ANGLE) + K * cos(ANGLE)))
		- (Z2 * MOVALT) + (HEIGHT / 8 + MOVUD);
	if (t_fdf->x1 >= 0 && t_fdf->x1 <= WIDTH &&
				t_fdf->x2 >= 0 && t_fdf->x2 <= WIDTH &&
				t_fdf->y1 >= 0 && t_fdf->y1 <= HEIGHT &&
				t_fdf->y2 >= 0 && t_fdf->y2 <= HEIGHT)
		ft_launch_algo(t_fdf);
}
