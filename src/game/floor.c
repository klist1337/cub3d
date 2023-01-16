/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:20:35 by eassofi           #+#    #+#             */
/*   Updated: 2023/01/16 16:04:40 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	floor_castx(t_cub *cub, int y, t_mlx *mlx)
{
	int	cellx;
	int	celly;
	int	color;
	int	x;

	x = -1;
	while (++x < W)
	{
		cellx = (int)cub->floorx;
		celly = (int)cub->floory;
		cub->tx = (int)(TEXT_W * (cub->floorx - cellx)) & (TEXT_W - 1);
		cub->ty = (int)(TEXT_H * (cub->floory - celly)) & (TEXT_H - 1);
		cub->floorx += cub->floor_stepx;
		cub->floory += cub->floor_stepy;
		cub->floor_texture = 3;
		cub->ceiling_texture = 6;
		color = mlx->texture[cub->floor_texture][TEXT_W * cub->ty + cub->tx];
		color = (color >> 1) & 8355711;
		mlx->buffer[y][x] = color;
		color = mlx->texture[cub->ceiling_texture][TEXT_W * cub->ty + cub->tx];
		color = (color >> 1) & 8355711;
		mlx->buffer[H - y - 1][x] = color;
	}
}

void	floorcast(t_mlx *mlx)
{
	int		p;
	float	posz;
	int		y;
	t_cub cub;

	y = -1;
	init_cub(&cub);
	while (++y < H)
	{
		cub.ray_dirx0 = mlx->cub.dir_x - mlx->cub.plane_x;
		cub.ray_diry0 = mlx->cub.dir_y - mlx->cub.plane_y;
		cub.ray_dirx1 = mlx->cub.dir_x + mlx->cub.plane_x;
		cub.ray_diry1 = mlx->cub.dir_y + mlx->cub.plane_y;
		p = y - H / 2;
		posz = 0.5 * H;
		cub.row_dist = posz / p;
		cub.floor_stepx = cub.row_dist
			* (cub.ray_dirx1 - cub.ray_dirx0) / W;
		cub.floor_stepy = cub.row_dist
			* (cub.ray_diry1 - cub.ray_diry0) / W;
		cub.floorx = mlx->cub.pos_x + cub.row_dist * cub.ray_dirx0;
		cub.floory = mlx->cub.pos_y + cub.row_dist * cub.ray_diry0;
		floor_castx(&cub, y, mlx);
	}
}

void	floorcast_color(t_mlx *mlx)
{
	int	y;
	int	x;
	int	color;

	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
		{
			color = mlx->floor_color;
			mlx->buffer[y][x] = color;
			color = mlx->celling_color;
			mlx->buffer[H - y - 1][x] = color;
		}
	}	
}
