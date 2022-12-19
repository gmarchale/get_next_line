/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:36:38 by gmarchal          #+#    #+#             */
/*   Updated: 2022/12/19 11:42:17 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> // delete (pour open)
#include <stdio.h> // delete

char *get_next_line(int fd)
{
	static char	my_static[BUFFER_SIZE + 1];
	char		my_buffer[BUFFER_SIZE + 1];
	char		*my_line;
	char		*tmp;
	int			i;
	int			j;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	my_line = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!my_line)
		return (0);
	tmp = ft_strdup_mod(my_static);
	if (!tmp)
		return (0);
	my_line = ft_line(my_buffer)
	/*
	while (end != 1)
	{
		i = 0;
		ft_bzero(my_buffer, BUFFER_SIZE + 1);
		read(fd, my_buffer, BUFFER_SIZE);
		while (my_buffer[i])
		{
			// continuer ici
			// parcourt my_buffer et met tout dans my_line
		}
	}
	*/
}

char	*ft_line(char *str)
{
	char *my_line;

	my_line = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!my_line)
		return (0);
	ft_bzero(str, BUFFER_SIZE + 1);
	read(fd, my_buffer, BUFFER_SIZE);
	while (my_buffer[i])
	{
	}
	return (my_line);
}
