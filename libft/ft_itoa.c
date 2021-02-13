/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:38:23 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/02/13 22:46:41 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long z)
{
	int	y;

	y = 0;
	if (z < 0)
	{
		z = z * -1;
		y++;
	}
	while (z > 0)
	{
		z = z / 10;
		y++;
	}
	return (y);
}

static char	*ft_intstr(char *str, long l, int size)
{
	if (l < 0)
	{
		str[0] = '-';
		l *= -1;
	}
	while (l > 0)
	{
		str[size--] = (l % 10) + 48;
		l = l / 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*num;
	int		len;
	long	m;

	m = n;
	len = ft_intlen(m);
	if (m == 0)
	{
		if ((num = (char *)malloc(2 * sizeof(char))) == NULL)
			return (0);
		num[0] = '0';
		num[1] = '\0';
		return (num);
	}
	if ((num = (char *)malloc((len + 1) * sizeof(char))) == NULL)
		return (0);
	num[len--] = '\0';
	ft_intstr(num, m, len);
	return (num);
}
