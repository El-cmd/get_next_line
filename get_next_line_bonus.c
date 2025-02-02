/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 01:27:36 by vloth             #+#    #+#             */
/*   Updated: 2022/08/28 17:20:13 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*gnl(char *line, int fd, int ret, char **save)
{
	line = ft_substr(save[fd], 0, ret + 1, 0);
	save[fd] = ft_substr(save[fd], ret + 1, ft_strlen(save[fd]), 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		buff[BUFFER_SIZE + 1];
	int			ret;
	char		*line;

	ret = 1;
	line = 0;
	if (fd > 1024 || fd < 0 || BUFFER_SIZE < 1 || ret < 0)
		return (NULL);
	while ((where_is_n(save[fd]) == -1 || where_is_n(save[fd]) == 0) \
			&& ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = 0;
		if (ret < 0)
			return (NULL);
		save[fd] = ft_strjoin(save[fd], buff);
	}
	ret = w_is_n(save[fd]);
	if (ret == 0 && save[fd][ret] == 0)
	{	
		save[fd] = freeee(save[fd]);
		return (save[fd]);
	}
	return (gnl(line, fd, ret, save));
}
