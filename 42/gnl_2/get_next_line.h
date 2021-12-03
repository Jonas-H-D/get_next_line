/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:35:47 by jhermon-          #+#    #+#             */
/*   Updated: 2021/12/03 09:52:44 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFERSIZE 10
# endif
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
// uses the read function to feel up the buff with string until \n 
char	*ft_read(int fd, char *save);
/* ft_save will save what is left after the \n to be use in the next read */
char	*ft_save(char *save);
/* will extract the line from the save and return it for reading */
char	*ft_get_line(char *save);
/* strjoin is giving here a '\0' value to s1 if no s1 present, 
 * it returns s1 and s2 together as 1 string. */
char	*ft_strjoin(char *s1, char *s2);
/* find the occurence of c in s1 and changes the int into a char */
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);

#endif
