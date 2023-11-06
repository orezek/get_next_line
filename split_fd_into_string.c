/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_fd_into_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:24:46 by orezek            #+#    #+#             */
/*   Updated: 2023/11/06 14:36:23 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*split_fd_into_string(int fd)
{
	static char	*buf; // global and static are initiated with NULL by default
	char		*newline;
	char		*temp;
	int			buffer_size;
	int			bytes_read;

	newline = NULL;
	temp	= NULL;
	buffer_size = 5;

// the delimeter is \n

	if (!buf)
	{
		// todo check malloc allocation
		buf = malloc(sizeof(char) * buffer_size + 1);
		// todo check read result and invalid fd
		bytes_read = read(fd, buf, buffer_size);
		*(buf + bytes_read) = '\0';
	}

 	if (buf[0] != '\0')
	{
		
	}



	free(buf);
	return (NULL);
}
