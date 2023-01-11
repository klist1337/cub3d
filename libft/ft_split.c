/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:36:57 by eassofi           #+#    #+#             */
/*   Updated: 2021/12/21 19:35:21 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	i;
	int	wc;

	i = 1;
	wc = 0;
	if (s[0] != c)
		wc++;
	while (s[i])
	{
		if ((s[i - 1] == c && s[i] != c))
			wc++;
		i++;
	}
	return (wc);
}

static void	set_all_memory_null(char **strs, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(strs[i]);
	}
	free(strs);
	return ;
}

void	split2(const char *s, char **strs, char c)
{
	int		index;
	char	*ptr;

	index = 0;
	while (*s)
	{
		if (*s != c)
		{
			ptr = (char *) s;
			while (*ptr && *ptr != c)
				ptr++;
			strs[index] = (char *)malloc(ptr - s + 1);
			ft_strlcpy(strs[index++], s, ptr - s + 1);
			s = ptr;
		}
		else
			s++;
	}
	strs[index] = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		index;

	if (!s)
		return (NULL);
	if ((!ft_strlen(s) && !c) || !ft_strlen(s))
	{
		strs = (char **)malloc(sizeof(char *));
		strs[0] = NULL;
		return (strs);
	}
	index = count_word(s, c);
	strs = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!strs)
		return (NULL);
	split2(s, strs, c);
	if (strs == 0)
	{
		set_all_memory_null(strs, index);
		return (0);
	}
	return (strs);
}
