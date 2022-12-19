/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:51:14 by gmarchal          #+#    #+#             */
/*   Updated: 2022/12/19 11:42:28 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, int n)
{
	int				i;
	unsigned char	*ret;

	i = 0;
	ret = s;
	while (i < n)
	{
		ret[i] = 0;
		i++;
	}
}

char	*ft_strdup_mod(char *s1)
{
	int		i;
	int		len;
	char	*ret;

	len = 0;
	while (s1[len] != '\n' && s1[len] != '\0')
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	ft_strlcpy(s1, s1 + i, BUFFER_SIZE + 1);
	return (ret);
}
