/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:07:30 by acouliba          #+#    #+#             */
/*   Updated: 2021/11/20 16:23:30 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_strcpy(char	*dst, char	*src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	len = i + ft_strlen(s2) + 1;
	res = (char *)malloc(len * sizeof(char));
	if (!res)
		return (0);
	ft_strcpy(res, (char *)s1);
	ft_strcpy(res + i, (char *)s2);
	return (res);
}
