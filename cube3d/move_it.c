/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:26:02 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/01/29 21:28:24 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	key_forward(t_a *a)
{
	if (a->m.map[(int)(a->pl.pos_x + a->pl.dir_x *
	a->ray.movespeed)][(int)(a->pl.pos_y)] != '1')
		if (a->m.map[(int)(a->pl.pos_x + a->pl.dir_x *
		a->ray.movespeed)][(int)(a->pl.pos_y)] != '2')
			a->pl.pos_x += a->pl.dir_x * a->ray.movespeed;
	if (a->m.map[(int)(a->pl.pos_x)][(int)(a->pl.pos_y +
	a->pl.dir_y * a->ray.movespeed)] != '1')
		if (a->m.map[(int)(a->pl.pos_x)][(int)(a->pl.pos_y +
		a->pl.dir_y * a->ray.movespeed)] != '2')
			a->pl.pos_y += a->pl.dir_y * a->ray.movespeed;
}

void	key_back(t_a *a)
{
	if (a->m.map[(int)(a->pl.pos_x - a->pl.dir_x *
	a->ray.movespeed)][(int)(a->pl.pos_y)] != '1')
		if (a->m.map[(int)(a->pl.pos_x - a->pl.dir_x *
		a->ray.movespeed)][(int)(a->pl.pos_y)] != '2')
			a->pl.pos_x -= a->pl.dir_x * a->ray.movespeed;
	if (a->m.map[(int)(a->pl.pos_x)][(int)(a->pl.pos_y -
	a->pl.dir_y * a->ray.movespeed)] != '1')
		if (a->m.map[(int)(a->pl.pos_x)][(int)(a->pl.pos_y -
		a->pl.dir_y * a->ray.movespeed)] != '2')
			a->pl.pos_y -= a->pl.dir_y * a->ray.movespeed;
}

void	key_left(t_a *a)
{
	if (a->m.map[(int)(a->pl.pos_x - a->pl.dir_y *
	a->ray.movespeed)][(int)(a->pl.pos_y)] != '1')
		if (a->m.map[(int)(a->pl.pos_x - a->pl.dir_y *
		a->ray.movespeed)][(int)(a->pl.pos_y)] != '2')
			a->pl.pos_x -= a->pl.dir_y * a->ray.movespeed;
	if (a->m.map[(int)(a->pl.pos_x)][(int)(a->pl.pos_y +
	a->pl.dir_x * a->ray.movespeed)] != '1')
		if (a->m.map[(int)(a->pl.pos_x)][(int)(a->pl.pos_y +
		a->pl.dir_x * a->ray.movespeed)] != '2')
			a->pl.pos_y += a->pl.dir_x * a->ray.movespeed;
}

void	key_right(t_a *a)
{
	if (a->m.map[(int)(a->pl.pos_x + a->pl.dir_y *
	a->ray.movespeed)][(int)(a->pl.pos_y)] != '1')
		if (a->m.map[(int)(a->pl.pos_x + a->pl.dir_y *
		a->ray.movespeed)][(int)(a->pl.pos_y)] != '2')
			a->pl.pos_x += a->pl.dir_y * a->ray.movespeed;
	if (a->m.map[(int)(a->pl.pos_x)][(int)(a->pl.pos_y -
	a->pl.dir_x * a->ray.movespeed)] != '1')
		if (a->m.map[(int)(a->pl.pos_x)][(int)(a->pl.pos_y -
		a->pl.dir_x * a->ray.movespeed)] != '2')
			a->pl.pos_y -= a->pl.dir_x * a->ray.movespeed;
}
void	movement(t_a *a)
{
	if (a->move.moveflag1 == 1)
		key_forward(a);
	if (a->move.moveflag2 == 1)
		key_back(a);
	if (a->move.moveflag3 == 1)
		key_left(a);
	if (a->move.moveflag4 == 1)
		key_right(a);
	if (a->move.moveflag5 == 1)
		turn_left(a, 3);
	if (a->move.moveflag6 == 1)
		turn_right(a, 3);
}

int		key_flagoff(int key, t_a *a)
{
	if (key == 13)
		a->move.moveflag1 = 0;
	else if (key == 1)
		a->move.moveflag2 = 0;
	else if (key == 0)
		a->move.moveflag3 = 0;
	else if (key == 2)
		a->move.moveflag4 = 0;
	else if (key == 123)
		a->move.moveflag6 = 0;
	else if (key == 124)
		a->move.moveflag5 = 0;
	return (0);
}

int		key_flagon(int key, t_a *a)
{
	if (key == 13)
		a->move.moveflag1 = 1;
	else if (key == 1)
		a->move.moveflag2 = 1;
	else if (key == 0)
		a->move.moveflag3 = 1;
	else if (key == 2)
		a->move.moveflag4 = 1;
	else if (key == 123)
		a->move.moveflag6 = 1;
	else if (key == 124)
		a->move.moveflag5 = 1;
	else if (key == 53)
		esc_exit(a);
	return (0);
}