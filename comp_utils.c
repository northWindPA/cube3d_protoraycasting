/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:54:01 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/02/10 22:11:35 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void			free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

int				error(char *st)
{
	write(1, st, ft_strlen(st));
	write(1, "\n", 1);
	exit(1);
}

int				loop_digit(char *pr)
{
	int i;

	i = -1;
	while (pr[++i])
		if (!ft_isdigit(pr[i]))
			return (-1);
	return (0);
}

unsigned int	texture_color(t_a *a, int x, int y, int crd_p)
{
	char			*dst;
	unsigned int	color;

	dst = a->tx_d[crd_p].add
	+ (y * a->tx_d[crd_p].l_l
	+ x * (a->tx_d[crd_p].bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void			my_pixel_put(t_a *a, int x, int y, int color)
{
	char	*dst;

	dst = a->d.add + (y * a->d.l_l + x * (a->d.bpp / 8));
	*(unsigned int *)dst = color;
}
