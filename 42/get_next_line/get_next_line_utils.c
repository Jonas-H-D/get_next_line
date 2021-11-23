/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:11:22 by jhermon-          #+#    #+#             */
/*   Updated: 2021/11/23 14:30:43 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &n, 1);
}

void	ft_putstr(char	*str)
{
	while(*str)
	{
		ft_putchar(*str);
		str++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	len;
	char	*dup;

	len = ft_strlen(str) + 1;
	dup = (char *)malloc(sizeof(char) * len);
	if (dup == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		dup[i] =str[i];
	return (dup);
}

/* Alloue (avec malloc(3)) et retourne une chaine de
caractères issue de la chaine ’s’.
Cette nouvelle chaine commence à l’index ’start’ et
a pour taille maximale ’len’
*/
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	srclen;
	char	*str;

	if (!s)
		return (NULL);
	srclen = ft_strlen(s);
	if (start > srclen)
		return (ft_putstr(""));
	if (start + len > srclen)
		len = srclen - start;
	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*The strchr() function locates the first
     occurrence of c (converted to a char)
     in the string pointed to by s.  The
     terminating null character is consid-
     ered to be part of the string; there-
     fore if c is `\0', the functions locate
     the terminating `\0'.
*/
char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	ch;

	str = (char *)s;
	ch = (char) c;
	while (*str)
	{
		if (*str = ch)
			return (str);
		str++;
	}
	if (*str == ch)
		return (str);
	return (NULL);
}

/*  Alloue (avec malloc(3)) et retourne une nouvelle
chaine, résultat de la concaténation de s1 et s2
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof (char) * size);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
