/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:42:02 by aoudin            #+#    #+#             */
/*   Updated: 2017/10/18 20:18:21 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "../libs/minilibx_macos/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/X.h"

# define HEIGHT t_fdf->height
# define WIDTH t_fdf->width
# define BPP t_fdf->bpp
# define DATA t_fdf->data
# define DX1 t_fdf->dx1
# define DX2 t_fdf->dx2
# define DY1 t_fdf->dy1
# define DY2 t_fdf->dy2
# define I t_fdf->i
# define J t_fdf->j
# define K t_fdf->k
# define L t_fdf->l
# define Z1 t_fdf->z1
# define Z2 t_fdf->z2
# define ZOOM t_fdf->zoom
# define MOVLR t_fdf->movlr
# define MOVUD t_fdf->movud
# define MOVALT t_fdf->movalt
# define COL t_fdf->col
# define ANGLE t_fdf->angle
# define INCLI t_fdf->incli
# define YMAX t_fdf->ymax
# define FILENAME t_fdf->filename
# define BHEX "0123456789ABCDEF"
# define BDEC "0123456789"

typedef	struct			s_windata
{
	char				**split;
	char				*filename;
	int					bpp;
	int					endian;
	int					size_line;
	char				*data;
	void				*img;
	void				*mlx;
	void				*win;
	char				*map;
	char				***tab;
	int					xmax;
	int					ymax;
	int					zoom;
	int					z1;
	int					z2;
	int					x1;
	int					x2;
	int					y1;
	int					y2;
	int					dx1;
	int					dx2;
	int					dy1;
	int					dy2;
	int					longest;
	int					shortest;
	int					numerator;
	int					i;
	int					j;
	int					k;
	int					l;
	int					movlr;
	int					movud;
	int					movalt;
	int					width;
	int					height;
	int					col;
	float				angle;
	float				incli;
}						t_windata;

void					ft_init_image(t_windata *t_fdf);
void					ft_f5(t_windata *t_fdf);
void					ft_reset_position(t_windata *t_fdf);
void					ft_algo(t_windata *t_fdf);
void					ft_paint_color(t_windata *t_fdf, int z);
void					ft_get_color(t_windata *t_fdf);
int						ft_hookevent(int keycode, t_windata *t_fdf);
int						ft_display(t_windata *t_fdf);
void					ft_parsefdf(t_windata *t_fdf, int fd);
void					ft_exit(int i);
int						ft_destroy();
void					ft_free_struct(t_windata *t_fdf);
void					ft_splitmap(t_windata *t_fdf);

#endif
