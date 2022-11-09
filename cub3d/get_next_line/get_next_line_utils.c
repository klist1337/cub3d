/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 01:52:41 by eassofi           #+#    #+#             */
/*   Updated: 2022/09/27 04:29:43 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr2(char *s, int c)
{
	if (!s)
		return (0);
	if (c == '\0')
		return (s);
	while (*s)
	{
		if (*s == (char) c)
			return (s);
		s++;
	}
	return (0);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	i = -1;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen2(s1) + ft_strlen2(s2) + 1));
	if (!ret)
		return (NULL);
	if (s1)
		while (s1[++i])
			ret[i] = s1[i];
	j = 0;
	while (s2[j])
		ret[i++] = s2[j++];
	ret[ft_strlen2(s1) + ft_strlen2(s2)] = '\0';
	free(s1);
	return (ret);
}
