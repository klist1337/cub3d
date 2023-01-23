/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:55:47 by eassofi           #+#    #+#             */
/*   Updated: 2023/01/23 18:06:41 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_dda_utils(t_cub *cub, t_mlx *mlx)
{
	cub->map_x = (int)mlx->cub.pos_x;
	cub->map_y = (int)mlx->cub.pos_y;
	if (cub->raydir_x == 0)
		cub->delta_distx = 1e30;
	else
		cub->delta_distx = fabs(1 / cub->raydir_x);
	if (cub->raydir_y == 0)
		cub->delta_distx = 1;
	else
		cub->delta_disty = fabs(1 / cub->raydir_y);
}

void	initial_distside_x(t_mlx *mlx, t_cub *cub, t_dda *dda)
{
	if (cub->raydir_x < 0)
	{
		dda->step_x = -1;
		cub->side_distx = (mlx->cub.pos_x - cub->map_x) * cub->delta_distx;
	}
	else
	{
		dda->step_x = 1;
		cub->side_distx
			= (cub->map_x + 1.0 - mlx->cub.pos_x) * cub->delta_distx;
	}
}

void	initial_distside_y(t_mlx *mlx, t_cub *cub, t_dda *dda)
{
	if (cub->raydir_y < 0)
	{
		dda->step_y = -1;
		cub->side_disty = (mlx->cub.pos_y - cub->map_y) * cub->delta_disty;
	}
	else
	{
		dda->step_y = 1;
		cub->side_disty = (cub->map_y + 1.0 - mlx->cub.pos_y)
			* cub->delta_disty;
	}
}

void	perfom_dda(t_mlx *mlx, t_dda *dda, t_cub *cub)
{
	while (dda->hit == 0)
	{
		if (cub->side_distx < cub->side_disty)
		{
			cub->side_distx += cub->delta_distx;
			cub->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			cub->side_disty += cub->delta_disty;
			cub->map_y += dda->step_y;
			dda->side = 1;
		}
		if (mlx->matrix[cub->map_x][cub->map_y] == 1)
			dda->hit = 1;
	}
}

void	dda_algoritm(t_mlx *mlx, t_cub *cub, t_dda *dda)
{
	dda->hit = 0;
	initial_distside_x(mlx, cub, dda);
	initial_distside_y(mlx, cub, dda);
	perfom_dda(mlx, dda, cub);
	if (dda->side == 0)
		cub->perpwalldist = cub->side_distx - cub->delta_distx;
	else
		cub->perpwalldist = cub->side_disty - cub->delta_disty;
	cub->line_height = (int)(H / cub->perpwalldist);
	cub->draw_start = -cub->line_height / 2 + H / 2;
	if (cub->draw_start < 0)
		cub->draw_start = 0;
	cub->draw_end = cub->line_height / 2 + H / 2;
	if (cub->draw_end >= H || cub->draw_end < 0)
		cub->draw_end = H - 1;
}
