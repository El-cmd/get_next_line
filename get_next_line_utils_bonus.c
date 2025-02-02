/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 01:27:53 by vloth             #+#    #+#             */
/*   Updated: 2022/08/28 01:44:16 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	char	*ndest;
	char	*nsrc;
	size_t	i;

	ndest = (char *)dest;
	nsrc = (char *)src;
	if (!dest && !src)
		return (0);
	i = 0;
	while (n > i)
	{
		ndest[i] = nsrc[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;

	if (s2 != 0)
	{
		join = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!join)
			return (0);
		ft_memcpy(join, s1, ft_strlen(s1));
		ft_memcpy(join + ft_strlen(s1), s2, ft_strlen(s2) + 1);
		join[ft_strlen(s1) + ft_strlen(s2)] = 0;
		free(s1);
		s1 = NULL;
		return (join);
	}
	return (s1);
}

char	*tst(int test, char *s)
{
	if (test == 1)
	{
		free(s);
		s = NULL;
	}
	return (s);
}

char	*ft_substr(char *s, unsigned int start, size_t len, int test)
{
	char	*new;
	int		i;

	new = 0;
	if (start > ft_strlen(s))
	{
		new = malloc(sizeof(char) * 1);
		if (!new)
			return (NULL);
		s = tst(test, s);
		new[0] = '\0';
		return (new);
	}
	if (len > ft_strlen(&s[start]))
		new = malloc(sizeof(char) * ft_strlen(&s[start]) + 1);
	else
		new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && len-- != 0)
		new[i++] = s[start++];
	s = tst(test, s);
	new[i] = '\0';
	return (new);
}
