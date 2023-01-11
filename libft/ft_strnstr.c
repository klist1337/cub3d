/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:54:38 by eassofi           #+#    #+#             */
/*   Updated: 2021/11/15 20:23:21 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	needle_len = ft_strlen(needle);
	i = 0;
	if (*needle == '\0')
	{
		return ((char *) haystack);
	}
	if (len == 0)
		return (0);
	while (haystack[i] && i <= (len - needle_len))
	{
		if (0 == ft_strncmp((haystack + i), needle, needle_len))
		{
			return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}
