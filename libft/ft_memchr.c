/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:58:23 by mhumfrey          #+#    #+#             */
/*   Updated: 2020/11/11 13:37:10 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ss;

	c = (unsigned char)c;
	ss = (unsigned char *)s;
	while (n-- != 0)
	{
		if (*ss == c)
			return (ss);
		ss++;
	}
	return (0);
}
