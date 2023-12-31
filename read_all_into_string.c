/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all_into_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:21:45 by orezek            #+#    #+#             */
/*   Updated: 2023/11/06 23:28:58 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Reads the content of a file into a single string regardles of the file size and buffer size.
// Doesn't have any error checking and edge case handling but it is a good starting point.

char	*read_all_into_string(int fd)
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
