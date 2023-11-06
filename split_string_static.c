/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string_static.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:44:18 by orezek            #+#    #+#             */
/*   Updated: 2023/11/06 14:57:36 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line_counter(char *str)
{
	int	counter;
	counter = 0;
	while(*str++)
	{
		if (*str == '\n')
		counter++;
	}
	return (counter);
}

// "ahoj, ja jsem\npetr, jak\nsemas?"
char	*split_string_static(char *buf)
{
	static char	arr;
	char	*result;

	arr = buf;

	return (NULL);
}
