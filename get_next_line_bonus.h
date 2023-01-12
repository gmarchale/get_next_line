/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:35:25 by gmarchal          #+#    #+#             */
/*   Updated: 2023/01/12 18:35:59 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
void	ft_bzero(void *s, int n);
char	*ft_strdup_mod(char *s1, int *check);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlcpy(char *dst, const char *src, int size);

#endif
