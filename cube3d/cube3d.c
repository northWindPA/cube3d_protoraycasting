/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:32:37 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/01/28 20:21:14 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int     main(int ac, char **av)
{
	if (ac < 2)
		return (write(1, "Not enough arguments\n", 20));
	if (ac > 3)
		return (write(1, "Too many arguments\n", 18));
	parser(av);
	//sprites
	// if (ac == 3)
	// {
	// 	if (ft_strncmp(av[2], "--save", 7) == 0)
	// 		return (screenshot(&a));
	// 	else
	// 	{
	// 		return (write(1, "Wrong command\n", 13));
	// }
	// if (start_maze(&a) == 0)
	// 	return (0);
	// while(1);
	return (0);
}