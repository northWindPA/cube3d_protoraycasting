/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:10:37 by mhumfrey          #+#    #+#             */
/*   Updated: 2020/11/03 16:57:12 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *dest;
	char *sorc;

	dest = (char *)dst;
	sorc = (char *)src;
	if (dest < sorc)
	{
		while (len--)
			*dest++ = *sorc++;
	}
	else if (sorc < dest)
	{
		dest = dest + len - 1;
		sorc = sorc + len - 1;
		while (len--)
			*dest-- = *sorc--;
	}
	return (dst);
}
