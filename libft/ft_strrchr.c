/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:41:09 by acouliba          #+#    #+#             */
/*   Updated: 2021/11/20 16:43:36 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	c = (char)c;
	str = 0;
	i = 0;
	if (c == 0)
		str = ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == c)
			str = ((char *)s + i);
		i++;
	}
	return (str);
}
