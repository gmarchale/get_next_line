/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:17:25 by gmarchal          #+#    #+#             */
/*   Updated: 2022/11/21 20:59:19 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>		// delete (pour open)
#include <stdio.h>		// delete

char *get_next_line(int fd)
{
	static char my_static[BUFFER_SIZE + 1];
	char my_buffer[BUFFER_SIZE + 1];
	char *my_line;
	int i;
	int j;
	int end;
	int m;

	end = 0;
	j = 0;
	m = 0;
	my_line = malloc (sizeof(char) * (BUFFER_SIZE + 1)); //pas certain que ca soit la bonne taille de malloc
	if (!my_line)
		return (0);
	while (end != 1)
	{
		ft_bzero(my_buffer, BUFFER_SIZE + 1);
		read(fd, my_buffer, BUFFER_SIZE);
		i = 0;
		while (my_buffer[i])
		{
			if (my_buffer[i] == '\n')
				end = 1;
			else if (end != 1)
			{
				my_line[j] = my_buffer[i];
				j++;
			}
			else if (end == 1)
			{
				my_static[m] = my_buffer[i];
				m++;
			}
			i++;
		}
		my_line[j] = '\0';
	}
	return (my_line);
}
int main(void)
{
	int	fd;
	char *ligne;
	char *ligne2;

	fd = open("text1.txt", O_RDONLY);
	ligne = get_next_line(fd);
	ligne2 = get_next_line(fd);
	printf("%s\n", ligne);
	//printf("%s\n", my_static);
	printf("%s\n", ligne2);
	free(ligne);
}
