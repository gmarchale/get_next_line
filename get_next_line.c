/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:17:25 by gmarchal          #+#    #+#             */
/*   Updated: 2022/11/18 18:36:40 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>		// enlever cette ligne


char *get_next_line(int fd)
{
	static char variable[BUFFER_SIZE + 1];
	char my_buffer[BUFFER_SIZE + 1];
	int	i;
	int j;

	i = 0;
	j = 0;
	read(fd, my_buffer, BUFFER_SIZE);
	my_buffer[BUFFER_SIZE] = '\0';

	//printf("%s\n", my_buffer);
	while(my_buffer[i] || my_buffer[i] != '\n')
	{
		if (my_buffer[i] == '\n')
		{
			break ;
		}
		else
			write(1, &my_buffer[i], 1);
		i++;
	}
	while (my_buffer[i])
	{
		variable[j] = my_buffer[i + j];
		j++;
	}

	return (0);
}

int main(void)
{
	int	fd;

	fd = open("text1.txt", O_RDONLY);
	get_next_line(fd);
}
