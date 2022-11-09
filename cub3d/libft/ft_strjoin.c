/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:33:50 by eassofi           #+#    #+#             */
/*   Updated: 2021/11/15 20:04:13 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char const *s1, char	*res)
{
	int		len_s1;
	int		i;

	i = 0;
	len_s1 = ft_strlen(s1);
	while (i < len_s1)
	{
		res[i] = s1[i];
		i++;
	}
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;
	char	*ret;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (ret == 0)
		return (0);
	ft_strcpy(s1, ret);
	i = len_s1;
	j = 0;
	while (s2[j] && j < len_s2)
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}
