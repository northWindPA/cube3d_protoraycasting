/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 22:04:34 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/01/16 19:15:52 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_maker(char *text)
{
	char					*line;
	unsigned long long		len;

	len = 0;
	while (text[len] != '\n' && text[len] != 0)
		len++;
	if ((line = malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	len = 0;
	while (text[len] != '\n' && text[len] != 0)
	{
		line[len] = text[len];
		len++;
	}
	line[len] = '\0';
	return (line);
}

int		text_checker(char *text)
{
	unsigned long long int	i;

	i = 0;
	if (text == 0)
		return (0);
	while (text[i] != 0)
	{
		if (text[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*tail_cutter(char *text)
{
	unsigned long long int	i;
	unsigned long long int	j;
	char					*pure_line;

	i = 0;
	while (text[i] != '\n' && text[i] != 0)
		i++;
	if (text[i] == 0)
	{
		free(text);
		return (0);
	}
	if ((pure_line = malloc(sizeof(char) * ((ft_strlen_g(text) - i) + 1))) == 0)
		return (0);
	i++;
	j = 0;
	while (text[i] != 0)
		pure_line[j++] = text[i++];
	pure_line[j] = '\0';
	free(text);
	return (pure_line);
}

int		get_next_line(int fd, char **line)
{
	long long int	read_result;
	char			*buffer;
	static char		*text;

	if (fd < 0 || BUFFER_SIZE < 1 || line == 0)
		return (-1);
	if ((buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))) == 0)
		return (-1);
	read_result = 1;
	while (read_result != 0 && text_checker(text) == 0)
	{
		if ((read_result = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[read_result] = '\0';
		text = str_join_g(text, buffer);
	}
	free(buffer);
	*line = line_maker(text);
	text = tail_cutter(text);
	return (read_result == 0) ? 0 : 1;
}
