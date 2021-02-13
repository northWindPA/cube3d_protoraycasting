/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_parce_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:06:32 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/02/13 22:51:44 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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

int		check_line(t_a *a, int x, int y)
{
	if (x > 0 && y > 0 && (y + 1) <
	(int)ft_strlen(a->m.m[x]) && (x + 1) < a->prc.n_l)
	{
		if (y >= (int)ft_strlen(a->m.m[x - 1])
		|| y >= (int)ft_strlen(a->m.m[x + 1]))
			return (error("Error\nMap is not closed!"));
		if (a->m.m[x - 1][y] == ' ' || a->m.m[x + 1][y] == ' '
		|| a->m.m[x][y - 1] == ' ' || a->m.m[x][y + 1] == ' '
		|| a->m.m[x - 1][y - 1] == ' ' || a->m.m[x - 1][y + 1] == ' '
		|| a->m.m[x + 1][y - 1] == ' ' || a->m.m[x + 1][y + 1] == ' ')
			return (error("Error\nMap is not closed!"));
	}
	else
		return (error("Error\nMap is not closed!"));
	return (0);
}

void	player_dir(t_a *a, char direction, int x, int y)
{
	if (direction == 'N')
	{
		a->pl.dr_x = -1;
		a->pl.pln_y = 0.66;
	}
	if (direction == 'S')
	{
		a->pl.dr_x = 1;
		a->pl.pln_y = -0.66;
	}
	if (direction == 'E')
	{
		a->pl.dr_y = 1;
		a->pl.pln_x = 0.66;
	}
	if (direction == 'W')
	{
		a->pl.dr_y = -1;
		a->pl.pln_x = -0.66;
	}
	a->pl.ps_x = x + 0.5;
	a->pl.ps_y = y + 0.5;
}

char	**make_map(t_list **head, int size, t_a *a)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *head;
	if (!(a->m.m = ft_calloc(size + 1, sizeof(char *))))
		return (0);
	while (tmp)
	{
		a->m.m[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	a->m.m[i] = NULL;
	ft_lstclear(head, &free);
	return (0);
}

char	**read_map(t_a *a, char *line)
{
	t_list		*head;

	head = NULL;
	validate_line(line);
	(line[0] != '\0') ? ft_lstadd_back(&head, ft_lstnew(line)) : free(line);
	while (get_next_line(a->prc.fd, &line) > 0)
	{
		validate_line(line);
		(line[0] != '\0') ? ft_lstadd_back(&head, ft_lstnew(line)) : free(line);
	}
	validate_line(line);
	(line[0] != '\0') ? ft_lstadd_back(&head, ft_lstnew(line)) : free(line);
	close(a->prc.fd);
	a->prc.n_l = ft_lstsize(head);
	return (make_map(&head, a->prc.n_l, a));
}
