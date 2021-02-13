/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_texture_proc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:17:02 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/02/13 22:54:30 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	floor_ceiling(t_a *a, int start, int end, int width)
{
	if (start == 0)
		while (start < end)
			my_pixel_put(a, width, start++, a->m.c);
	else
		while (start < end)
			my_pixel_put(a, width, start++, a->m.f);
}

void	texture_wall(t_a *a, int num_p_l)
{
	int	card_p;

	card_p = take_side(a);
	if (a->r.side == 0)
		a->tx.w_x = a->pl.ps_y + a->r.prp_w_dst * a->r.r_dr_y;
	else
		a->tx.w_x = a->pl.ps_x + a->r.prp_w_dst * a->r.r_dr_x;
	a->tx.w_x -= floor(a->tx.w_x);
	a->tx.tx_x = (int)(a->tx.w_x * (double)(a->tx.tx_w[card_p]));
	if (a->r.side == 0 && a->r.r_dr_x > 0)
		a->tx.tx_x = a->tx.tx_w[card_p] - a->tx.tx_x - 1;
	if (a->r.side == 1 && a->r.r_dr_y < 0)
		a->tx.tx_x = a->tx.tx_w[card_p] - a->tx.tx_x - 1;
	a->tx.stp = 1.0 * a->tx.tx_h[card_p] / a->r.l_h;
	a->tx.tx_ps = (a->r.start - a->prc.s_h / 2 + a->r.l_h / 2) * a->tx.stp;
	while (a->r.start < a->r.end)
	{
		a->tx.tx_y = (int)a->tx.tx_ps & (a->tx.tx_h[card_p] - 1);
		a->tx.tx_ps += a->tx.stp;
		my_pixel_put(a, num_p_l, a->r.start++,
		texture_color(a, a->tx.tx_x, a->tx.tx_y, card_p));
	}
}

void	get_data_tex(t_a *a)
{
	a->tx_d[0].img = mlx_xpm_file_to_image(a->d.mlx,
	a->m.w, &a->tx.tx_w[0], &a->tx.tx_h[0]);
	a->tx_d[0].add = mlx_get_data_addr(a->tx_d[0].img,
	&a->tx_d[0].bpp, &a->tx_d[0].l_l, &a->tx_d[0].endi);
	a->tx_d[1].img = mlx_xpm_file_to_image(a->d.mlx,
	a->m.n, &a->tx.tx_w[1], &a->tx.tx_h[1]);
	a->tx_d[1].add = mlx_get_data_addr(a->tx_d[1].img,
	&a->tx_d[1].bpp, &a->tx_d[1].l_l, &a->tx_d[1].endi);
	a->tx_d[2].img = mlx_xpm_file_to_image(a->d.mlx,
	a->m.e, &a->tx.tx_w[2], &a->tx.tx_h[2]);
	a->tx_d[2].add = mlx_get_data_addr(a->tx_d[2].img,
	&a->tx_d[2].bpp, &a->tx_d[2].l_l, &a->tx_d[2].endi);
	a->tx_d[3].img = mlx_xpm_file_to_image(a->d.mlx,
	a->m.s, &a->tx.tx_w[3], &a->tx.tx_h[3]);
	a->tx_d[3].add = mlx_get_data_addr(a->tx_d[3].img,
	&a->tx_d[3].bpp, &a->tx_d[3].l_l, &a->tx_d[3].endi);
	a->tx_d[4].img = mlx_xpm_file_to_image(a->d.mlx,
	a->m.sp, &a->tx.tx_w[4], &a->tx.tx_h[4]);
	a->tx_d[4].add = mlx_get_data_addr(a->tx_d[4].img,
	&a->tx_d[4].bpp, &a->tx_d[4].l_l, &a->tx_d[4].endi);
}

int		take_side(t_a *a)
{
	int	rtn;

	if (a->pl.ps_x >= a->r.m_x && a->pl.ps_y >= a->r.m_y)
		rtn = a->r.side == 1 ? 0 : 1;
	else if (a->pl.ps_x >= a->r.m_x && a->pl.ps_y <= a->r.m_y)
		rtn = a->r.side == 1 ? 2 : 1;
	else if (a->pl.ps_x <= a->r.m_x && a->pl.ps_y <= a->r.m_y)
		rtn = a->r.side == 1 ? 2 : 3;
	else
		rtn = a->r.side == 1 ? 0 : 3;
	return (rtn);
}

void	line_height(t_a *a)
{
	a->r.l_h = (int)(a->prc.s_h / a->r.prp_w_dst);
	a->r.start = -a->r.l_h / 2 + a->prc.s_h / 2;
	(a->r.start < 0) ? a->r.start = 0 : 0;
	a->r.end = a->r.l_h / 2 + a->prc.s_h / 2;
	(a->r.end >= a->prc.s_h) ? a->r.end = a->prc.s_h - 1 : 0;
}
