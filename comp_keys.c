/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:15:04 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/02/10 19:21:16 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		escape(t_a *a)
{
	int	i;

	i = 0;
	while (a->m.m[i])
		free(a->m.m[i++]);
	free(a->m.m);
	free(a->m.n);
	free(a->m.s);
	free(a->m.w);
	free(a->m.e);
	free(a->m.sp);
	exit(1);
	return (1);
}

void	displacement(t_a *a)
{
	if (a->mv_f.mv_f == 1)
		forward(a);
	if (a->mv_f.mv_b == 1)
		back(a);
	if (a->mv_f.mv_l == 1)
		left(a);
	if (a->mv_f.mv_r == 1)
		right(a);
	if (a->mv_f.rtt_l == 1)
		rotate_left(a);
	if (a->mv_f.rtt_r == 1)
		rotate_right(a);
	if (a->mv_f.spd_up == 1)
		a->r.mvspd = 0.2;
	else
		a->r.mvspd = 0.1;
}

int		unpressed(int key, t_a *a)
{
	if (key == 13)
		a->mv_f.mv_f = 0;
	if (key == 1)
		a->mv_f.mv_b = 0;
	if (key == 0)
		a->mv_f.mv_l = 0;
	if (key == 2)
		a->mv_f.mv_r = 0;
	if (key == 124)
		a->mv_f.rtt_l = 0;
	if (key == 123)
		a->mv_f.rtt_r = 0;
	if (key == 257)
		a->mv_f.spd_up = 0;
	return (0);
}

int		pressed(int key, t_a *a)
{
	if (key == 13)
		a->mv_f.mv_f = 1;
	if (key == 1)
		a->mv_f.mv_b = 1;
	if (key == 0)
		a->mv_f.mv_l = 1;
	if (key == 2)
		a->mv_f.mv_r = 1;
	if (key == 124)
		a->mv_f.rtt_l = 1;
	if (key == 123)
		a->mv_f.rtt_r = 1;
	if (key == 257)
		a->mv_f.spd_up = 1;
	if (key == 53)
		escape(a);
	return (0);
}

void	rotate_right(t_a *a)
{
	a->r.prv_dr_x = a->pl.dr_x;
	a->pl.dr_x = a->pl.dr_x *
	cos(a->r.rtspd) - a->pl.dr_y * sin(a->r.rtspd);
	a->pl.dr_y = a->r.prv_dr_x *
	sin(a->r.rtspd) + a->pl.dr_y * cos(a->r.rtspd);
	a->r.prv_pln_x = a->pl.pln_x;
	a->pl.pln_x = a->pl.pln_x *
	cos(a->r.rtspd) - a->pl.pln_y * sin(a->r.rtspd);
	a->pl.pln_y = a->r.prv_pln_x *
	sin(a->r.rtspd) + a->pl.pln_y * cos(a->r.rtspd);
}
