/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 01:27:49 by vloth             #+#    #+#             */
/*   Updated: 2022/08/28 01:44:42 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dest, void *src, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len, int test);
size_t	ft_strlen(char *str);

#endif