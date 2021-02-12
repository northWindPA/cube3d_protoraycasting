/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:52:55 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/02/12 19:15:22 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		get_resolution(t_a *a, char **words)
{
	if ((loop_digit(words[1]) == 0) && (loop_digit(words[2]) == 0))
	{
		a->prc.s_w = ft_atoi(words[1]);
		if (a->prc.s_w < 0)
			return (error("Error\nNegative resolution!"));
		a->prc.s_h = ft_atoi(words[2]);
		if (a->prc.s_h < 0)
			return (error("Error\nNegative resolution!"));
		a->prc.s_w < 100 ? a->prc.s_w = 100 : 0;
		a->prc.s_h < 100 ? a->prc.s_h = 100 : 0;
		a->prc.s_w > 2560 ? a->prc.s_w = 2560 : 0;
		a->prc.s_h > 1440 ? a->prc.s_h = 1440 : 0;
	}
	else
		return (error("Error\nWrong resolution input!"));
	free_arr(words);
	return (0);
}

int		cube(t_a *a)
{
	double tmp_line[(int)a->prc.s_w];

	a->r.n_p_l = -1;
	displacement(a);
	a->d.img = mlx_new_image(a->d.mlx, a->prc.s_w, a->prc.s_h);
	a->d.add = mlx_get_data_addr(a->d.img, &a->d.bpp, &a->d.l_l, &a->d.endi);
	while (++a->r.n_p_l < a->prc.s_w)
	{
		raycast_initiation(a);
		raycast_correction(a);
		hit_identification(a);
		side_identification(a);
		line_height(a);
		floor_ceiling(a, 0, a->r.start, a->r.n_p_l);
		texture_wall(a, a->r.n_p_l);
		floor_ceiling(a, a->r.end, a->prc.s_h, a->r.n_p_l);
		tmp_line[a->r.n_p_l] = a->r.prp_w_dst;
	}
	draw_sprites(a, tmp_line);
	if (a->scrnst.flag == 0)
	{
		mlx_put_image_to_window(a->d.mlx, a->d.win, a->d.img, 0, 0);
		mlx_destroy_image(a->d.mlx, a->d.img);
	}
	return (0);
}

int		maze(t_a *a)
{
	if ((a->sp.sp = sprites_coordinates(a)) == 0)
		return (0);
	a->d.mlx = mlx_init();
	a->d.win = mlx_new_window(a->d.mlx, a->prc.s_w, a->prc.s_h, "maze");
	get_data_tex(a);
	mlx_hook(a->d.win, 2, 0, pressed, a);
	mlx_hook(a->d.win, 3, 0, unpressed, a);
	mlx_hook(a->d.win, 17, 0, escape, a);
	mlx_loop_hook(a->d.mlx, cube, a);
	mlx_loop(a->d.mlx);
	return (0);
}
