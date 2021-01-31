/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:15:48 by mhumfrey          #+#    #+#             */
/*   Updated: 2020/11/11 15:08:08 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		sublen;
	char		*s2;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (ft_strchr(set, *s1) != 0 && *s1 != '\0')
		s1++;
	sublen = ft_strlen(s1);
	while (sublen != 0 && ft_strchr(set, s1[sublen]) != 0)
		sublen--;
	s2 = ft_substr((char*)s1, 0, sublen + 1);
	return (s2);
}
