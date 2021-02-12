/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_validators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:24:39 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/02/12 19:34:22 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		validate_line(char *line)
{
	while (*line != 0)
	{
		if (!(*line == 'W' || *line == 'E'
		|| *line == 'S' || *line == 'N'
		|| *line == '1' || *line == '2'
		|| *line == '0' || *line == ' '))
			return (error("Error\nWrong object in line of map!"));
		line++;
	}
	return (0);
}

int		validate_player(t_a *a, int x, int y)
{
	if (a->m.m[x][y] == '0' || a->m.m[x][y] == '2'
	|| a->m.m[x][y] == 'N' || a->m.m[x][y] == 'S'
	|| a->m.m[x][y] == 'W' || a->m.m[x][y] == 'E')
	{
		if (a->prc.pl_f > 1)
			return (error("Error\nMore than one player!"));
		if (a->m.m[x][y] == 'N'
		|| a->m.m[x][y] == 'S'
		|| a->m.m[x][y] == 'W'
		|| a->m.m[x][y] == 'E')
		{
			a->prc.pl_f++;
			player_dir(a, a->m.m[x][y], x, y);
		}
		check_line(a, x, y);
	}
	return (0);
}

int		validate_map(t_a *a)
{
	int	x;
	int	y;

	x = 0;
	while (a->m.m[x])
	{
		y = 0;
		while (a->m.m[x][y])
		{
			if (a->m.m[x][y] == ' ' || a->m.m[x][y] == '1')
				y++;
			validate_player(a, x, y);
			y++;
		}
		x++;
	}
	if (a->prc.pl_f == 0)
		return (error("Error\nNo player on map!"));
	return (0);
}

void	bmp_head(t_a *a, int h, int w)
{
	write(a->scrnst.fd, "BM", 2);
	write(a->scrnst.fd, &a->scrnst.size, 4);
	write(a->scrnst.fd, &a->scrnst.unsi_z, 2);
	write(a->scrnst.fd, &a->scrnst.unsi_z, 2);
	write(a->scrnst.fd, &a->scrnst.ppd_54, 4);
	write(a->scrnst.fd, &a->scrnst.ppd_40, 4);
	write(a->scrnst.fd, &w, 4);
	write(a->scrnst.fd, &h, 4);
	write(a->scrnst.fd, &a->scrnst.pln_1, 2);
	write(a->scrnst.fd, &a->d.bpp, 2);
	write(a->scrnst.fd, &a->scrnst.unsi_z, 4);
	write(a->scrnst.fd, &a->scrnst.unsi_z, 4);
	write(a->scrnst.fd, &a->scrnst.sign_z, 4);
	write(a->scrnst.fd, &a->scrnst.sign_z, 4);
	write(a->scrnst.fd, &a->scrnst.unsi_z, 4);
	write(a->scrnst.fd, &a->scrnst.unsi_z, 4);
}

int		get_screenshot(t_a *a)
{
	int h;
	int w;

	h = (int)a->prc.s_h;
	w = (int)a->prc.s_w;
	a->d.mlx = mlx_init();
	a->sp.sp = sprites_coordinates(a);
	get_data_tex(a);
	cube(a);
	a->scrnst.size = 54 + (int)a->prc.s_h * (int)a->prc.s_w * a->d.bpp;
	if ((a->scrnst.fd = open("screen.bmp",
	O_CREAT | O_RDWR | O_TRUNC, 0666)) < 0)
		error("Error\nCan't create screen.bmp!");
	bmp_head(a, h, w);
	while (h > 0)
	{
		h--;
		write(a->scrnst.fd, a->d.add + (h * a->d.l_l),
		((int)a->prc.s_w * (a->d.bpp / 8)));
	}
	close(a->scrnst.fd);
	exit(0);
}
