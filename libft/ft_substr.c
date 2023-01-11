/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:39:38 by eassofi           #+#    #+#             */
/*   Updated: 2021/11/15 23:31:21 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	size_sub_str;
	size_t			i;

	if (s == 0)
		return (0);
	if (start >= ft_strlen(s))
	{
		return (ft_calloc(1, 1));
	}
	size_sub_str = min(ft_strlen(s) - start, len);
	sub = (char *)malloc(sizeof(char) * (size_sub_str + 1));
	i = 0;
	if (sub == 0)
		return (0);
	while (i < size_sub_str)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
