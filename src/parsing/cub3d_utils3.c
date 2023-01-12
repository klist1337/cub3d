/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 05:15:10 by eassofi           #+#    #+#             */
/*   Updated: 2022/09/27 04:57:10 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	maximum(int a, int b)
{
	int	max;

	if (a >= b)
		max = a;
	else
		max = b;
	return (max);
}

void	display_matrix(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->height)
	{
		j = 0;
		while (j < mlx->width - 1)
		{
			printf("%d", mlx->matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	free_char_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_int_matrix(t_mlx *mlx, int **matrix)
{
	int	i;

	i = 0;
	while (i < mlx->height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	get_nb_of_split(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}
