/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:32:37 by eassofi           #+#    #+#             */
/*   Updated: 2022/09/27 04:28:06 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*saver(char *str)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * ft_strlen2(str) - i + 1);
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
	{
		s[j++] = str[i++];
	}
	s[j] = '\0';
	free(str);
	return (s);
}

char	*reader(int fd, char *str)
{
	char	*buff;
	int		r;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	r = 1;
	while (!ft_strchr2(str, '\n') && r != 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[r] = '\0';
		str = ft_strjoin2(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*lptr;
	static char	*str;

	lptr = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = reader(fd, str);
	if (!str)
		return (NULL);
	lptr = get_line(str);
	str = saver(str);
	return (lptr);
}
