/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:39:47 by eassofi           #+#    #+#             */
/*   Updated: 2022/12/27 19:43:42 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	pos2(t_mlx *mlx)
{
	if (mlx->start_pos == 'W')
	{
		mlx->cub.dir_y = -1;
		mlx->cub.dir_x = 0;
		mlx->cub.plane_x = -0.66;
		mlx->cub.plane_y = 0;
	}
	if (mlx->start_pos == 'E')
	{
		mlx->cub.dir_y = 1;
		mlx->cub.dir_x = 0;
		mlx->cub.plane_y = 0;
		mlx->cub.plane_x = 0.66;
	}
}

void	pos(t_mlx *mlx)
{
	if (mlx->start_pos == 'N')
	{
		mlx->cub.dir_x = -1;
		mlx->cub.dir_y = 0;
		mlx->cub.plane_y = 0.66;
		mlx->cub.plane_x = 0;
	}
	if (mlx->start_pos == 'S')
	{
		mlx->cub.dir_x = 1;
		mlx->cub.plane_y = -0.66;
		mlx->cub.plane_x = 0;
		mlx->cub.dir_y = 0;
	}
	pos2(mlx);
}

void	player(t_mlx *mlx)
{
	long	h;
	long	w;

	h = 1;
	while (h <= mlx->start_y)
	{
		w = 1;
		while (w <= mlx->start_x)
		{
			mlx->cub.pos_x = h;
			mlx->cub.pos_y = w;
			w++;
		}
		h++;
	}
	pos(mlx);
}
