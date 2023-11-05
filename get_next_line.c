/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:58:19 by aldokezer         #+#    #+#             */
/*   Updated: 2023/11/06 00:36:39 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	static int	buf_used;
	int 		BUFFER_SIZE;
	char		*new_line;
	char		*temp;
	size_t		bytes_read;

// initialize n to 1 to account for the newline character
	BUFFER_SIZE = 1;
	buf = NULL;
	buf_used = 0;
	new_line = NULL;
	temp = NULL;
// allocate memory for buf
	if (buf_used == 0)
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// check if buf is valid
		if (!buf)
			return (NULL);
// read from fd into buf
	bytes_read = read(fd, buf, BUFFER_SIZE);
// check if read was successful, fd is valid or buf is empty
	if (bytes_read <= 0 || buf[0] == '\0')
	{
		if (errno == EBADF )
		{
			free(buf);
			return (NULL);
		}
		free(buf);
		return (NULL);
	}
	buf[BUFFER_SIZE + 1] = '\0';
	while(bytes_read > 0)
	{
		if (bytes_read == BUFFER_SIZE)
		{
			;
		}
		if (bytes_read < BUFFER_SIZE)
		{
			;
		}

	}








// 	new_line = malloc(sizeof(char) * n);
// 	if(!new_line)
// 	{
// 		free(buf);
// 		return (NULL);
// 	}
// // initialize new_line to empty string to check if previous call returned line and the next call is on a new line
// 	new_line[0] = '\0';
// // loop through buf until newline is found
// 	while (bytes_read > 0)
// 	{
// 		if (buf[0] == '\n')
// 		{
// 			*(new_line + i) = buf[0];
// 			temp = realloc(new_line, sizeof(char) * ++n);
// 			if (!temp)
// 			{
// 				free(buf);
// 				free(new_line);
// 				new_line = NULL;
// 				return (NULL);
// 			}
// 			new_line = temp;
// 			temp = NULL;
// 			*(new_line + i + 1) = '\0';
// 			free(buf);
// 			return (new_line);
// 		}
// 		*(new_line + i++) = buf[0];
// 		temp = realloc(new_line, sizeof(char) * ++n);
// 		if (!temp)
// 		{
// 			free(buf);
// 			free(new_line);
// 			new_line = NULL;
// 			return (NULL);
// 		}
// 		new_line = temp;
// 		temp = NULL;
// 		bytes_read = read(fd, buf, BUFFER_SIZE);
// 	}
// // if new line has content, return it
// 	if (new_line[0] != '\0')
// 	{
// 		free(buf);
// 		new_line[i] = '\0';
// 		return (new_line);
// 	}
// // if new line is empty, free memory and return NULL
// 	free(new_line);
// 	free(buf);
// 	return (NULL);
}
