/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_sprites_dest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:10:18 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/02/10 21:40:40 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	sprites_srt(int amount, t_a *a)
{
	double	dst_f;
	double	dst_s;
	int		x;
	int		y;
	int		i;

	i = -1;
	while (++i < amount - 1)
	{
		dst_f = get_distance(a, i);
		dst_s = get_distance(a, i + 1);
		if (dst_f < dst_s)
		{
			x = a->sp.sp[i][0];
			y = a->sp.sp[i][1];
			a->sp.sp[i][0] = a->sp.sp[i + 1][0];
			a->sp.sp[i][1] = a->sp.sp[i + 1][1];
			a->sp.sp[i + 1][0] = x;
			a->sp.sp[i + 1][1] = y;
			i = -1;
		}
	}
}

double	get_distance(t_a *a, int j)
{
	return (((a->pl.ps_x - a->sp.sp[j][0])
	* (a->pl.ps_x - a->sp.sp[j][0])
	+ (a->pl.ps_y - a->sp.sp[j][1])
	* (a->pl.ps_y - a->sp.sp[j][1])));
}

int		number_sprites(t_a *a)
{
	int x;
	int y;
	int sprite_num;

	x = -1;
	sprite_num = 0;
	while (a->m.m[++x])
	{
		y = -1;
		while (a->m.m[x][++y])
		{
			if (a->m.m[x][y] == '2')
				sprite_num++;
		}
	}
	return (sprite_num);
}

int		**sprites_coordinates(t_a *a)
{
	int		**sp_coord;
	int		i;
	int		x;
	int		y;

	i = -1;
	x = -1;
	if ((sp_coord = (int **)ft_calloc(number_sprites(a)
	+ 1, sizeof(int *))) == 0)
		return (0);
	while (a->m.m[++x])
	{
		y = -1;
		while (a->m.m[x][++y])
		{
			if (a->m.m[x][y] == '2')
			{
				if ((sp_coord[++i] = ft_calloc(sizeof(int), 3)) == 0)
					return (0);
				sp_coord[i][0] = x;
				sp_coord[i][1] = y;
			}
		}
	}
	return (sp_coord);
}
