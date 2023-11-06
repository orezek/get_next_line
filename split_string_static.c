/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string_static.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:44:18 by orezek            #+#    #+#             */
/*   Updated: 2023/11/06 23:45:55 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//cc split_string_static.c get_next_line_utils.c && ./a.out
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

int	find_new_line_position(	char *str)
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
// Generator function that returns string and retains state
// between calls. It will return NULL when there is no more string to return.
char	*ft_nwsplit_generator(char *str)
{
	static char	*arr;
	char	*result;
	int		new_line_position;

	new_line_position = 0;
	if (!arr)
		arr = strdup(str);
	if (arr[0] == '\0')
	{
		free(arr);
		return (arr = NULL);
	}
	new_line_position = find_new_line_position(arr);
	if (new_line_position >= 0)
	{
		result = malloc(sizeof(char) * (new_line_position + 2));
		result = strncpy(result, arr, new_line_position + 1);
		result[new_line_position + 1] = '\0';
		arr = memmove(arr, arr + new_line_position + 1, ft_strlen(arr) - new_line_position);
		return (result);
	}
	else if (new_line_position == -1)
	{
		result = malloc(sizeof(char) * ft_strlen(arr) + 1);
		result = strcpy(result, arr);
		arr[0] = '\0';
		return (result);
	}
	free(arr);
	return (arr = NULL);
}

int	main(void)
{
	char	*str = "ahoj,ja jsem aldo\na tohle je test\na tohle je dalsi test\n";
	char	*result;

	result = ft_nwsplit_generator(str);
	while (result != NULL)
	{
		printf("%s", result);
		free(result);
		result = ft_nwsplit_generator(str);
	}
	free(result);


	return (0);
}


// vraci get_next_line string zakoceny new line nebo nulou? - vraci string vcetne new line a nuly
// vrati strncpy string zakonceny nulou? - nevraci!
// pouziju memmove k premisteni byte z jedne casti na druhou
