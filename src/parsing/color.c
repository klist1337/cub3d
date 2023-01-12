/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:17:17 by eassofi           #+#    #+#             */
/*   Updated: 2022/09/27 04:57:10 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_nb_elmt(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (mlx->nb_elemt[i] > 1)
			return (0);
	}
	return (1);
}

int	check_nb_elmt2(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (mlx->nb_elemt[i] > 0)
			return (1);
	}
	return (0);
}

void	fill_color2(char **matrix, int nb, char **color)
{
	char	*tmp;

	if (nb == 2)
	{
		*color = ft_strdup(matrix[1]);
		free_char_matrix(matrix);
	}
	else if (nb > 2)
	{
		nb = 1;
		while (matrix[++nb])
		{
			tmp = matrix[1];
			matrix[1] = ft_strjoin(matrix[1], matrix[nb]);
			free(tmp);
		}
		*color = ft_strdup(matrix[1]);
		free_char_matrix(matrix);
	}
}

int	fill_color(char *str, char **color)
{
	char	**matrix;
	int		nb;

	nb = 0;
	matrix = ft_split(str, ' ');
	nb = get_nb_of_split(matrix);
	if (!matrix[1])
	{
		print_error("Error: Bad color\n");
		free_char_matrix(matrix);
		return (0);
	}
	fill_color2(matrix, nb, color);
	return (1);
}

int	get_rgb(t_mlx *mlx, char *str)
{
	if ((str[0] == 'F' && ft_isspace(str[1]))
		|| (str[0] == 'C' && ft_isspace(str[1])))
	{
		if (str[0] == 'F' && ft_isspace(str[1]))
		{
			if (!fill_color(str, &mlx->floor))
				return (0);
		}
		if (str[0] == 'C' && ft_isspace(str[1]))
		{
			if (!fill_color(str, &mlx->celling))
				return (0);
		}
	}
	return (1);
}
