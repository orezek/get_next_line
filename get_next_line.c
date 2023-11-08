/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:08:06 by orezek            #+#    #+#             */
/*   Updated: 2023/11/08 16:13:02 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*new_line;
	char		*temp;
	int			bytes_read;

	new_line = NULL;
	if (buf == NULL)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (free(buf), buf = NULL);
		buf[bytes_read] = '\0';
	}
	if (!ft_has_newline(buf))
	{
		while (!ft_has_newline(buf))
		{
			new_line = ft_strjoin(new_line, buf);
			bytes_read = read(fd, buf, BUFFER_SIZE);
			if (bytes_read <= 0 && new_line[0] == '\0')
				return (free(buf), free(new_line), buf = NULL);
			if (bytes_read <= 0)
				return (free(buf), buf = NULL, new_line);
			buf[bytes_read] = '\0';
		}
		temp = ft_extract_line_and_movebytes(buf);
		return (new_line = ft_strjoin(new_line, temp), free(temp), new_line);
	}
	if (ft_has_newline(buf))
		return (new_line = ft_extract_line_and_movebytes(buf));
	return (NULL);
}
