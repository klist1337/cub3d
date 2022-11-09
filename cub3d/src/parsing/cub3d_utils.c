/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 05:02:35 by eassofi           #+#    #+#             */
/*   Updated: 2022/09/27 04:57:10 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_error(char *s)
{
	write (1, s, ft_strlen(s));
}

void	skip_line_space(char **line, int fd)
{
	free(*line);
	*line = get_next_line(fd);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\f' || c == ' '
		|| c == '\v' || c == '\r')
		return (1);
	return (0);
}

size_t	ft_len(char *str)
{
	int			i;
	size_t		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		while (str[i] && ft_isalnum(str[i]))
		{
			nb++;
			i++;
		}
	}
	return (nb);
}

void	skip_and_fill(char *line, char *new)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (ft_isspace(line[i]))
			i++;
		new[j] = line[i];
		j++;
		i++;
	}
	new[j] = 0;
}
