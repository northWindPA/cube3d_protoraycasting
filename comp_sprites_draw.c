/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_sprites_draw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:10:33 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/02/11 18:56:14 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	sprites_proc(t_a *a, int i)
{
	a->sp.sp_x = a->sp.sp[i][0] - a->pl.ps_x + 0.5;
	a->sp.sp_y = a->sp.sp[i][1] - a->pl.ps_y + 0.5;
	a->sp.invdt = 1.0 / (a->pl.pln_x
	* a->pl.dr_y - a->pl.dr_x * a->pl.pln_y);
	a->sp.dpth_x = a->sp.invdt
	* (a->pl.dr_y * a->sp.sp_x - a->pl.dr_x * a->sp.sp_y);
	a->sp.dpth_y = a->sp.invdt
	* (-a->pl.pln_y * a->sp.sp_x + a->pl.pln_x * a->sp.sp_y);
	a->sp.ps_on_s = (int)((a->prc.s_w / 2)
	* (1 + a->sp.dpth_x / a->sp.dpth_y));
}

void	sprites_correction(t_a *a)
{
	a->sp.sp_h = fabs((a->prc.s_h / (a->sp.dpth_y)));
	a->sp.start_x = -a->sp.sp_h / 2 + a->prc.s_h / 2;
	(a->sp.start_x < 0) ? a->sp.start_x = 0 : 0;
	a->sp.start_y = a->sp.sp_h / 2 + a->prc.s_h / 2;
	if (a->sp.start_y >= a->prc.s_h)
		a->sp.start_y = a->prc.s_h - 1;
	a->sp.sp_w = fabs((a->prc.s_h / (a->sp.dpth_y)));
	a->sp.end_y = -a->sp.sp_w / 2 + a->sp.ps_on_s;
	(a->sp.end_y < 0) ? a->sp.end_y = 0 : 0;
	a->sp.end_x = a->sp.sp_w / 2 + a->sp.ps_on_s;
	if (a->sp.end_x >= a->prc.s_w)
		a->sp.end_x = a->prc.s_w - 1;
}

void	sprites_line(t_a *a)
{
	int				y;
	int				x;
	unsigned int	clr;

	y = a->sp.start_x - 1;
	while (++y < a->sp.start_y)
	{
		x = y * 256 - a->prc.s_h
		* 128 + a->sp.sp_h * 128;
		a->sp.tx_y = ((x * a->tx.tx_h[4])
		/ a->sp.sp_h) / 256;
		clr = texture_color(a, a->sp.tx_x, a->sp.tx_y, 4);
		if ((clr & 0x00FFFFFF) != 0)
			my_pixel_put(a, a->sp.l_l, y, clr);
	}
}

void	draw_sprites(t_a *a, double *buffer_w)
{
	int	i;

	i = -1;
	a->sp.n_sp = number_sprites(a);
	sprites_srt(a->sp.n_sp, a);
	while (++i < a->sp.n_sp)
	{
		sprites_proc(a, i);
		sprites_correction(a);
		a->sp.l_l = a->sp.end_y - 1;
		while (++a->sp.l_l < a->sp.end_x)
		{
			a->sp.tx_x = (int)(256 * (a->sp.l_l
			- (-a->sp.sp_w / 2 + a->sp.ps_on_s))
			* a->tx.tx_w[4] / a->sp.sp_w) / 256;
			if (a->sp.dpth_y > 0 && a->sp.l_l > 0
			&& a->sp.l_l < a->prc.s_w && a->sp.dpth_y
			< buffer_w[a->sp.l_l])
				sprites_line(a);
		}
	}
}
