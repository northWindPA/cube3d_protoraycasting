/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:51:35 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/02/10 21:32:52 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	raycast_initiation(t_a *a)
{
	a->r.cmr = 2 * a->r.n_p_l / (double)a->prc.s_w - 1;
	a->r.r_dr_x = a->pl.dr_x + a->pl.pln_x * a->r.cmr;
	a->r.r_dr_y = a->pl.dr_y + a->pl.pln_y * a->r.cmr;
	a->r.m_x = (int)a->pl.ps_x;
	a->r.m_y = (int)a->pl.ps_y;
	if (a->r.r_dr_y == 0)
		a->r.dlt_d_x = 0;
	else if (a->r.r_dr_x == 0)
		a->r.dlt_d_x = 0;
	else
		a->r.dlt_d_x = fabs(1 / a->r.r_dr_x);
	if (a->r.r_dr_x == 0)
		a->r.dlt_d_y = 0;
	else if (a->r.r_dr_x == 0)
		a->r.dlt_d_y = 0;
	else
		a->r.dlt_d_y = fabs(1 / a->r.r_dr_y);
}

void	raycast_correction(t_a *a)
{
	a->r.hit = 0;
	if (a->r.r_dr_x < 0)
	{
		a->r.st_x = -1;
		a->r.sd_dst_x = (a->pl.ps_x - a->r.m_x) * a->r.dlt_d_x;
	}
	else
	{
		a->r.st_x = 1;
		a->r.sd_dst_x = (a->r.m_x + 1.0 - a->pl.ps_x) * a->r.dlt_d_x;
	}
	if (a->r.r_dr_y < 0)
	{
		a->r.st_y = -1;
		a->r.sd_dst_y = (a->pl.ps_y - a->r.m_y) * a->r.dlt_d_y;
	}
	else
	{
		a->r.st_y = 1;
		a->r.sd_dst_y = (a->r.m_y + 1.0 - a->pl.ps_y) * a->r.dlt_d_y;
	}
}

void	hit_identification(t_a *a)
{
	while (a->r.hit == 0)
	{
		if (a->r.sd_dst_x < a->r.sd_dst_y)
		{
			a->r.sd_dst_x += a->r.dlt_d_x;
			a->r.m_x += a->r.st_x;
			a->r.side = 0;
		}
		else
		{
			a->r.sd_dst_y += a->r.dlt_d_y;
			a->r.m_y += a->r.st_y;
			a->r.side = 1;
		}
		if (a->m.m[a->r.m_x][a->r.m_y] == '1')
			a->r.hit = 1;
	}
}

void	side_identification(t_a *a)
{
	if (a->r.side == 0)
		a->r.prp_w_dst = (a->r.m_x - a->pl.ps_x
		+ (1 - a->r.st_x) / 2) / a->r.r_dr_x;
	else
		a->r.prp_w_dst = (a->r.m_y - a->pl.ps_y
		+ (1 - a->r.st_y) / 2) / a->r.r_dr_y;
}
