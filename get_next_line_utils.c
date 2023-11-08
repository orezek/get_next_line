/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:24:23 by aldokezer         #+#    #+#             */
/*   Updated: 2023/11/08 12:20:33 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while(*str++)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	if (s1)
	{
	while (s1[i])
		new_str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
		new_str[j++] = s2[i++];
	new_str[j] = '\0';
	free(s1);
	return (new_str);
}

int	ft_find_newline_position(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '\n')
			return (i);
		i++;
		str++;
	}
	return (-1);
}

int	ft_has_newline(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_extract_line_and_movebytes(char *buf)
{
	char	*newline;
	int		new_line_position;

	new_line_position = ft_find_newline_position(buf);
	if (new_line_position >= 0)
	{
		newline = malloc(sizeof(char) * (new_line_position + 2));
		newline = strncpy(newline, buf, new_line_position + 1);
		newline[new_line_position + 1] = '\0';
		buf = memmove(buf, buf + new_line_position + 1, ft_strlen(buf) - new_line_position);
		return (newline);
	}
	return (NULL);
}
