/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_parce_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:00:13 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/02/11 17:57:56 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		parse_textures(t_a *a, char **words)
{
	int fd;

	fd = open(words[1], O_RDONLY);
	if (!ft_strncmp(words[0], "NO", 3)
	&& !(fd < 0) && a->m.n == NULL)
		a->m.n = ft_strdup(words[1]);
	else if (!ft_strncmp(words[0], "SO", 3)
	&& !(fd < 0) && a->m.s == NULL)
		a->m.s = ft_strdup(words[1]);
	else if (!ft_strncmp(words[0], "WE", 3)
	&& !(fd < 0) && a->m.w == NULL)
		a->m.w = ft_strdup(words[1]);
	else if (!ft_strncmp(words[0], "EA", 3)
	&& !(fd < 0) && a->m.e == NULL)
		a->m.e = ft_strdup(words[1]);
	else if (!ft_strncmp(words[0], "S", 2)
	&& !(fd < 0) && a->m.sp == NULL)
		a->m.sp = ft_strdup(words[1]);
	else
		return (error("Error\nWrong path, specificator, texture!"));
	free_arr(words);
	close(fd);
	return (0);
}

int		parse_floor(t_a *a, char **rgb)
{
	if (number_words(rgb) == 3)
	{
		if (!loop_digit(rgb[0]) && !loop_digit(rgb[1]) && !loop_digit(rgb[2]))
		{
			if (ft_atoi(rgb[0]) <= 255 && ft_atoi(rgb[1]) <= 255 &&
			ft_atoi(rgb[2]) <= 255 && ft_atoi(rgb[0]) >= 0 &&
			ft_atoi(rgb[1]) >= 0 && ft_atoi(rgb[2]) >= 0)
			{
				a->m.f = (ft_atoi(rgb[0]) << 16 |
				ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]));
				a->f.f_f = 1;
			}
			else
				return (error("Error\nWrong value of color!"));
		}
		else
			return (error("Error\nWrong color!"));
	}
	else
		return (error("Error\nWrong color args!"));
	return (0);
}

int		parse_ceiling(t_a *a, char **rgb)
{
	if (number_words(rgb) == 3)
	{
		if (!loop_digit(rgb[0]) && !loop_digit(rgb[1]) && !loop_digit(rgb[2]))
		{
			if (ft_atoi(rgb[0]) <= 255 && ft_atoi(rgb[1]) <= 255 &&
			ft_atoi(rgb[2]) <= 255 && ft_atoi(rgb[0]) >= 0 &&
			ft_atoi(rgb[1]) >= 0 && ft_atoi(rgb[2]) >= 0)
			{
				a->m.c = (ft_atoi(rgb[0]) << 16 |
				ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]));
				a->f.f_c = 1;
			}
			else
				return (error("Error\nWrong value of color!"));
		}
		else
			return (error("Error\nWrong color!"));
	}
	else
		return (error("Error\nWrong color args!"));
	return (0);
}

int		parse_fc(t_a *a, char **words)
{
	char **rgb;

	if (!ft_strncmp(words[0], "F", 2) && a->f.f_f == 0)
	{
		rgb = ft_split(words[1], ',');
		parse_floor(a, rgb);
	}
	else if (!ft_strncmp(words[0], "C", 2) && a->f.f_c == 0)
	{
		rgb = ft_split(words[1], ',');
		parse_ceiling(a, rgb);
	}
	else
		return (error("Error\nWrong color specificator!"));
	free_arr(rgb);
	free_arr(words);
	return (0);
}

int		get_parameters(char *line, t_a *a)
{
	char	**words;
	int		rt;

	words = ft_split(line, ' ');
	if (!ft_strncmp(words[0], "R", 2) &&
	number_words(words) == 3 && a->f.f_r == 0)
	{
		rt = get_resolution(a, words);
		a->f.f_r = 1;
	}
	else if (('N' == *words[0] || 'S' == *words[0] || 'W' == *words[0]
	|| 'E' == *words[0]) && number_words(words) == 2)
		rt = parse_textures(a, words);
	else if (('F' == *words[0] || 'C' == *words[0]) && number_words(words) == 2)
		rt = parse_fc(a, words);
	else
		return (error("Error\nWrong specificator or args!"));
	return (rt);
}
