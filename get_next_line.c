/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:17:25 by gmarchal          #+#    #+#             */
/*   Updated: 2022/11/17 16:30:01 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd)
{
	char my_buffer[BUFFER_SIZE + 1];
	int	i;

	i = 0;
	read(fd, my_buffer, BUFFER_SIZE);
	my_buffer[BUFFER_SIZE] = '\0';

	printf("%s\n", my_buffer);
	return (0);
}

int main(void)
{
	int	fd;

	fd = open("text1.txt", O_RDONLY);
	get_next_line(fd);
}
