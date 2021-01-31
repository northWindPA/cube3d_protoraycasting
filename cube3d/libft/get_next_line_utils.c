/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 22:03:32 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/01/16 19:14:58 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen_g(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void		*ft_memmove_g(void *dst, const void *src, size_t len)
{
	char *dest;
	char *sorc;

	dest = (char *)dst;
	sorc = (char *)src;
	if (dst == src)
		return (dst);
	if (sorc < dest)
	{
		while (len--)
			*(dest + len) = *(sorc + len);
		return (dst);
	}
	while (len--)
		*dest++ = *sorc++;
	return (dst);
}

char		*str_join_g(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*string;

	if (s1 == 0 && s2 == 0)
		return (0);
	len1 = ft_strlen_g((char *)s1);
	len2 = ft_strlen_g((char *)s2);
	if ((string = malloc(sizeof(char) * (len1 + len2 + 1))) == 0)
		return (0);
	ft_memmove_g(string, s1, len1);
	ft_memmove_g(string + len1, s2, len2);
	string[len1 + len2] = '\0';
	free((char *)s1);
	return (string);
}
