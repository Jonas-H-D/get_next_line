/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:34:01 by jhermon-          #+#    #+#             */
/*   Updated: 2021/12/03 09:44:35 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *save)
{
	char	*str;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = malloc(sizeof (char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_save(char *save)
{
	char	*str;
	int		i;
	int		c;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = malloc((ft_strlen(save) - i + 1) * sizeof (char));
	if (!str)
		return (NULL);
	c = 0;
	i++;
	while (save[i])
	{
		str[c++] = save[i++];
	}
	str[c] = '\0';
	free (save);
	return (str);
}

char	*ft_read(int fd, char *save)
{
	int		read_bytes;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (!buff)
		return (0);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (buff);
			return (0);
		}
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free (buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read(fd, save);
	if (!save || save == NULL)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
