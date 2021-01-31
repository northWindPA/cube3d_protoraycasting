/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:05:52 by mhumfrey          #+#    #+#             */
/*   Updated: 2020/11/03 16:42:59 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ssrc;
	char	*ddst;

	ssrc = (char *)src;
	ddst = (char *)dst;
	if (n == 0 || ddst == ssrc)
		return (dst);
	while (n--)
		*ddst++ = *ssrc++;
	return (dst);
}
