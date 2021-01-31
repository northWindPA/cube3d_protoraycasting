/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:44:17 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/01/31 21:39:51 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>

typedef struct	s_m
{
	char		*n;
	char		*s;
	char		*w;
	char		*e;
	char		*sp;
	int			f;
	int			c;
	char		**map;
	int			p_pos[2];
	int			save_flag;
}				t_m;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
}				t_data;

typedef struct	s_pl
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		old_xpos;
	double		old_ypos;
	int			pos_flag;
}				t_pl;

typedef struct	s_move
{
	int			moveflag1;
	int			moveflag2;
	int			moveflag3;
	int			moveflag4;
	int			moveflag5;
	int			moveflag6;
}				t_move;

typedef struct	s_r
{
	double		fov;
	double		width;
	double		height;
	double		map_height;
	double		map_width;
	int			map_x;
	int			map_y;
	double		xray_lenght;
	double		yray_lenght;
	double		ray_dist_to_plane;
	int			step_x;
	int			step_y;
	int			side;
	double		delta_distx;
	double		delta_disty;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		camera;
	double		ray_dirx;
	double		ray_diry;
	int			x;
	int			hit;
	double		movespeed;
	double		old_dirx;
	double		old_planex;
	double		rotspeed;
	double      side_dist_x;
    double      side_dist_y;
	double      perp_wall_dist;
}				t_r;

typedef struct	s_tex
{
	int			height[5];
	int			width[5];
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	double		step;
}				t_tex;

typedef struct	s_tex_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_tex_data;

typedef struct	s_floor
{
	float		ray_dir_x0;
	float		ray_dir_x1;
	float		ray_dir_y0;
	float		ray_dir_y1;
	int			horizon;
	float		pos_z;
	float		row_distance;
	float		floor_step_x;
	float		floor_step_y;
	float		floor_x;
	float		floor_y;
	int			cell_x;
	int			cell_y;
	int			tex_x;
	int			tex_y;
}				t_floor;

typedef struct	s_sprite
{
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		depth_x;
	double		depth_y;
	int			pos_on_screen;
	int			sprite_height;
	int			start_point_y;
	int			stop_point_y;
	int			start_point_x;
	int			stop_point_x;
	int			sprite_width;
	int			**sprite;
	int			stroke;
	int			tex_x;
	int			tex_y;
	int			sprite_num;
}				t_sprite;

typedef struct	s_f
{
	int			fR;
	int			fF;
	int			fC;

}				t_f;


typedef struct	s_a
{
	t_m			m;
	t_f			f;
	t_data		data;
	t_r			r;
	t_pl		pl;
	t_tex		tex;
	t_tex_data	tex_data[5];
	t_floor		floor;
	t_move		move;
	t_sprite	sprite;
	char		*line;
	int			number_lines;
	int			fd;
	int			screen_width;
	int			screen_height;
	int			p_flag;
	int			x;
}				t_a;

int		parser(char **av);





#endif