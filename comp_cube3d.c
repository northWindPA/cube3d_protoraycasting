/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_cube3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:32:37 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/02/14 00:12:57 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	a->f.f_r = 0;
	a->f.f_f = 0;
	a->f.f_c = 0;
	a->r.mvspd = 0.1;
	a->r.rtspd = 0.05;
	a->mv_f.mv_f = 0;
	a->mv_f.mv_b = 0;
	a->mv_f.mv_l = 0;
	a->mv_f.mv_r = 0;
	a->mv_f.rtt_l = 0;
	a->mv_f.rtt_r = 0;
	a->prc.pl_f = 0;
	a->pl.dr_x = 0;
	a->pl.dr_y = 0;
	a->pl.pln_x = 0;
	a->pl.pln_y = 0;
}

void	struct_init_2(t_a *a)
{
	a->scrnst.flag = 0;
	a->scrnst.unsi_z = 0;
	a->scrnst.sign_z = 0;
	a->scrnst.ppd_54 = 54;
	a->scrnst.ppd_40 = 40;
	a->scrnst.pln_1 = 1;
}

int		number_words(char **words)
{
	int i;

	i = 0;
	while (words[i])
		i++;
	return (i);
}

int		read_lines(t_a *a, char **av)
{
	int i;

	i = 0;
	a->prc.fd = open(av[1], O_RDONLY);
	while (get_next_line(a->prc.fd, &a->prc.l) && i < 8)
	{
		if (!(a->prc.l[0] == '\0') && !spaces_line(a->prc.l))
		{
			i++;
			get_parameters(a->prc.l, a);
		}
		free(a->prc.l);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_a a;

	struct_init(&a);
	struct_init_2(&a);
	if (ac < 2)
		return (error("Error\nNot enough arguments"));
	if (ac > 3)
		return (error("Error\nToo many arguments"));
	if (!(ft_strncmp(av[1], "map.cub", 9) == 0))
		return (error("Wrong file of the map!"));
	read_lines(&a, av);
	read_map(&a, a.prc.l);
	validate_map(&a);
	close(a.prc.fd);
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 6) == 0)
		{
			a.scrnst.flag = 1;
			return (get_screenshot(&a));
		}
		else
			return (error("Wrong command!"));
	}
	maze(&a);
	return (0);
}
