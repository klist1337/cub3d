/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:28:27 by eassofi           #+#    #+#             */
/*   Updated: 2021/11/18 13:41:07 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, char const *set)
{
	int		start_index;
	int		end_index;
	char	*str_trim;

	if (s1 == 0)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start_index = 0;
	while (s1[start_index] && ft_strchr(set, s1[start_index]))
		start_index++;
	if (s1[start_index] == '\0')
		return (ft_calloc(1, 1));
	end_index = ft_strlen(s1);
	while (end_index >= 0 && ft_strchr(set, s1[end_index]))
		end_index--;
	str_trim = (char *) malloc((end_index - start_index + 2));
	if (str_trim == 0)
		return (0);
	ft_strlcpy(str_trim, s1 + start_index, (end_index - start_index + 2));
	return (str_trim);
}
