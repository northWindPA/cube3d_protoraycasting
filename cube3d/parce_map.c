/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 06:27:46 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/01/21 15:58:15 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "libft/libft.h"
#include "minilibx/mlx.h"

#define SCALE 10 // условный размер каждого квадратика в карте

typedef struct	s_win //структура для окна
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
	int			width;
	int			height;
}				t_win;

typedef struct	s_point // структура для точки
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_plr //структура для игрока и луча
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
}				t_plr;

typedef struct	s_all // структура для всего вместе
{
	t_win		*win;
	t_plr		*plr;
	char		**map;
}				t_all;

void	pixel_put(t_win *win, int x, int y, int color)
{
    char    *dst;

    dst = win->addr + (x * (win->bpp / 8) + y * win->line_l);
    *(int *)dst = color;
}

void	ft_init_player(char **map, t_plr *plr)
{
	t_point pos;

	ft_bzero(&pos, sizeof(t_point));
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (ft_strchr("NEWS", map[pos.y][pos.x]))
			{
				plr->x= pos.x * SCALE;
				plr->y= pos.y * SCALE;
				plr->dir = 3 * M_PI_2;
			}
			pos.x++;
		}
		pos.y++;
	}
}

char	**ft_make_map(t_list **head, int size)
{
	char	  **map = ft_calloc(size + 1, sizeof(char *));
	int		  i = 0;
	t_list	*tmp = *head;

	while (tmp)
	{
		map[i] = ft_strdup(tmp->content);
		i++;
		tmp= tmp->next;
	}
	i = 0;
	ft_lstclear(head, &free);
	return (map);
}

char    **ft_read_map(char *av1, t_plr *plr)
{
	char		*str = 0;
	t_list		*head = 0;
	int			amount = 0;
	const int	fd = open(av1, O_RDONLY);

	while (get_next_line(fd, &str) > 0)
	{
		ft_lstadd_back(&head, ft_lstnew(str)); 
		amount++;
		str = NULL;
	}
	close(fd);
	ft_lstadd_back(&head, ft_lstnew(str));
	amount++;
	return (ft_make_map(&head, amount));
}

void ft_drawline(t_all *all, int length_ray, int wall_x)
{
	all->win->width = 640;
	all->win->height = 480;
	if (length_ray <= 0)
		length_ray = 1;
	int wall_height = all->win->height * 4 / length_ray;
	int wall_start = all->win->height / 2 - wall_height / 2;
	while (wall_start <= (all->win->height / 2 + wall_height / 2))
	{
		pixel_put(all->win, wall_x, wall_start++, 0x990099);
	}
}

void	ft_draw_player(t_all *all, t_plr *pl)
{
	t_plr	plr = *all->plr;
	float length_ray = 0;
	int	wall_x = 0;

	plr.start = plr.dir - (M_PI / 6);
	plr.end = plr.dir + (M_PI / 6);
	while (plr.start <= plr.end)
	{
		plr.x = all->plr->x;
		plr.y = all->plr->y;
		while (all->map[(int)(plr.y / SCALE)][(int)(plr.x / SCALE)] != '1')
		{
			plr.x += cos(plr.start);
			plr.y += sin(plr.start);
			pixel_put(all->win, plr.x, plr.y, 0x990099);
			length_ray += 1;
		}
		ft_drawline(all, (int)length_ray, wall_x);
		wall_x += 1;
		length_ray = 0;
		plr.start += (M_PI / 6) / 320;
	}
	// t_point end;
	// t_plr	plr = *pl;

	// end.x = plr.x + SCALE;
	// end.y = plr.y + SCALE;
	// while (plr.y < end.y)
	// {
	// 	while (plr.x < end.x)
	// 		pixel_put(win->mlx, win->win, plr.x++, plr.y, 0x119911);
	// 	plr.x -= SCALE;
	// 	plr.y++;
	// }
}

void	ft_scale_img(t_win *win, t_point point, int color)
{
	t_point end;

	end.x = (point.x + 1) * SCALE;
	end.y = (point.y + 1) * SCALE;
	point.x *= SCALE;
	point.y *= SCALE;
	while (point.y < end.y)
	{
		while(point.x < end.x)
			pixel_put(win, point.x++, point.y, color);
		point.x -= SCALE;
		point.y++;
	}
}

void	draw_screen(t_all *all)
{
	t_point	point;
	t_win	*win = all->win;

	win->img = mlx_new_image(win->mlx,640, 480);
	win->addr = mlx_get_data_addr(win->img, &win->bpp, &win->line_l, &win->en);
	ft_bzero(&point, sizeof(t_point));
	while (all->map[point.y])
	{
		point.x = 0;
		while (all->map[point.y][point.x])
		{
			if (all->map[point.y][point.x] == '1')
				ft_scale_img(all->win, point, 0xFFFFFF);
			point.x++;
		}
		point.y++;
	}
	ft_draw_player(all, all->plr);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	mlx_destroy_image(win->mlx, win->img);
}

int	key_press(int key, t_all *all)
{
	mlx_clear_window(all->win->mlx, all->win->win);
	if (key == 13)
	{
		all->plr->y += sin(all->plr->dir) * 4;
		all->plr->x += cos(all->plr->dir) * 4;
	}
	if (key == 1)
	{
		all->plr->y -= sin(all->plr->dir) * 4;
		all->plr->x -= cos(all->plr->dir) * 4;
	}
	if (key == 0)
		all->plr->dir -= 0.1;
	if (key == 2)
		all->plr->dir += 0.1;
	if (key == 53)
		exit(0);
	draw_screen(all);
	return (0);
}

int	main(int ac, char **av)
{
	t_win	win;
	t_all	all;
	t_plr	plr;

	if (ac == 2)
		all.map = ft_read_map(av[1], &plr);
	// else
	// 	return (ft_putendl_fd("get map", 2));
	ft_init_player(all.map, &plr);
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 640, 480, "minimap");
	win.img = mlx_new_image(win.mlx, 640, 480);
	win.addr = mlx_get_data_addr(win.img, &win.bpp, &win.line_l, &win.en);
	all.plr = &plr;
	all.win = &win;
	draw_screen(&all);
	mlx_hook(win.win, 2, (1L << 0), &key_press, &all);
	mlx_loop(win.mlx);
}