/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:08:06 by orezek            #+#    #+#             */
/*   Updated: 2023/11/07 23:35:26 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Use standard library functions only for prototypes and for 42 replace them with your own.

// Todo: Add edge case handling.
	// What if the file doesn't exist?
	// What if the file is empty?
	// What if the file is only one line?
	// What if the file is only one line and it doesn't end with a new line?
	// What if the file is only one line and it ends with a new line?
	// What if the file is multiple lines?
	// What if the file is multiple lines and it doesn't end with a new line?
	// What if the file is multiple lines and it ends with a new line?
	// What if the file is multiple lines and it ends with multiple new lines?
	// What if the file is multiple lines and it ends with multiple new lines and the last line is empty?
	// What if the file is multiple lines and it ends with multiple new lines and the last line is not empty?
	// What if the file is multiple lines and it ends with multiple new lines and the last line is not empty and it doesn't end with a new line?
// Todo: Add error handling.
	// Check mallocs.
	// Check read.
	// Check close.
	// Check fd.
	// Check buffer size.
	// Null all pointers after free.

// Todo: Add support for multiple file descriptors.

// Steps:
// 0. Caller calls get_next_line with a file descriptor and expects a line from the file or NULL.
// 1. function entry - is buffer NULL?
	// 1.1 if it is, allocate memory, read to buf, set trailing \0 to the buffer
		// do all the checks including EOF and continue to 2.1 (if EOF return NULL)
	// 1.2 if it is not, continue to 2.1
// 2.1 check if the buffer contains a new line.
	// 2.1.1 if it does, it appends the chars including the new line and (manually add \0)
	//		// into a new_string var, shifts the buffer to the
			// left and returns the new string var to the caller (continues to 0)
	// 2.1.2 if it doesn't, it moves (strjoin)? the buffer into
			// a new_line var, reads to the buffer, sets trailing \0 to the buffer
			// and it contines until if either finds a new line or EOF (continues to 0)
// 3. caller receives a NULL pointer and knows that there is no more data to read.

char	*get_next_line(int fd)
{
	static char	*buf;
	size_t		buffer_size;
	char		*new_line;
	char		*temp;
	int			bytes_read;

	buffer_size = 50;
	new_line = NULL;
	if (buf == NULL)
	{
		buf = malloc(sizeof(char) * (buffer_size + 1));
		bytes_read = read(fd, buf, buffer_size);
		if (bytes_read <= 0)
		{
			free(buf);
			return (buf = NULL);
		}
		buf[bytes_read] = '\0';
	}
	if (!ft_has_newline(buf))
	{
		while (!ft_has_newline(buf))
		{
			new_line = ft_strjoin(new_line, buf);
			bytes_read = read(fd, buf, buffer_size);
			if (bytes_read == 0)
			{
				free(buf);
				buf = NULL;
				return (new_line);
			}
			buf[bytes_read] = '\0';
		}
		temp = ft_extract_line_and_movebytes(buf);
		new_line = ft_strjoin(new_line, temp);
		free(temp);
		return (new_line);
	}
	if (ft_has_newline(buf))
	{
		new_line = ft_extract_line_and_movebytes(buf);
		return (new_line);
	}
	return (NULL);
}
