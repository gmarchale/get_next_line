/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:11:13 by gmarchal          #+#    #+#             */
/*   Updated: 2022/11/21 19:07:58 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

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

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	len = ft_strlen(s1);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
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
