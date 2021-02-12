/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:02:10 by mhumfrey          #+#    #+#             */
/*   Updated: 2020/11/10 17:21:55 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buff;

	if (del == 0)
		return ;
	while (*lst != 0)
	{
		del((*lst)->content);
		buff = *lst;
		*lst = buff->next;
		free(buff);
	}
	*lst = NULL;
}
