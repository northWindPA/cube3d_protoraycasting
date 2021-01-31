/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:15:06 by mhumfrey          #+#    #+#             */
/*   Updated: 2020/11/09 15:16:27 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static int		ft_wordnum(char *str, char c)
{
	int		i;
	int		nw;
	int		word;

	i = 0;
	nw = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && word == 0)
		{
			word = 1;
			nw++;
		}
		if (str[i] == c && word == 1)
			word = 0;
		i++;
	}
	return (nw);
}

static void		*ft_freeall(char **arr, int i)
{
	while (i-- != 0)
		free(arr[i]);
	free(arr);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	char	**arr;
	int		wordnum;

	i = 0;
	if (s == 0)
		return (NULL);
	wordnum = ft_wordnum((char *)s, c);
	if ((arr = (char **)malloc((wordnum + 1) * sizeof(char*))) == 0)
		return (NULL);
	while (wordnum--)
	{
		while (*s != '\0' && *s == c)
			s++;
		if ((arr[i] = ft_substr((char *)s, 0, ft_wordlen((char *)s, c))) == 0)
			return (ft_freeall(arr, i));
		i++;
		s += ft_wordlen((char *)s, c);
	}
	arr[i] = NULL;
	return (arr);
}
