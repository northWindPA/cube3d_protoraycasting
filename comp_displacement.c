/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_displacement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:50:51 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/02/10 19:16:58 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	right(t_a *a)
{
	if (a->m.m[(int)(a->pl.ps_x + a->pl.pln_x * a->r.mvspd)]
	[(int)(a->pl.ps_y)] != '2')
		if (a->m.m[(int)(a->pl.ps_x + a->pl.pln_x * a->r.mvspd)]
		[(int)(a->pl.ps_y)] != '1')
			a->pl.ps_x += a->pl.pln_x * a->r.mvspd;
	if (a->m.m[(int)(a->pl.ps_x)]
	[(int)(a->pl.ps_y + a->pl.pln_y * a->r.mvspd)] != '2')
		if (a->m.m[(int)(a->pl.ps_x)]
		[(int)(a->pl.ps_y + a->pl.pln_y * a->r.mvspd)] != '1')
			a->pl.ps_y += a->pl.pln_y * a->r.mvspd;
}

void	left(t_a *a)
{
	if (a->m.m[(int)(a->pl.ps_x - a->pl.pln_x * a->r.mvspd)]
	[(int)(a->pl.ps_y)] != '2')
		if (a->m.m[(int)(a->pl.ps_x - a->pl.pln_x * a->r.mvspd)]
		[(int)(a->pl.ps_y)] != '1')
			a->pl.ps_x -= a->pl.pln_x * a->r.mvspd;
	if (a->m.m[(int)(a->pl.ps_x)]
	[(int)(a->pl.ps_y - a->pl.pln_y * a->r.mvspd)] != '2')
		if (a->m.m[(int)(a->pl.ps_x)]
		[(int)(a->pl.ps_y - a->pl.pln_y * a->r.mvspd)] != '1')
			a->pl.ps_y -= a->pl.pln_y * a->r.mvspd;
}

void	forward(t_a *a)
{
	if (a->m.m[(int)(a->pl.ps_x - a->pl.pln_y * a->r.mvspd)]
	[(int)(a->pl.ps_y)] != '2')
		if (a->m.m[(int)(a->pl.ps_x - a->pl.pln_y * a->r.mvspd)]
		[(int)(a->pl.ps_y)] != '1')
			a->pl.ps_x -= a->pl.pln_y * a->r.mvspd;
	if (a->m.m[(int)(a->pl.ps_x)]
	[(int)(a->pl.ps_y + a->pl.pln_x * a->r.mvspd)] != '2')
		if (a->m.m[(int)(a->pl.ps_x)]
		[(int)(a->pl.ps_y + a->pl.pln_x * a->r.mvspd)] != '1')
			a->pl.ps_y += a->pl.pln_x * a->r.mvspd;
}

void	back(t_a *a)
{
	if (a->m.m[(int)(a->pl.ps_x + a->pl.pln_y * a->r.mvspd)]
	[(int)(a->pl.ps_y)] != '2')
		if (a->m.m[(int)(a->pl.ps_x + a->pl.pln_y * a->r.mvspd)]
		[(int)(a->pl.ps_y)] != '1')
			a->pl.ps_x += a->pl.pln_y * a->r.mvspd;
	if (a->m.m[(int)(a->pl.ps_x)]
	[(int)(a->pl.ps_y - a->pl.pln_x * a->r.mvspd)] != '2')
		if (a->m.m[(int)(a->pl.ps_x)]
		[(int)(a->pl.ps_y - a->pl.pln_x * a->r.mvspd)] != '1')
			a->pl.ps_y -= a->pl.pln_x * a->r.mvspd;
}

void	rotate_left(t_a *a)
{
	a->r.prv_dr_x = a->pl.dr_x;
	a->pl.dr_x = a->pl.dr_x *
	cos(-a->r.rtspd) - a->pl.dr_y * sin(-a->r.rtspd);
	a->pl.dr_y = a->r.prv_dr_x *
	sin(-a->r.rtspd) + a->pl.dr_y * cos(-a->r.rtspd);
	a->r.prv_pln_x = a->pl.pln_x;
	a->pl.pln_x = a->pl.pln_x *
	cos(-a->r.rtspd) - a->pl.pln_y * sin(-a->r.rtspd);
	a->pl.pln_y = a->r.prv_pln_x *
	sin(-a->r.rtspd) + a->pl.pln_y * cos(-a->r.rtspd);
}
