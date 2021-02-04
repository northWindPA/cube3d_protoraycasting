/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:43:29 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/02/04 21:04:42 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cube3d.h"

void	struct_init(t_structures *structures)
{
	structures->map.north = NULL;
	structures->map.south = NULL;
	structures->map.west = NULL;
	structures->map.east = NULL;
	structures->map.sprite = NULL;
	structures->map.floor = 0;
	structures->map.ceiling = 0;
	structures->flag.flag_resolution = 0;
	structures->flag.flag_floor = 0;
	structures->flag.flag_ceiling = 0;
	structures->raycast.movespeed = 0.1;
	structures->raycast.rotspeed = 0.1;
	structures->move_flag.move_forward = 0;
	structures->move_flag.move_back = 0;
	structures->move_flag.move_left = 0;
	structures->move_flag.move_right = 0;
	structures->move_flag.rotate_left = 0;
	structures->move_flag.rotate_right = 0;
}

//KEEEEEEEEEEEEEEEEEYYYYYYYYYYYYSSSSSSSSSSS

void	forward(t_structures *structures)
{
	if (structures->map.map[(int)(structures->player.pos_x + structures->player.dir_x * structures->raycast.movespeed)][(int)(structures->player.pos_y)] != '2')
		if (structures->map.map[(int)(structures->player.pos_x + structures->player.dir_x * structures->raycast.movespeed)][(int)(structures->player.pos_y)] != '1')
			structures->player.pos_x += structures->player.dir_x * structures->raycast.movespeed;
	if (structures->map.map[(int)(structures->player.pos_x)][(int)(structures->player.pos_y + structures->player.dir_y * structures->raycast.movespeed)] != '2')
		if (structures->map.map[(int)(structures->player.pos_x)][(int)(structures->player.pos_y + structures->player.dir_y * structures->raycast.movespeed)] != '1')
			structures->player.pos_y += structures->player.dir_y * structures->raycast.movespeed;
}

void	back(t_structures *structures)
{
	if (structures->map.map[(int)(structures->player.pos_x - structures->player.dir_x * structures->raycast.movespeed)] [(int)(structures->player.pos_y)]!= '2')
		if (structures->map.map[(int)(structures->player.pos_x - structures->player.dir_x * structures->raycast.movespeed)][(int)(structures->player.pos_y)] != '1')
			structures->player.pos_x -= structures->player.dir_x * structures->raycast.movespeed;
	if (structures->map.map[(int)(structures->player.pos_x)][(int)(structures->player.pos_y - structures->player.dir_y * structures->raycast.movespeed)] != '2')
		if (structures->map.map[(int)(structures->player.pos_x)][(int)(structures->player.pos_y - structures->player.dir_y * structures->raycast.movespeed)] != '1')
			structures->player.pos_y -= structures->player.dir_y * structures->raycast.movespeed;
}

void	left(t_structures *structures)
{
	if (structures->map.map[(int)(structures->player.pos_x - structures->player.dir_y * structures->raycast.movespeed)][(int)(structures->player.pos_y)] != '2')
		if (structures->map.map[(int)(structures->player.pos_x - structures->player.dir_y * structures->raycast.movespeed)][(int)(structures->player.pos_y)] != '1')
			structures->player.pos_x -= structures->player.dir_y * structures->raycast.movespeed;
	if (structures->map.map[(int)(structures->player.pos_x)][(int)(structures->player.pos_y + structures->player.dir_x * structures->raycast.movespeed)] != '2')
		if (structures->map.map[(int)(structures->player.pos_x)][(int)(structures->player.pos_y + structures->player.dir_x * structures->raycast.movespeed)] != '1')
			structures->player.pos_y += structures->player.dir_x * structures->raycast.movespeed;
}

void	right(t_structures *structures)
{
	if (structures->map.map[(int)(structures->player.pos_x + structures->player.dir_y * structures->raycast.movespeed)][(int)(structures->player.pos_y)] != '2')
		if (structures->map.map[(int)(structures->player.pos_x + structures->player.dir_y * structures->raycast.movespeed)][(int)(structures->player.pos_y)] != '1')
			structures->player.pos_x += structures->player.dir_y * structures->raycast.movespeed;
	if (structures->map.map[(int)(structures->player.pos_x)][(int)(structures->player.pos_y -structures->player.dir_x * structures->raycast.movespeed)] != '2')
		if (structures->map.map[(int)(structures->player.pos_x)][(int)(structures->player.pos_y - structures->player.dir_x * structures->raycast.movespeed)] != '1')
			structures->player.pos_y -= structures->player.dir_x * structures->raycast.movespeed;
}

void	rotate_left(t_structures *structures)
{
	structures->raycast.prev_dir_x = structures->player.dir_x;
	structures->player.dir_x = structures->player.dir_x * cos(-structures->raycast.rotspeed) - structures->player.dir_y * sin(-structures->raycast.rotspeed);
	structures->player.dir_y = structures->raycast.prev_dir_x * sin(-structures->raycast.rotspeed) + structures->player.dir_y * cos(-structures->raycast.rotspeed);
	structures->raycast.prev_plane_x = structures->player.plane_x;
	structures->player.plane_x = structures->player.plane_x * cos(-structures->raycast.rotspeed) - structures->player.plane_y * sin(-structures->raycast.rotspeed);
	structures->player.plane_y = structures->raycast.prev_plane_x * sin(-structures->raycast.rotspeed) + structures->player.plane_y * cos(-structures->raycast.rotspeed);
}

void	rotate_right(t_structures *structures)
{
	structures->raycast.prev_dir_x = structures->player.dir_x;
	structures->player.dir_x = structures->player.dir_x * cos(structures->raycast.rotspeed) - structures->player.dir_y * sin(structures->raycast.rotspeed);
	structures->player.dir_y = structures->raycast.prev_dir_x * sin(structures->raycast.rotspeed) + structures->player.dir_y * cos(structures->raycast.rotspeed);
	structures->raycast.prev_plane_x = structures->player.plane_x;
	structures->player.plane_x = structures->player.plane_x * cos(structures->raycast.rotspeed) - structures->player.plane_y * sin(structures->raycast.rotspeed);
	structures->player.plane_y = structures->raycast.prev_plane_x * sin(structures->raycast.rotspeed) + structures->player.plane_y * cos(structures->raycast.rotspeed);
}

int		escape(t_structures *structures)
{
	int	i;

	i = 0;
	while (structures->map.map[i])
		free(structures->map.map[i++]);
	free(structures->map.map);
	free(structures->map.north);
	free(structures->map.south);
	free(structures->map.west);
	free(structures->map.east);
	free(structures->map.sprite);
	exit(1);
	return (1);
}

void	displacement(t_structures *structures)
{
	if (structures->move_flag.move_forward == 1)
		forward(structures);
	if (structures->move_flag.move_back == 1)
		back(structures);
	if (structures->move_flag.move_left == 1)
		left(structures);
	if (structures->move_flag.move_right == 1)
		right(structures);
	if (structures->move_flag.rotate_left == 1)
		rotate_left(structures);
	if (structures->move_flag.rotate_right == 1)
		rotate_right(structures);
}

int		unpressed(int key, t_structures *structures)
{
	if (key == 13)
		structures->move_flag.move_forward = 0;
	else if (key == 1)
		structures->move_flag.move_back = 0;
	else if (key == 0)
		structures->move_flag.move_left = 0;
	else if (key == 2)
		structures->move_flag.move_right = 0;
	else if (key == 124)
		structures->move_flag.rotate_left = 0;
	else if (key == 123)
		structures->move_flag.rotate_right = 0;
	return (0);
}

int		pressed(int key, t_structures *structures)
{
	if (key == 13)
		structures->move_flag.move_forward = 1;
	else if (key == 1)
		structures->move_flag.move_back = 1;
	else if (key == 0)
		structures->move_flag.move_left = 1;
	else if (key == 2)
		structures->move_flag.move_right = 1;
	else if (key == 124)
		structures->move_flag.rotate_left = 1;
	else if (key == 123)
		structures->move_flag.rotate_right = 1;
	else if (key == 53)
		escape(structures);
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

//PARCE SPETICIFICATORS

int		get_resolution(t_structures *structures, char **words)
{
	if ((loop_digit(words[1]) == 0) && (loop_digit(words[2]) == 0))
	{
		structures->parcer.screen_width = ft_atoi(words[1]);
		if (structures->parcer.screen_width < 0)
			return (error("Negative resolution!"));
		structures->parcer.screen_height = ft_atoi(words[2]);
		if (structures->parcer.screen_height < 0)
			return (error("Negative resolution!"));
		structures->parcer.screen_width < 100 ? structures->parcer.screen_width = 100 : 0;
		structures->parcer.screen_height < 100 ? structures->parcer.screen_height = 100 : 0;
		structures->parcer.screen_width > 2560 ? structures->parcer.screen_width = 2560 : 0;
		structures->parcer.screen_height > 1440 ? structures->parcer.screen_height = 1440 : 0;
	}
	else
		return (error("Wrong resolution input!"));
	freeall(words);
	return (0);
}

int		parse_textures(t_structures *structures, char **words)
{
	int fd;

	fd = open(words[1], O_RDONLY);
	if (!ft_strncmp(words[0], "NO", 3)
	&& !(fd < 0) && structures->map.north == NULL)
		structures->map.north = ft_strdup(words[1]);
	else if (!ft_strncmp(words[0], "SO", 3)
	&& !(fd < 0) && structures->map.south == NULL)
		structures->map.south = ft_strdup(words[1]);
	else if (!ft_strncmp(words[0], "WE", 3)
	&& !(fd < 0) && structures->map.west == NULL)
		structures->map.west = ft_strdup(words[1]);
	else if (!ft_strncmp(words[0], "EA", 3)
	&& !(fd < 0) && structures->map.east == NULL)
		structures->map.east = ft_strdup(words[1]);
	else if (!ft_strncmp(words[0], "S", 2)
	&& !(fd < 0) && structures->map.sprite == NULL)
		structures->map.sprite = ft_strdup(words[1]);
	else
		return (error("Wrong path, specificator, texture!"));
	freeall(words);
	close(fd);
	return (0);
}

int		number_words(char **words)
{
	int i;

	i = 0;
	while (words[i])
		i++;
	return (i);
}

int		parse_fc(t_structures *structures, char **words)
{
	char **rgb;

	if (!ft_strncmp(words[0], "F", 2) && structures->flag.flag_floor == 0)
	{
		rgb = ft_split(words[1], ',');
		if (number_words(rgb) == 3)
		{
			if (!loop_digit(rgb[0]) && !loop_digit(rgb[1]) && !loop_digit(rgb[2]))
			{
				if (ft_atoi(rgb[0]) <= 255 && ft_atoi(rgb[1]) <= 255 && ft_atoi(rgb[2]) <= 255
				&& ft_atoi(rgb[0]) >= 0 && ft_atoi(rgb[1]) >= 0 && ft_atoi(rgb[2]) >= 0)
				{
					structures->map.floor = (ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]));
					structures->flag.flag_floor = 1;
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
	else if (!ft_strncmp(words[0], "C", 2) && structures->flag.flag_ceiling == 0)
	{
		rgb = ft_split(words[1], ',');
		if (number_words(rgb) == 3)
		{
			if (!loop_digit(rgb[0]) && !loop_digit(rgb[1]) && !loop_digit(rgb[2]))
			{
				if (ft_atoi(rgb[0]) <= 255 && ft_atoi(rgb[1]) <= 255 && ft_atoi(rgb[2]) <= 255
				&& ft_atoi(rgb[0]) >= 0 && ft_atoi(rgb[1]) >= 0 && ft_atoi(rgb[2]) >= 0)
				{
					structures->map.ceiling = (ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]));
					structures->flag.flag_ceiling = 1;
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
	freeall(words);
	return (0);
}

int		get_parameters(char *line, t_structures *structures)
{
	char	**words;
	int		rt;

	words = ft_split(line, ' ');
	if (!ft_strncmp(words[0], "R", 2) && number_words(words) == 3 && structures->flag.flag_resolution == 0)
	{
		rt = get_resolution(structures, words);
		structures->flag.flag_resolution = 1;
	}
	else if (('N' == *words[0] || 'S' == *words[0] || 'W' == *words[0]
	|| 'E' == *words[0]) && number_words(words) == 2)
		rt = parse_textures(structures, words);
	else if (('F' == *words[0] || 'C' == *words[0]) && number_words(words) == 2)
		rt = parse_fc(structures, words);
	else
		return (error("Wrong specificator or args!"));
	return (rt);
}

//PARCE SPETICIFICATORS

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

int		check_line(t_structures *structures, int x, int y)
{
	if (x > 0 && y > 0 && (y + 1) < ft_strlen(structures->map.map[x]) && (x + 1) < structures->parcer.number_lines)
	{
		if (y >= ft_strlen(structures->map.map[x - 1]) || y >= ft_strlen(structures->map.map[x + 1]))
			return(error("Map is not closed!"));
		if (structures->map.map[x - 1][y] == ' ' || structures->map.map[x + 1][y] == ' '
		|| structures->map.map[x][y - 1] == ' ' ||  structures->map.map[x][y + 1] == ' '
		|| structures->map.map[x - 1][y - 1] == ' ' || structures->map.map[x - 1][y + 1] == ' '
		|| structures->map.map[x + 1][y - 1] == ' ' ||  structures->map.map[x + 1][y + 1] == ' ')
			return(error("Map is not closed!"));
	}
	else
		return(error("Map is not closed!"));
	return (0);
}

int		player_dir(t_structures *structures, char direction, int x, int y)
{
	if (direction == 'N')
	{
		structures->player.dir_x = -1;
		structures->player.dir_y = 0;
		structures->player.plane_x = 0;
		structures->player.plane_y = 0.66;
	}
	if (direction == 'S')
	{
		structures->player.dir_x = 1;
		structures->player.dir_y = 0;
		structures->player.plane_x = 0;
		structures->player.plane_y = -0.66;
	}
	if (direction == 'E')
	{
		structures->player.dir_x = 0;
		structures->player.dir_y = 1;
		structures->player.plane_x = 0.66;
		structures->player.plane_y = 0;
	}
	if (direction == 'W')
	{
		structures->player.dir_x = 0;
		structures->player.dir_y = -1;
		structures->player.plane_x = -0.66;
		structures->player.plane_y = 0;
	}
	structures->player.pos_x = (int)x;
	structures->player.pos_y = (int)y;
	return (0);
}

int		validate_map(t_structures *structures)
{
	int	x;
	int	y;

	x = 0;
	structures->parcer.player_flag = 0;
	while(structures->map.map[x])
	{
		y = 0;
		while(structures->map.map[x][y])
		{
			if (structures->map.map[x][y] == ' ' || structures->map.map[x][y] == '1')
				y++;
			if (structures->map.map[x][y] == '0' || structures->map.map[x][y] == '2'
			|| structures->map.map[x][y] == 'N' || structures->map.map[x][y] == 'S'
			|| structures->map.map[x][y] == 'W' || structures->map.map[x][y] == 'E')
			{
				if (structures->parcer.player_flag > 1)
					return(error("More than one player!"));
				if ((structures->map.map[x][y] == 'N' || structures->map.map[x][y] == 'S' || structures->map.map[x][y] == 'W' || structures->map.map[x][y] == 'E') && structures->parcer.player_flag == 0)
				{
					structures->parcer.player_flag++;
					player_dir(structures, structures->map.map[x][y], x, y);
				}
				check_line(structures, x, y);
			}
			y++;
		}
		x++;
	}
	if (structures->parcer.player_flag == 0)
		return(error("No player on map!"));
	return (0);
}

char	**make_map(t_list **head, int size, t_structures *structures)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *head;
	if(!(structures->map.map = ft_calloc(size + 1, sizeof(char *))))
		return(0);
	while (tmp)
	{
		structures->map.map[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	structures->map.map[i] = NULL;
	ft_lstclear(head, &free);
	return (0);
}

int     validate_line(char *line)
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

char	**read_map(t_structures *structures, char *line)
{
	t_list		*head;

	head = NULL;
	validate_line(line);
	(line[0] != '\0') ? ft_lstadd_back(&head, ft_lstnew(line)) : free(line);
	while (get_next_line(structures->parcer.fd, &line) > 0)
	{
		validate_line(line);
		(line[0] != '\0') ? ft_lstadd_back(&head, ft_lstnew(line)) : free(line);
	}
	(line[0] != '\0') ? ft_lstadd_back(&head, ft_lstnew(line)) : free(line);
	close(structures->parcer.fd);
	structures->parcer.number_lines = ft_lstsize(head);
	return (make_map(&head, structures->parcer.number_lines, structures));
}

//PARCE MAP

//SPRITES

int		sprite_count(t_structures *structures)
{
	int x;
	int y;
	int sprite_num;

	x = -1;
	sprite_num = 0;
	while (structures->map.map[++x])
	{
		y = -1;
		while (structures->map.map[x][++y])
		{
			if (structures->map.map[x][y] == '2')
				sprite_num++;
		}
	}
	return (sprite_num);
}

int		**sprite_coordinates(t_structures *structures)
{
	int		**sprite_coordinates;
	int		x;
	int		y;
	int		i;

	x = -1;
	i = -1;
	if ((sprite_coordinates = (int **)ft_calloc(sprite_count(structures) + 1,
		sizeof(int *))) == 0)
		return (0);
	while (structures->map.map[++x])
	{
		y = -1;
		while (structures->map.map[x][++y])
		{
			if (structures->map.map[x][y] == '2')
			{
				if ((sprite_coordinates[++i] = ft_calloc(sizeof(int), 3)) == 0)
					return (0);
				sprite_coordinates[i][0] = x;
				sprite_coordinates[i][1] = y;
			}
		}
	}
	return (sprite_coordinates);
}

double	get_distance(t_structures *structures, int j)
{
	return (((structures->player.pos_x - structures->sprite.sprite[j][0]) * (structures->player.pos_x
		- structures->sprite.sprite[j][0]) + (structures->player.pos_y -
			structures->sprite.sprite[j][1]) * (structures->player.pos_y -
				structures->sprite.sprite[j][1])));
}

void	sort_sprites(int amount, t_structures *structures)
{
	int		j;
	double	distance1;
	double	distance2;
	int		x;
	int		y;

	j = -1;
	while (++j < amount - 1)
	{
		distance1 = get_distance(structures, j);
		distance2 = get_distance(structures, j + 1);
		if (distance1 < distance2)
		{
			x = structures->sprite.sprite[j][0];
			y = structures->sprite.sprite[j][1];
			structures->sprite.sprite[j][0] = structures->sprite.sprite[j + 1][0];
			structures->sprite.sprite[j][1] = structures->sprite.sprite[j + 1][1];
			structures->sprite.sprite[j + 1][0] = x;
			structures->sprite.sprite[j + 1][1] = y;
			j = -1;
		}
	}
}

void	sprite_calc(t_structures *structures, int i)
{
	structures->sprite.sprite_x = structures->sprite.sprite[i][0] - structures->player.pos_x + 0.5;
	structures->sprite.sprite_y = structures->sprite.sprite[i][1] - structures->player.pos_y + 0.5;
	structures->sprite.inv_det = 1.0 / (structures->player.plane_x * structures->player.dir_y - structures->player.dir_x * structures->player.plane_y);
	structures->sprite.depth_x = structures->sprite.inv_det * (structures->player.dir_y * structures->sprite.sprite_x - structures->player.dir_x * structures->sprite.sprite_y);
	structures->sprite.depth_y = structures->sprite.inv_det * (-structures->player.plane_y * structures->sprite.sprite_x + structures->player.plane_x * structures->sprite.sprite_y);
	structures->sprite.pos_on_screen = (int)((structures->parcer.screen_width / 2) * (1 + structures->sprite.depth_x / structures->sprite.depth_y));
	structures->sprite.sprite_height = fabs((structures->parcer.screen_height / (structures->sprite.depth_y)));
	structures->sprite.start_point_x = -structures->sprite.sprite_height / 2 + structures->parcer.screen_height / 2;
}

void	sprite_start_end(t_structures *structures)
{
	if (structures->sprite.start_point_x < 0)
		structures->sprite.start_point_x = 0;
	structures->sprite.start_point_y = structures->sprite.sprite_height / 2 +
		structures->parcer.screen_height / 2;
	if (structures->sprite.start_point_y >= structures->parcer.screen_height)
		structures->sprite.start_point_y = structures->parcer.screen_height - 1;
	structures->sprite.sprite_width = fabs((structures->parcer.screen_height /
		(structures->sprite.depth_y)));
	structures->sprite.stop_point_y = -structures->sprite.sprite_width / 2 +
		structures->sprite.pos_on_screen;
	if (structures->sprite.stop_point_y < 0)
		structures->sprite.stop_point_y = 0;
	structures->sprite.stop_point_x = structures->sprite.sprite_width / 2 +
		structures->sprite.pos_on_screen;
	if (structures->sprite.stop_point_x >= structures->parcer.screen_width)
		structures->sprite.stop_point_x = structures->parcer.screen_width - 1;
}

void	sprite_stroke_draw(t_structures *structures)
{
	int				y;
	int				d;
	unsigned int	color;

	y = structures->sprite.start_point_x - 1;
	while (++y < structures->sprite.start_point_y)
	{
		d = (y) * 256 - structures->parcer.screen_height * 128 +
			structures->sprite.sprite_height * 128;
		structures->sprite.tex_y = ((d * structures->texture.height[4]) /
			structures->sprite.sprite_height) / 256;
		color = texture_color(structures, structures->sprite.tex_x, structures->sprite.tex_y, 4);
		if ((color & 0x00FFFFFF) != 0)
			my_pixel_put(structures, structures->sprite.stroke, y, color);
	}
}

void	sprite_cast(t_structures *structures, double *buffer_w)
{
	int	i;

	structures->sprite.sprite_num = sprite_count(structures);
	sort_sprites(structures->sprite.sprite_num, structures);
	i = -1;
	while (++i < structures->sprite.sprite_num)
	{
		sprite_calc(structures, i);
		sprite_start_end(structures);
		structures->sprite.stroke = structures->sprite.stop_point_y - 1;
		while (++structures->sprite.stroke < structures->sprite.stop_point_x)
		{
			structures->sprite.tex_x = (int)(256 * (structures->sprite.stroke -
				(-structures->sprite.sprite_width / 2 + structures->sprite.pos_on_screen))
					* structures->texture.width[4] / structures->sprite.sprite_width) / 256;
			if (structures->sprite.depth_y > 0 && structures->sprite.stroke > 0 &&
				structures->sprite.stroke < structures->parcer.screen_width &&
					structures->sprite.depth_y < buffer_w[structures->sprite.stroke])
				sprite_stroke_draw(structures);
		}
	}
}


//SPRITES

//RAYCAST

unsigned int	texture_color(t_structures *structures, int x, int y, int cardinal_point)
{
	char			*dst;
	unsigned int	color;

	dst = structures->texture_data[cardinal_point].addr + (y * structures->texture_data[cardinal_point].line_length + x * (structures->texture_data[cardinal_point].bpp / 8));
	color = *(unsigned int*)dst;
	return (color);
}

void	get_data_tex(t_structures *structures)
{
	structures->texture_data[0].img = mlx_xpm_file_to_image(structures->data.mlx, structures->map.west, &structures->texture.width[0], &structures->texture.height[0]);
	structures->texture_data[0].addr = mlx_get_data_addr(structures->texture_data[0].img, &structures->texture_data[0].bpp, &structures->texture_data[0].line_length, &structures->texture_data[0].endian);
	structures->texture_data[1].img = mlx_xpm_file_to_image(structures->data.mlx, structures->map.north, &structures->texture.width[1], &structures->texture.height[1]);
	structures->texture_data[1].addr = mlx_get_data_addr(structures->texture_data[1].img, &structures->texture_data[1].bpp, &structures->texture_data[1].line_length, &structures->texture_data[1].endian);
	structures->texture_data[2].img = mlx_xpm_file_to_image(structures->data.mlx, structures->map.east, &structures->texture.width[2], &structures->texture.height[2]);
	structures->texture_data[2].addr = mlx_get_data_addr(structures->texture_data[2].img, &structures->texture_data[2].bpp, &structures->texture_data[2].line_length, &structures->texture_data[2].endian);
	structures->texture_data[3].img = mlx_xpm_file_to_image(structures->data.mlx, structures->map.south, &structures->texture.width[3], &structures->texture.height[3]);
	structures->texture_data[3].addr = mlx_get_data_addr(structures->texture_data[3].img, &structures->texture_data[3].bpp, &structures->texture_data[3].line_length, &structures->texture_data[3].endian);
	structures->texture_data[4].img = mlx_xpm_file_to_image(structures->data.mlx, structures->map.sprite, &structures->texture.width[4], &structures->texture.height[4]);
	structures->texture_data[4].addr = mlx_get_data_addr(structures->texture_data[4].img, &structures->texture_data[4].bpp, &structures->texture_data[4].line_length, &structures->texture_data[4].endian);
}

int		take_side(t_structures *structures)
{
	int	rtn;

	if (structures->player.pos_x >= structures->raycast.map_x && structures->player.pos_y >= structures->raycast.map_y)
		rtn = structures->raycast.side == 1 ? 0 : 1;
	else if (structures->player.pos_x >= structures->raycast.map_x && structures->player.pos_y <= structures->raycast.map_y)
		rtn = structures->raycast.side == 1 ? 2 : 1;
	else if (structures->player.pos_x <= structures->raycast.map_x && structures->player.pos_y <= structures->raycast.map_y)
		rtn = structures->raycast.side == 1 ? 2 : 3;
	else
		rtn = structures->raycast.side == 1 ? 0 : 3;
	return (rtn);
}

void	my_pixel_put(t_structures *structures, int x, int y, int color)
{
    char    *dst;

    dst = structures->data.addr + (y * structures->data.line_length + x * (structures->data.bpp / 8));
    *(unsigned int *)dst = color;
}

void		line_height(t_structures *structures)
{
	structures->raycast.line_height = (int)(structures->parcer.screen_height / structures->raycast.perp_wall_dist);
	structures->raycast.draw_start = -structures->raycast.line_height / 2 + structures->parcer.screen_height / 2;
	if (structures->raycast.draw_start < 0)
		structures->raycast.draw_start = 0;
	structures->raycast.draw_end = structures->raycast.line_height / 2 + structures->parcer.screen_height / 2;
	if (structures->raycast.draw_end >= structures->parcer.screen_height)
		structures->raycast.draw_end = structures->parcer.screen_height - 1;
	// if (structures->raycast.draw_end % 2 != 0)
	// 	structures->raycast.draw_end += 0.035;
	// if (structures->raycast.draw_start % 2 != 0)
	// 	structures->raycast.draw_start += 0.035;
}

void	texture_wall(t_structures *structures, int iterator)
{
	int	cardinal_point;

	cardinal_point = take_side(structures);
	if (structures->raycast.side == 0)
		structures->texture.wall_x = structures->player.pos_y + structures->raycast.perp_wall_dist * structures->raycast.ray_dir_y;
	else
		structures->texture.wall_x = structures->player.pos_x + structures->raycast.perp_wall_dist * structures->raycast.ray_dir_x;
	structures->texture.wall_x -= floor(structures->texture.wall_x);
	structures->texture.tex_x = (int)(structures->texture.wall_x * (double)(structures->texture.width[cardinal_point]));
	if (structures->raycast.side == 0 && structures->raycast.ray_dir_x > 0)
		structures->texture.tex_x = structures->texture.width[cardinal_point] - structures->texture.tex_x - 1;
	if (structures->raycast.side == 1 && structures->raycast.ray_dir_y < 0)
		structures->texture.tex_x = structures->texture.width[cardinal_point] - structures->texture.tex_x - 1;
	structures->texture.step = 1.0 * structures->texture.height[cardinal_point] / structures->raycast.line_height;
	structures->texture.tex_pos = (structures->raycast.draw_start - structures->parcer.screen_height / 2 + structures->raycast.line_height / 2) * structures->texture.step;
	while (structures->raycast.draw_start < structures->raycast.draw_end)
	{
		structures->texture.tex_y = (int)structures->texture.tex_pos & (structures->texture.height[cardinal_point] - 1);
		structures->texture.tex_pos += structures->texture.step;
		my_pixel_put(structures, iterator, structures->raycast.draw_start++, texture_color(structures, structures->texture.tex_x, structures->texture.tex_y, cardinal_point));
	}
}

void		floor_ceiling(t_structures *structures, int start, int end, int width)
{
	if (start == 0)
		while (start < end)
			my_pixel_put(structures, width, start++, structures->map.floor);
	else
		while (start < end)
			my_pixel_put(structures, width, start++, structures->map.ceiling);
}

int		cube(t_structures *structures)
{
    structures->raycast.iterator = -1;
	double tmp_line[(int)structures->parcer.screen_width];

	displacement(structures);
    structures->data.img = mlx_new_image(structures->data.mlx, structures->parcer.screen_width, structures->parcer.screen_height);
    structures->data.addr = mlx_get_data_addr(structures->data.img, &structures->data.bpp, &structures->data.line_length, &structures->data.endian);
    while (++structures->raycast.iterator < structures->parcer.screen_width)
    {
        structures->raycast.camera = 2 * structures->raycast.iterator / (double)structures->parcer.screen_width - 1;
        structures->raycast.ray_dir_x = structures->player.dir_x + structures->player.plane_x * structures->raycast.camera;
        structures->raycast.ray_dir_y = structures->player.dir_y + structures->player.plane_y * structures->raycast.camera;

        structures->raycast.map_x = (int)structures->player.pos_x;
        structures->raycast.map_y = (int)structures->player.pos_y;

		if (structures->raycast.ray_dir_y == 0)
			structures->raycast.delta_dist_x = 0;
		else if (structures->raycast.ray_dir_x == 0)
			structures->raycast.delta_dist_x = 0;
		else
			structures->raycast.delta_dist_x = fabs(1 / structures->raycast.ray_dir_x);
		if (structures->raycast.ray_dir_x == 0)
			structures->raycast.delta_dist_y = 0;
		else if (structures->raycast.ray_dir_x == 0)
			structures->raycast.delta_dist_y = 0;
		else
			structures->raycast.delta_dist_y = fabs(1 / structures->raycast.ray_dir_y);

        structures->raycast.hit = 0;
        if (structures->raycast.ray_dir_x < 0)
        {
            structures->raycast.step_x = -1;
            structures->raycast.side_dist_x = (structures->player.pos_x - structures->raycast.map_x) * structures->raycast.delta_dist_x;
        }
        else
        {
            structures->raycast.step_x = 1;
            structures->raycast.side_dist_x = (structures->raycast.map_x + 1.0 - structures->player.pos_x) * structures->raycast.delta_dist_x;
        }
        if (structures->raycast.ray_dir_y < 0)
        {
            structures->raycast.step_y = -1;
            structures->raycast.side_dist_y = (structures->player.pos_y - structures->raycast.map_y) * structures->raycast.delta_dist_y;
        }
        else
        {
            structures->raycast.step_y = 1;
            structures->raycast.side_dist_y = (structures->raycast.map_y + 1.0 - structures->player.pos_y) * structures->raycast.delta_dist_y;
        }
        while (structures->raycast.hit == 0)
        {
            if (structures->raycast.side_dist_x < structures->raycast.side_dist_y)
            {
                structures->raycast.side_dist_x += structures->raycast.delta_dist_x;
                structures->raycast.map_x += structures->raycast.step_x;
                structures->raycast.side = 0;
            }
            else
            {
                structures->raycast.side_dist_y += structures->raycast.delta_dist_y;
                structures->raycast.map_y += structures->raycast.step_y;
                structures->raycast.side = 1;
            }
            if (structures->map.map[structures->raycast.map_x][structures->raycast.map_y] == '1')
                structures->raycast.hit = 1;
        }
        if (structures->raycast.side == 0)
            structures->raycast.perp_wall_dist = (structures->raycast.map_x - structures->player.pos_x + (1 - structures->raycast.step_x) / 2) / structures->raycast.ray_dir_x;
        else
            structures->raycast.perp_wall_dist = (structures->raycast.map_y - structures->player.pos_y + (1 - structures->raycast.step_y) / 2) / structures->raycast.ray_dir_y;
		line_height(structures);
		floor_ceiling(structures, 0, structures->raycast.draw_start, structures->raycast.iterator);
		texture_wall(structures, structures->raycast.iterator);
		floor_ceiling(structures, structures->raycast.draw_end, structures->parcer.screen_height, structures->raycast.iterator);
		tmp_line[structures->raycast.iterator] = structures->raycast.perp_wall_dist;
    }
	sprite_cast(structures, tmp_line);
    mlx_put_image_to_window(structures->data.mlx, structures->data.win, structures->data.img, 0, 0);
    mlx_destroy_image(structures->data.mlx, structures->data.img);
	return (0);
}

//RAYCAST
int		parser(char **av)
{
	int i;
	int rt;
	t_structures structures;

	i = 0;
	struct_init(&structures);
	structures.parcer.fd = open(av[1], O_RDONLY);
	while (get_next_line(structures.parcer.fd, &structures.parcer.line) && i < 8)
	{
		if (!(structures.parcer.line[0] == '\0') && !spaces_line(structures.parcer.line))
		{
			i++;
			rt = get_parameters(structures.parcer.line, &structures);
		}
		free(structures.parcer.line);
	}
	read_map(&structures, structures.parcer.line);
	validate_map(&structures);
	close(structures.parcer.fd);
	if ((structures.sprite.sprite = sprite_coordinates(&structures)) == 0)
		return (0);
   	structures.data.mlx = mlx_init();
	structures.data.win = mlx_new_window(structures.data.mlx, structures.parcer.screen_width, structures.parcer.screen_height, "maze");
	// structures.data.img = mlx_new_image(structures.data.mlx, structures.parcer.screen_width, structures.parcer.screen_height);
    // structures.data.addr = mlx_get_data_addr(structures.data.img, &structures.data.bpp, &structures.data.line_length, &structures.data.endian);
	get_data_tex(&structures);
	mlx_hook(structures.data.win, 2, 0, pressed, &structures);
	mlx_hook(structures.data.win, 3, 0, unpressed, &structures);
	mlx_hook(structures.data.win, 17, 0, escape, &structures);
	mlx_loop_hook(structures.data.mlx, cube, &structures);
    mlx_loop(structures.data.mlx);
	return (0);
}