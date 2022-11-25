/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:39:49 by gmarchal          #+#    #+#             */
/*   Updated: 2022/11/25 17:37:31 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_strlen(const char *s);
void	ft_bzero(void *s, int n);
char	*ft_strdup_mod(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlcpy(char *dst, const char *src, int size);
char 	*get_next_line(int fd);
char	*check_bn(char *str);

#endif
