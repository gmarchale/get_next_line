/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:51:14 by gmarchal          #+#    #+#             */
/*   Updated: 2023/01/11 17:11:52 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char	*ft_strdup_mod(char *s1, int *check)
{
	int		i;
	int		len;
	char	*ret;

	len = 0;
	while (s1[len] != '\n' && s1[len] != '\0')
		len++;
	if (s1[len] == '\n')
	{
		len++;
		*check = 1;
	}
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ret;

	ret = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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
	free(s1);
	free(s2);
	return (ret);
}

int	ft_strlcpy(char *dst, const char *src, int size)
{
	int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}
