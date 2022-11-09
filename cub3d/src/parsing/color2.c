/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:21:42 by eassofi           #+#    #+#             */
/*   Updated: 2022/09/27 04:57:10 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

unsigned long	creatergb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int	check_nb_comma(char *s)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ',')
			nb++;
		i++;
	}
	return (nb);
}

int	color_isdigit(char *rgbcolor)
{
	char	**matrix;
	int		i;
	int		j;

	i = -1;
	matrix = ft_split(rgbcolor, ',');
	while (matrix[++i])
	{
		j = 0;
		while (matrix[i][j] && matrix[i][j] != '\n')
		{
			if (ft_isalpha(matrix[i][j]))
			{
				return (0);
				free_char_matrix(matrix);
			}
			j++;
		}
	}
	free_char_matrix(matrix);
	return (1);
}

int	convert_colorrgb(char *rgbcolor, long *color)
{
	char	**matrix;
	int		i;

	i = -1;
	if (check_nb_comma(rgbcolor) != 2 || !color_isdigit(rgbcolor))
	{
		print_error("Error : invalid map\n");
		return (1);
	}
	matrix = ft_split(rgbcolor, ',');
	while (matrix[++i])
	{
		if ((get_nb_of_split(matrix) != 3
				|| ft_atoi(matrix[i]) < 0 || ft_atoi(matrix[i]) > 255))
		{
			free_char_matrix(matrix);
			print_error("Error : bad color\n");
			return (1);
		}
	}
	*color = creatergb(ft_atoi(matrix[0]),
			ft_atoi(matrix[1]), ft_atoi(matrix[2]));
	free_char_matrix(matrix);
	return (0);
}
