/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:32:09 by mhumfrey          #+#    #+#             */
/*   Updated: 2020/11/04 13:02:16 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ss;
	int		len;

	len = ft_strlen(s);
	ss = (char *)s + len;
	while (*ss != c)
	{
		if (ss == s)
			return (0);
		ss--;
	}
	return (ss);
}
