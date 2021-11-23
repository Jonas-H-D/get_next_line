/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:15:40 by jhermon-          #+#    #+#             */
/*   Updated: 2021/11/23 14:17:43 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	char	*temp;
	int	fd;

	fd = open("test.txt", O_RDONLY);

	while(1)
	{
		temp = get_next_line(fd);
		if (!temp)
		break ;
		printf("%s", temp);
		free(temp);
	}
	return (0);
}
