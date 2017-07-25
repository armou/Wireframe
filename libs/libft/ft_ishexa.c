/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:52:42 by aoudin            #+#    #+#             */
/*   Updated: 2017/01/24 13:38:49 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ishexa(char c)
{
	char	*str;
	int		i;

	i = -1;
	str = "0123456789ABCDEFabcdef";
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}