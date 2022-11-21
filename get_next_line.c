/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:17:25 by gmarchal          #+#    #+#             */
/*   Updated: 2022/11/21 16:56:52 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>		// delete (pour open)
#include <stdio.h>		// delete

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (!s1 || !s2)
		return (0);
	ret = malloc (sizeof(char const) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ret[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		ret[j++] = s2[i];
		i++;
	}
	ret[j] = '\0';
	//rajouter un free
	return (ret);
}

char *get_next_line(int fd)
{
	//static char my_static[BUFFER_SIZE + 1];
	char my_buffer[BUFFER_SIZE + 1];
	char *my_line;
	int i;
	int j;
	int end;

	end = 0;
	j = 0;
	my_line = malloc (sizeof(char) * (BUFFER_SIZE + 1)); //pas certain que ca soit la bonne taille de malloc
	while (end != 1)
	{
		read(fd, my_buffer, BUFFER_SIZE);
		i = 0;
		while (my_buffer[i] && end != 1)
		{
			if (my_buffer[i] == '\n')
				end = 1;
			else
			{
				my_line[j] = my_buffer[i];
				j++;
				i++;
			}
		}
	}
	return (my_line);
}
int main(void)
{
	int	fd;

	fd = open("text1.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}
