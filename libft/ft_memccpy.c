/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:00:02 by mhumfrey          #+#    #+#             */
/*   Updated: 2020/11/07 18:14:05 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ssrc;
	unsigned char		*ddst;
	size_t				i;

	i = 0;
	c = (unsigned char)c;
	ssrc = (unsigned char *)src;
	ddst = (unsigned char *)dst;
	while (i < n)
	{
		ddst[i] = ssrc[i];
		if (ddst[i] == c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
