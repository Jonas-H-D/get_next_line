/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:15:40 by jhermon-          #+#    #+#             */
/*   Updated: 2021/11/26 14:38:06 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*temp;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		printf("main.c temp = %s", temp);
		free(temp);
	} 
	return (0);
}
