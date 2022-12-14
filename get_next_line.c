/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:17:25 by gmarchal          #+#    #+#             */
/*   Updated: 2022/11/25 17:37:27 by gmarchal         ###   ########.fr       */
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
	char *tmp;
	int left_to_read;
	int i;
	int j;
	int end;
	int m;

	end = 0;
	i = 0;
	j = 0;
	m = 0;
	
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	left_to_read = BUFFER_SIZE;
	my_line = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!my_line)
		return (0);
	while (my_static[i])
	{

	}
	tmp = ft_strdup_mod(my_static);
	if (!tmp)
		return (0);
	while (end != 1 && left_to_read > 0)
	{
		ft_bzero(my_buffer, BUFFER_SIZE + 1);
		left_to_read = read(fd, my_buffer, BUFFER_SIZE);
		i = 0;
		while (my_buffer[i])
		{
			if (end != 1)
			{
				if (my_buffer[i] == '\n')
					end = 1;
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
		end = 1;
	}
	if (left_to_read == 0 && my_buffer[0] == '\0')
		return (NULL);
	return (ft_strjoin(tmp, my_line));
}

int main(void)
{
	int fd;
	char *ligne;

	fd = open("test_file", O_RDONLY);
	ligne = get_next_line(fd);
	while (ligne)
	{
		printf("%s", ligne);		
		ligne = get_next_line(fd);
	}
}
