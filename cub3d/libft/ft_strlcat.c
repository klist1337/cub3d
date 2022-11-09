/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:47:10 by eassofi           #+#    #+#             */
/*   Updated: 2021/11/15 20:06:10 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	j = 0;
	src_len = ft_strlen(src);
	while (dst[i] && i < dstsize)
		i++;
	dst_len = i;
	if (!dstsize)
		return (src_len + dst_len);
	while (src[j] && dstsize - 1 > i + j)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (dst_len < dstsize)
		dst[i + j] = '\0';
	return (dst_len + src_len);
}
