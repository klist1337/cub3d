/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:32:50 by acouliba          #+#    #+#             */
/*   Updated: 2023/01/24 21:08:32 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	c = (char)c;
	str = (char *)s;
	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == c)
		return (str + i);
	return (0);
}
