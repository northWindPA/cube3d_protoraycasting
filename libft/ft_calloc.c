/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:09:36 by mhumfrey          #+#    #+#             */
/*   Updated: 2020/11/06 18:33:00 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	char	*d;
	int		csize;

	csize = count * size;
	s = (char *)malloc((csize) * sizeof(char));
	if (s == 0)
		return (s);
	d = s;
	while (csize-- > 0)
		*d++ = '\0';
	return (s);
}
