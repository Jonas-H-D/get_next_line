/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:11:03 by jhermon-          #+#    #+#             */
/*   Updated: 2021/11/22 17:01:06 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

#define BUF_SIZE 4096

char	*get_next_line(int fd)
{
	int	ret;
	char buf[BUF_SIZE + 1];

	ret = read(fd, buff, BUF_SIZE);
	buf[ret] = '\0';
	ft_putstr(buf); 
	if (close(fd) == -1)
	{
		return(NULL);
	}
}
