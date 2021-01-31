/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:43:29 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/01/31 22:35:38 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cube3d.h"

void	struct_init(t_a *a)
{
	a->m.n = NULL;
	a->m.s = NULL;
	a->m.w = NULL;
	a->m.e = NULL;
	a->m.sp = NULL;
	a->m.f = 0;
	a->m.c = 0;
	a->f.fR = 0;
	a->f.fF = 0;
	a->f.fC = 0;
	a->r.movespeed = 0.1;
	a->r.rotspeed = 0.02;
	a->move.moveflag1 = 0;
	a->move.moveflag2 = 0;
	a->move.moveflag3 = 0;
	a->move.moveflag4 = 0;
	a->move.moveflag5 = 0;
	a->move.moveflag6 = 0;
}

//KEEEEEEEEEEEEEEEEEYYYYYYYYYYYYSSSSSSSSSSS

void	key_w(t_a *a)
{
	if (a->m.map[(int)(a->pl.pos_y)][(int)(a->pl.pos_x + a->pl.dir_x * a->r.movespeed)] != '2')
		if (a->m.map[(int)(a->pl.pos_y)][(int)(a->pl.pos_x + a->pl.dir_x * a->r.movespeed)] != '1')
			a->pl.pos_x += a->pl.dir_x * a->r.movespeed;
	if (a->m.map[(int)(a->pl.pos_y + a->pl.dir_y * a->r.movespeed)][(int)(a->pl.pos_x)] != '2')
		if (a->m.map[(int)(a->pl.pos_y + a->pl.dir_y * a->r.movespeed)][(int)(a->pl.pos_x)] != '1')
			a->pl.pos_y += a->pl.dir_y * a->r.movespeed;
}

void	key_s(t_a *a)
{
	if (a->m.map[(int)(a->pl.pos_y)][(int)(a->pl.pos_x - a->pl.dir_x * a->r.movespeed)] != '2')
		if (a->m.map[(int)(a->pl.pos_y)][(int)(a->pl.pos_x - a->pl.dir_x * a->r.movespeed)] != '1')
			a->pl.pos_x -= a->pl.dir_x * a->r.movespeed;
	if (a->m.map[(int)(a->pl.pos_y - a->pl.dir_y * a->r.movespeed)][(int)(a->pl.pos_x)] != '2')
		if (a->m.map[(int)(a->pl.pos_y - a->pl.dir_y * a->r.movespeed)][(int)(a->pl.pos_x)] != '1')
			a->pl.pos_y -= a->pl.dir_y * a->r.movespeed;
}

void	key_d(t_a *a)
{
	if (a->m.map[(int)(a->pl.pos_y)][(int)(a->pl.pos_x - a->pl.dir_y * a->r.movespeed)] != '2')
		if (a->m.map[(int)(a->pl.pos_y)][(int)(a->pl.pos_x - a->pl.dir_y * a->r.movespeed)] != '1')
			a->pl.pos_x -= a->pl.dir_y * a->r.movespeed;
	if (a->m.map[(int)(a->pl.pos_y + a->pl.dir_x * a->r.movespeed)][(int)(a->pl.pos_x)] != '2')
		if (a->m.map[(int)(a->pl.pos_y + a->pl.dir_x * a->r.movespeed)][(int)(a->pl.pos_x)] != '1')
			a->pl.pos_y += a->pl.dir_x * a->r.movespeed;
}

void	key_a(t_a *a)
{
	if (a->m.map[(int)(a->pl.pos_y)][(int)(a->pl.pos_x + a->pl.dir_y * a->r.movespeed)] != '2')
		if (a->m.map[(int)(a->pl.pos_y)][(int)(a->pl.pos_x + a->pl.dir_y * a->r.movespeed)] != '1')
			a->pl.pos_x += a->pl.dir_y * a->r.movespeed;
	if (a->m.map[(int)(a->pl.pos_y -a->pl.dir_x * a->r.movespeed)][(int)(a->pl.pos_x)] != '2')
		if (a->m.map[(int)(a->pl.pos_y - a->pl.dir_x * a->r.movespeed)][(int)(a->pl.pos_x)] != '1')
			a->pl.pos_y -= a->pl.dir_x * a->r.movespeed;
}

void	turn_left(t_a *a, int frequency)
{
	a->r.old_dirx = a->pl.dir_x;
	a->pl.dir_x = a->pl.dir_x * cos(a->r.rotspeed * frequency) - a->pl.dir_y * sin(a->r.rotspeed * frequency);
	a->pl.dir_y = a->r.old_dirx * sin(a->r.rotspeed * frequency) + a->pl.dir_y * cos(a->r.rotspeed * frequency);
	a->r.old_planex = a->pl.plane_x;
	a->pl.plane_x = a->pl.plane_x * cos(a->r.rotspeed * frequency) - a->pl.plane_y * sin(a->r.rotspeed * frequency);
	a->pl.plane_y = a->r.old_planex * sin(a->r.rotspeed * frequency) + a->pl.plane_y * cos(a->r.rotspeed * frequency);
}

void	turn_right(t_a *a, int frequency)
{
	a->r.old_dirx = a->pl.dir_x;
	a->pl.dir_x = a->pl.dir_x * cos(-a->r.rotspeed * frequency) - a->pl.dir_y * sin(-a->r.rotspeed * frequency);
	a->pl.dir_y = a->r.old_dirx * sin(-a->r.rotspeed * frequency) + a->pl.dir_y * cos(-a->r.rotspeed * frequency);
	a->r.old_planex = a->pl.plane_x;
	a->pl.plane_x = a->pl.plane_x * cos(-a->r.rotspeed * frequency) - a->pl.plane_y * sin(-a->r.rotspeed * frequency);
	a->pl.plane_y = a->r.old_planex * sin(-a->r.rotspeed * frequency) + a->pl.plane_y * cos(-a->r.rotspeed * frequency);
}

int		escape(t_a *a)
{
	int	i;

	i = 0;
	while (a->m.map[i])
		free(a->m.map[i++]);
	free(a->m.map);
	free(a->m.n);
	free(a->m.s);
	free(a->m.w);
	free(a->m.e);
	free(a->m.sp);
	exit(1);
	return (1);
}

void	movement(t_a *a)
{
	if (a->move.moveflag1 == 1)
		key_w(a);
	if (a->move.moveflag2 == 1)
		key_s(a);
	if (a->move.moveflag3 == 1)
		key_a(a);
	if (a->move.moveflag4 == 1)
		key_d(a);
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
	else if (key == 124)
		a->move.moveflag5 = 0;
	else if (key == 123)
		a->move.moveflag6 = 0;
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
	else if (key == 124)
		a->move.moveflag5 = 1;
	else if (key == 123)
		a->move.moveflag6 = 1;
	else if (key == 53)
		escape(a);
	return (0);
}

//KEEEEEEEEEEEEEEEEEYYYYYYYYYYYYSSSSSSSSSSS

void	freeall(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

int		error(char *st)
{
	write(1, st, ft_strlen(st));
	write(1, "\n", 1);
	exit(1);
}

int		loop_digit(char *pr)
{
	int i;

	i = -1;
	while (pr[++i])
		if (!ft_isdigit(pr[i]))
			return (-1);
	return (0);
}

//PARCE SPETICIFATORS

int		parce_res(t_a *a, char **w)
{
	if ((loop_digit(w[1]) == 0) && (loop_digit(w[2]) == 0))
	{
		a->screen_width = ft_atoi(w[1]);
		if (a->screen_width < 0)
			return (error("Negative resolution!"));
		a->screen_height = ft_atoi(w[2]);
		if (a->screen_height < 0)
			return (error("Negative resolution!"));
		a->screen_width < 100 ? a->screen_width = 100 : 0;
		a->screen_height < 100 ? a->screen_height = 100 : 0;
		a->screen_width > 2560 ? a->screen_width = 2560 : 0;
		a->screen_height > 1440 ? a->screen_height = 1440 : 0;
	}
	else
		return (error("Wrong resolution input!"));
	freeall(w);
	return (0);
}

int		parse_tex(t_a *a, char **w)
{
	int fd;

	fd = open(w[1], O_RDONLY);
	if (!ft_strncmp(w[0], "NO", 3)
	&& !(fd < 0) && a->m.n == NULL)
		a->m.n = ft_strdup(w[1]);
	else if (!ft_strncmp(w[0], "SO", 3)
	&& !(fd < 0) && a->m.s == NULL)
		a->m.s = ft_strdup(w[1]);
	else if (!ft_strncmp(w[0], "WE", 3)
	&& !(fd < 0) && a->m.w == NULL)
		a->m.w = ft_strdup(w[1]);
	else if (!ft_strncmp(w[0], "EA", 3)
	&& !(fd < 0) && a->m.e == NULL)
		a->m.e = ft_strdup(w[1]);
	else if (!ft_strncmp(w[0], "S", 2)
	&& !(fd < 0) && a->m.sp == NULL)
		a->m.sp = ft_strdup(w[1]);
	else
		return (error("Wrong path, specificator, texture!"));
	freeall(w);
	close(fd);
	return (0);
}

int		n_w(char **w)
{
	int i;

	i = 0;
	while (w[i])
		i++;
	return (i);
}

int		parse_fc(t_a *a, char **w)
{
	char **rgb;

	if (!ft_strncmp(w[0], "F", 2) && a->f.fF == 0)
	{
		rgb = ft_split(w[1], ',');
		if (n_w(rgb) == 3)
		{
			if (!loop_digit(rgb[0]) && !loop_digit(rgb[1]) && !loop_digit(rgb[2]))
			{
				if (ft_atoi(rgb[0]) <= 255 && ft_atoi(rgb[1]) <= 255 && ft_atoi(rgb[2]) <= 255
				&& ft_atoi(rgb[0]) >= 0 && ft_atoi(rgb[1]) >= 0 && ft_atoi(rgb[2]) >= 0)
				{
					a->m.f = (ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]));
					a->f.fF = 1;
				}
				else
					return (error("Wrong value of color!"));
			}
			else
				return (error("Wrong color!"));
		}
		else
			return (error("Wrong color args!"));
	}
	else if (!ft_strncmp(w[0], "C", 2) && a->f.fC == 0)
	{
		rgb = ft_split(w[1], ',');
		if (n_w(rgb) == 3)
		{
			if (!loop_digit(rgb[0]) && !loop_digit(rgb[1]) && !loop_digit(rgb[2]))
			{
				if (ft_atoi(rgb[0]) <= 255 && ft_atoi(rgb[1]) <= 255 && ft_atoi(rgb[2]) <= 255
				&& ft_atoi(rgb[0]) >= 0 && ft_atoi(rgb[1]) >= 0 && ft_atoi(rgb[2]) >= 0)
				{
					a->m.c = (ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]));
					a->f.fC = 1;
				}
				else
					return (error("Wrong value of color!"));
			}
			else
				return (error("Wrong color!"));
		}
		else
			return (error("Wrong color args!"));
	}
	else
		return (error("Wrong color specificator!"));
	freeall(rgb);
	freeall(w);
	return (0);
}

int		main_hub(char *line, t_a *a)
{
	char	**w;
	int		rt;

	w = ft_split(line, ' ');
	if (!ft_strncmp(w[0], "R", 2) && n_w(w) == 3 && a->f.fR == 0)
	{
		rt = parce_res(a, w);
		a->f.fR = 1;
	}
	else if (('N' == *w[0] || 'S' == *w[0] || 'W' == *w[0]
	|| 'E' == *w[0]) && n_w(w) == 2)
		rt = parse_tex(a, w);
	else if (('F' == *w[0] || 'C' == *w[0]) && n_w(w) == 2)
		rt = parse_fc(a, w);
	else
		return (error("Wrong specificator or args!"));
	return (rt);
}

//PARCE SPETICIFATORS

//PARCE MAP

int		spaces_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int		check_line(t_a *a, int i, int j)
{
	if (i > 0 && j > 0 && (j + 1) < ft_strlen(a->m.map[i]) && (i + 1) < a->number_lines)
	{
		if (j >= ft_strlen(a->m.map[i - 1]) || j >= ft_strlen(a->m.map[i + 1]))
			return(error("Map is not closed!"));
		if (a->m.map[i - 1][j] == ' ' || a->m.map[i + 1][j] == ' '
		|| a->m.map[i][j - 1] == ' ' ||  a->m.map[i][j + 1] == ' '
		|| a->m.map[i - 1][j - 1] == ' ' || a->m.map[i - 1][j + 1] == ' '
		|| a->m.map[i + 1][j - 1] == ' ' ||  a->m.map[i + 1][j + 1] == ' ')
			return(error("Map is not closed!"));
	}
	else
		return(error("Map is not closed!"));
	return (0);
}

int		player_dir(t_a *a, char direction, int y, int x)
{
	if (direction == 'S')
	{
		a->pl.dir_x = 0;
		a->pl.dir_y = 1;
		a->pl.plane_x = -0.66;
		a->pl.plane_y = 0;
	}
	if (direction == 'E')
	{
		a->pl.dir_x = 1;
		a->pl.dir_y = 0;
		a->pl.plane_x = 0;
		a->pl.plane_y = 0.66;
	}
	if (direction == 'W')
	{
		a->pl.dir_x = -1;
		a->pl.dir_y = 0;
		a->pl.plane_x = 0;
		a->pl.plane_y = -0.66;
	}
	if (direction == 'N')
	{
		a->pl.dir_x = 0;
		a->pl.dir_y = -1;
		a->pl.plane_x = 0.66;
		a->pl.plane_y = 0;
	}
	a->pl.pos_y = (int)y;
	a->pl.pos_x = (int)x;
	return (0);
}

int		val_map(t_a *a)
{
	int	y;
	int	x;

	y = 0;
	a->p_flag = 0;
	while(a->m.map[y])
	{
		x = 0;
		while(a->m.map[y][x])
		{
			if (a->m.map[y][x] == ' ' || a->m.map[y][x] == '1')
				x++;
			if (a->m.map[y][x] == '0' || a->m.map[y][x] == '2'
			|| a->m.map[y][x] == 'N' || a->m.map[y][x] == 'S'
			|| a->m.map[y][x] == 'W' || a->m.map[y][x] == 'E')
			{
				if (a->p_flag > 1)
					return(error("More than one player!"));
				if ((a->m.map[y][x] == 'N' || a->m.map[y][x] == 'S' || a->m.map[y][x] == 'W' || a->m.map[y][x] == 'E') && a->p_flag == 0)
				{
					a->p_flag++;
					player_dir(a, a->m.map[y][x], y, x);
				}
				check_line(a, y, x);
			}
			x++;
		}
		y++;
	}
	if (a->p_flag == 0)
		return(error("No player on map!"));
	return (0);
}

char	**make_map(t_list **head, int size, t_a *a)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *head;
	if(!(a->m.map = ft_calloc(size + 1, sizeof(char *))))
		return(0);
	while (tmp)
	{
		a->m.map[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	a->m.map[i] = NULL;
	ft_lstclear(head, &free);
	return (0);
}

int     val_line(char *line)
{
    while(*line != 0)
    {
        if (!(*line == 'W' || *line == 'E'
		|| *line == 'S' || *line == 'N'
        || *line == '1' || *line == '2'
		|| *line == '0' || *line == ' '))
            return (error("Wrong object in line of map!"));
        line++;
    }
    return (0);
}

char	**read_map(t_a *a, char *line)
{
	t_list		*head;

	head = NULL;
	val_line(line);
	(line[0] != '\0') ? ft_lstadd_back(&head, ft_lstnew(line)) : free(line);
	while (get_next_line(a->fd, &line) > 0)
	{
		val_line(line);
		(line[0] != '\0') ? ft_lstadd_back(&head, ft_lstnew(line)) : free(line);
	}
	(line[0] != '\0') ? ft_lstadd_back(&head, ft_lstnew(line)) : free(line);
	close(a->fd);
	a->number_lines = ft_lstsize(head);
	return (make_map(&head, a->number_lines, a));
}

//PARCE MAP

//RAYCAST

void	my_pixel_put(t_a *a, int x, int y, int color)
{
    char    *dst;

    dst = a->data.addr + (y * a->data.line_length + x * (a->data.bpp / 8));
    *(unsigned int *)dst = color;
}

int		cube(t_a *a)
{
    a->x = 0;

	movement(a);
    a->data.img = mlx_new_image(a->data.mlx, a->screen_width, a->screen_height);
    a->data.addr = mlx_get_data_addr(a->data.img, &a->data.bpp, &a->data.line_length, &a->data.endian);
    while (a->x < (float)a->screen_width)
    {
        a->r.camera = 2 * a->x / (double)a->screen_width - 1;
        a->r.ray_dirx = a->pl.dir_x + a->pl.plane_x * a->r.camera;
        a->r.ray_diry = a->pl.dir_y + a->pl.plane_y * a->r.camera;

        a->r.map_x = (int)a->pl.pos_x;
        a->r.map_y = (int)a->pl.pos_y;

        a->r.delta_distx = fabs(1 / a->r.ray_dirx);
        a->r.delta_disty = fabs(1 / a->r.ray_diry);

        a->r.hit = 0;
        if (a->r.ray_dirx < 0)
        {
            a->r.step_x = -1;
            a->r.side_dist_x = (a->pl.pos_x - a->r.map_x) * a->r.delta_distx;
        }
        else
        {
            a->r.step_x = 1;
            a->r.side_dist_x = (a->r.map_x + 1.0 - a->pl.pos_x) * a->r.delta_distx;
        }
        if (a->r.ray_diry < 0)
        {
            a->r.step_y = -1;
            a->r.side_dist_y = (a->pl.pos_y - a->r.map_y) * a->r.delta_disty;
        }
        else
        {
            a->r.step_y = 1;
            a->r.side_dist_y = (a->r.map_y + 1.0 - a->pl.pos_y) * a->r.delta_disty;
        }
        while (a->r.hit == 0)
        {
            if (a->r.side_dist_x < a->r.side_dist_y)
            {
                a->r.side_dist_x += a->r.delta_distx;
                a->r.map_x += a->r.step_x;
                a->r.side = 0;
            }
            else
            {
                a->r.side_dist_y += a->r.delta_disty;
                a->r.map_y += a->r.step_y;
                a->r.side = 1;
            }
            if (a->m.map[a->r.map_y][a->r.map_x] == '1')
                a->r.hit = 1;
        }
        if (a->r.side == 0)
            a->r.perp_wall_dist = (a->r.map_x - a->pl.pos_x + (1 - a->r.step_x) / 2) / a->r.ray_dirx;
        else
            a->r.perp_wall_dist = (a->r.map_y - a->pl.pos_y + (1 - a->r.step_y) / 2) / a->r.ray_diry;
        a->r.line_height = (int)(a->screen_height / a->r.perp_wall_dist);
        a->r.draw_start = -a->r.line_height / 2 + a->screen_height / 2;
        if (a->r.draw_start < 0)
            a->r.draw_start = 0;
        a->r.draw_end = a->r.line_height / 2 + a->screen_height / 2;
        if (a->r.draw_end >= a->screen_height)
            a->r.draw_end = a->screen_height - 1;
        while (a->r.draw_start < a->r.draw_end)
        {
            my_pixel_put(a, a->x, a->r.draw_start, 0xFFFFFF);
            a->r.draw_start++;
        }
        a->x++;
    }
    mlx_put_image_to_window(a->data.mlx, a->data.win, a->data.img, 0, 0);
    mlx_destroy_image(a->data.mlx, a->data.img);
	return (0);
}

//RAYCAST
int		parser(char **av)
{
	int i;
	int rt;
	t_a a;

	i = 0;
	struct_init(&a);
	a.fd = open(av[1], O_RDONLY);
	while (get_next_line(a.fd, &a.line) && i < 8)
	{
		if (!(a.line[0] == '\0') && !spaces_line(a.line))
		{
			i++;
			rt = main_hub(a.line, &a);
		}
		free(a.line);
	}
	read_map(&a, a.line);
	val_map(&a);
	close(a.fd);

   	a.data.mlx = mlx_init();
	a.data.win = mlx_new_window(a.data.mlx, a.screen_width, a.screen_height, "maze");
	a.data.img = mlx_new_image(a.data.mlx, a.screen_width, a.screen_height);
    a.data.addr = mlx_get_data_addr(a.data.img, &a.data.bpp, &a.data.line_length, &a.data.endian);
	mlx_hook(a.data.win, 2, 0, key_flagon, &a);
	mlx_hook(a.data.win, 17, 0, escape, &a);
	mlx_hook(a.data.win, 3, 0, key_flagoff, &a);
	mlx_loop_hook(a.data.mlx, cube, &a);
    mlx_loop(a.data.mlx);

	// TEST
	printf("|width:   %d|\n", a.screen_width);
	printf("|height:   %d|\n", a.screen_height);
	printf("|path_no: %s|\n", a.m.n);
	printf("|path_we: %s|\n", a.m.w);
	printf("|path_ea: %s|\n", a.m.e);
	printf("|path_so: %s|\n", a.m.s);
	printf("|path_sp: %s|\n", a.m.sp);
	printf("|f:       %d|\n", a.m.f);
	printf("|c:       %d|\n", a.m.c);
	printf("|r_flag:  %d|\n", a.f.fR);
	printf("|f_flag:  %d|\n", a.f.fF);
	printf("|c_flag:  %d|\n", a.f.fC);
	i = -1;
	while(a.m.map[++i])
		ft_putendl_fd(a.m.map[i], 1);
	printf("|number of lines:  %d|\n", a.number_lines);
	return (0);
}