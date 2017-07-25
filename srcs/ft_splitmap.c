/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 12:52:44 by aoudin            #+#    #+#             */
/*   Updated: 2017/01/24 15:51:03 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int			ft_check_hexa(char *str, int a, int b)
{
	if (str[a++] == ',' && str[a])
	{
		if (str[a] && str[a] == '0')
		{
			a++;
			if (str[a] && str[a] == 'x')
			{
				a++;
				while (str[a] && str[a] != ' ' && str[a] != '\n')
				{
					if (!ft_ishexa(str[a]))
						return (0);
					b++;
					a++;
				}
				if (b != 6)
					return (0);
			}
			else
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

static int			ft_validmap(t_windata *t_fdf)
{
	int			i;

	i = -1;
	if (t_fdf->map[0] == '\0')
		return (0);
	while (t_fdf->map[++i])
	{
		if (t_fdf->map[i] == '\n' || t_fdf->map[i] == ' ')
			i++;
		else if (t_fdf->map[i] == ',')
		{
			if (ft_check_hexa(t_fdf->map, i, 0) == 0)
				return (0);
			while (t_fdf->map[i] && t_fdf->map[i] != '\n'
					&& t_fdf->map[i] != ' ')
				i++;
		}
		else if (!ft_isdigit(t_fdf->map[i]) && t_fdf->map[i] != '-'
				&& t_fdf->map[i] != '+')
			return (0);
	}
	return (1);
}

void				ft_splitmap(t_windata *t_fdf)
{
	int			i;

	if (ft_validmap(t_fdf) == 0)
		ft_exit(1);
	!(t_fdf->tab = (char***)ft_memalloc(sizeof(char**) * (YMAX + 1))) ?
		ft_exit(1) : (t_fdf->split = ft_strsplit(t_fdf->map, '\n'));
	i = -1;
	while (t_fdf->split[++i])
	{
		!(t_fdf->tab[i] = ft_strsplit(t_fdf->split[i], ' ')) ? exit(0) :
			free(t_fdf->split[i]);
	}
	free(t_fdf->split);
}
