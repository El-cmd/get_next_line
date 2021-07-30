/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:23:51 by vloth             #+#    #+#             */
/*   Updated: 2021/07/30 23:31:48 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	where_is_n(char *save)
{
	int	i;

	i = 0;
	if (!save)
		return (-1);
	while (save[i])
	{
		if (save[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	w_is_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	return (i);
}

char	*freeee(char *save)
{
	if (save)
	{
		free(save);
		save = NULL;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		buff[BUFFER_SIZE + 1];
	int			ret;
	char		*line;

	ret = 1;
	if (fd > 1024 || fd < 0 || BUFFER_SIZE < 0 || ret < 0)
		return (NULL);
	while ((where_is_n(save) == -1 || where_is_n(save) == 0) && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = 0;
		if (ret < 0)
			return (NULL);
		save = ft_strjoin(save, buff);
	}
	ret = w_is_n(save);
	if (ret == 0 && save[ret] == 0)
	{
		save = freeee(save);
		return (NULL);
	}
	line = ft_substr(save, 0, ret + 1, 0);
	save = ft_substr(save, ret + 1, ft_strlen(save), 1);
	return (line);
}
