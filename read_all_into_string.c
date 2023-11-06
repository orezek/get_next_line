/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all_into_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:21:45 by orezek            #+#    #+#             */
/*   Updated: 2023/11/06 14:04:14 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// doest not have any error checking and edge case handling

char	*get_next_line(int fd)
{
	size_t	buffer_size;
	char	*buf;
	char	*new_line;
	char	*temp;
	int		bytes_read;

	buf = NULL;
	new_line = NULL;
	temp = NULL;
	buffer_size = 50;
	buf = malloc(sizeof(char) * (buffer_size + 1));
	new_line = malloc(sizeof(char) * 1);
	bytes_read = read(fd, buf, buffer_size);
	buf[bytes_read] = '\0';
	*new_line = '\0';
	while (bytes_read > 0)
	{
		temp = ft_strjoin(new_line, buf);
		free(new_line);
		new_line = temp;
		bytes_read = read(fd, buf, buffer_size);
		buf[bytes_read] = '\0';
	}
	free(buf);
	return (new_line);
}
