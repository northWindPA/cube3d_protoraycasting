/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:44:17 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/02/04 21:00:26 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>

typedef struct	s_parcer
{
	char		*line;
	int			number_lines;
	int			fd;
	double		screen_width;
	double		screen_height;
	int			player_flag;
	int			x;
}				t_parcer;

typedef struct	s_map
{
	char		**map;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	int			floor;
	int			ceiling;
	int			p_pos[2];
}				t_map;

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

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		prev_pos_x;
	double		prev_pos_y;
	int			pos_flag;
}				t_player;

typedef struct	s_move_flag
{
	int			move_forward;
	int			move_back;
	int			move_left;
	int			move_right;
	int			rotate_left;
	int			rotate_right;
}				t_move_flag;

typedef struct	s_raycast
{
	double		fov;
	double		width;
	double		height;
	double		map_height;
	double		map_width;
	int			map_x;
	int			map_y;
	double		ray_lenght_x;
	double		ray_lenght_y;
	double		dist_to_plane;
	int			step_x;
	int			step_y;
	int			side;
	double		delta_dist_x;
	double		delta_dist_y;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		camera;
	double		ray_dir_x;
	double		ray_dir_y;
	int			iterator;
	int			hit;
	double		movespeed;
	double		prev_dir_x;
	double		prev_plane_x;
	double		rotspeed;
	double      side_dist_x;
    double      side_dist_y;
	double      perp_wall_dist;
	double		*tmp_line2;
}				t_raycast;

typedef struct	s_texture
{
	int			height[5];
	int			width[5];
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	double		step;
}				t_texture;

typedef struct	s_texture_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_texture_data;

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

typedef struct	s_flag
{
	int			flag_resolution;
	int			flag_floor;
	int			flag_ceiling;

}				t_flag;


typedef struct	s_structures
{
	t_parcer		parcer;
	t_map			map;
	t_flag			flag;
	t_data			data;
	t_raycast		raycast;
	t_player		player;
	t_texture		texture;
	t_texture_data	texture_data[5];
	t_floor			floor;
	t_move_flag		move_flag;
	t_sprite		sprite;
}				t_structures;

int				parser(char **av);
void			my_pixel_put(t_structures *structures, int x, int y, int color);
unsigned int	texture_color(t_structures *structures, int x, int y, int cardinal_point);





#endif