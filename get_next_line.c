/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:08:06 by orezek            #+#    #+#             */
/*   Updated: 2023/11/07 13:07:13 by aldokezer        ###   ########.fr       */
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
// 0. Caller calls get_next_line with a file descriptor and expects a line from the file.
// 1. function entry - is buffer NULL?
	// 1.1 if it is, allocate memory, read to buf, set trailing \0 to the buffer
		// do all the checks including EOF and continue to 2.1 (if EOF return NULL)
	// 1.2 if it is not, continue to 2.1
// 2.1 check if the buffer contains a new line.
	// 2.1.1 if it does, it appends the chars including the new line and (manually add \0)
	//		// into a new_string var, shifts the buffer to the
			// left and returns the new string var to the caller (continues to 0)
	// 2.1.2 if it doesn't, it moves (strjoin)? the buffer into
			// a new_lie var, reads to the buffer, sets trailing \0 to the buffer
			// and it contines until if either finds a new line or EOF
// 3. check if buffer is not empty
	// 3.1 if it is, free the buffer and return NULL to the caller
	// 3.2 if it is not, return the buffer to the caller
// 4. caller receives a NULL pointer and knows that there is no more data to read.
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


char	*get_next_line(int fd)
{
	static char	*buf;
	size_t		buffer_size;
	char		*new_line;
	char		*temp;
	int			bytes_read;
	buffer_size = 50;

// 1
	if (buf == NULL)
	{
		buf = malloc(sizeof(char) * (buffer_size + 1));
		bytes_read = read(fd, buf, buffer_size);
		buf[bytes_read] = '\0';
	}
// 2.1.2
	if (!ft_has_newline(buf) || buf[0] == '\0')
	{
		new_line = strdup(buf);
		bytes_read = read(fd, buf, buffer_size);
		buf[bytes_read] = '\0';
		if (ft_has_newline(buf))
		{
			temp = ft_extract_line_and_movebytes(buf);
			new_line = ft_strjoin(new_line, temp);
			free(temp);
			return (new_line);
		}
		while (!ft_has_newline(buf) && bytes_read > 0)
		{
			new_line = ft_strjoin(new_line, buf);
			bytes_read = read(fd, buf, buffer_size);
			buf[bytes_read] = '\0';
		}
		if (bytes_read == 0)
		{
			free(buf);
			return (new_line);
		}
		temp = ft_extract_line_and_movebytes(buf);
		new_line = ft_strjoin(new_line, temp);
		free(temp);
		return (new_line);
	}
// 2.1.1 & 3.2 be careful if is true if there is content  this is error
	if (ft_has_newline(buf) || buf[0] != '\0')
	{
		new_line = ft_extract_line_and_movebytes(buf);
		return (new_line);
	}
// 3.1
	free(buf);
	return (NULL);
}
