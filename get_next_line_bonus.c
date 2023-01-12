/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:29:49 by gmarchal          #+#    #+#             */
/*   Updated: 2023/01/12 19:47:41 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_line(char *my_buffer, int *check, char *my_static)
{
	char	*my_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	my_line = malloc (sizeof(char) * (ft_strlen(my_buffer) + 1));
	if (!my_line)
		return (0);
	while (my_buffer[i] && *check != 1)
	{
		if (my_buffer[i] == '\n')
			*check = 1;
		my_line[i] = my_buffer[i];
		i++;
	}
	my_line[i] = '\0';
	if (i == 0)
		*check = 1;
	while (my_buffer[i])
		my_static[j++] = my_buffer[i++];
	my_static[j] = '\0';
	return (my_line);
}

static int	ft_read(int fd, char *my_buffer)
{
	int	read_return;

	read_return = 1;
	ft_bzero(my_buffer, BUFFER_SIZE + 1);
	read_return = read(fd, my_buffer, BUFFER_SIZE);
	if (read_return == -1)
	{
		ft_bzero(my_buffer, BUFFER_SIZE + 1);
		return (0);
	}
	return (1);
}

static char	*ft_free(char *str)
{
	free(str);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	my_static[OPEN_MAX][BUFFER_SIZE + 1];
	int			check;
	char		*my_line;
	char		my_buffer[BUFFER_SIZE + 1];
	char		*str;

	check = 0;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	str = ft_strdup_mod(my_static[fd], &check);
	if (!str)
		return (0);
	while (check == 0)
	{
		if (!ft_read(fd, my_buffer))
			return (ft_free(str));
		my_line = ft_line(my_buffer, &check, my_static[fd]);
		str = ft_strjoin(str, my_line);
	}
	if (!str[0])
		return (ft_free(str));
	return (str);
}
