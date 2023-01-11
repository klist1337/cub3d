/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:15:53 by eassofi           #+#    #+#             */
/*   Updated: 2022/12/10 00:32:26 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
// #define mapWidth 24
// #define mapHeight 24

void	init_buff(t_mlx *mlx)
{
	int	y;
	int	x;

	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
			mlx->buffer[y][x] = 0;
	}
}

// void	wall_color(t_mlx *mlx, t_cub *cub, t_dda *dda)
// {
// 	if (mlx->matrix[cub->map_x][cub->map_y] == 1)
// 		mlx->color = 0x00FFFF;
// 	else if (mlx->matrix[cub->map_x][cub->map_y] == 2)
// 		mlx->color = 0x0000FF;
// 	else if (mlx->matrix[cub->map_x][cub->map_y] == 3)
// 		mlx->color = 0xFF0000;
// 	else if (mlx->matrix[cub->map_x][cub->map_y] == 4)
// 		mlx->color = 0xFFFF00;
// 	else
// 		mlx->color = 0xFFFFFF;
// 	if (dda->side == 1)
// 			mlx->color = mlx->color / 2;
// }

void	init_cub(t_cub *cub)
{
	cub->height = 0;
	cub->y = 0;
	cub->pos_x = 22;
	cub->pos_y = 12;
}

void	draw_in_window(t_mlx *mlx)
{
	t_cub	cub;
	t_dda	dda;
	int		x;

	x = -1;
	init_cub(&cub);
	mlx_clear_window(mlx->mlx, mlx->win);
	// if (mlx->re_buff == 1)
	// 	init_buff(mlx);
	while (++x < W)
	{
		mlx->cub.camera_x = 2 * x / (double)W - 1;
		cub.raydir_x = mlx->cub.dir_x + mlx->cub.plane_x * mlx->cub.camera_x;
		cub.raydir_y = mlx->cub.dir_y + mlx->cub.plane_y * mlx->cub.camera_x;
		init_dda_utils(&cub, mlx);
		dda_algoritm(mlx, &cub, &dda);
		texture_calculation(&cub, mlx, &dda, x);
	}
}

void	raycaster(t_mlx *mlx)
{
	floorcast(mlx); // texture for floor and celling
	//floorcast_color(mlx); // color for floor and celling
	draw_in_window(mlx);
}

void	raycasting(t_mlx *mlx)
{
	init_texture(mlx);
	init_buff(mlx);
	load_texture(mlx);
	create_img(mlx);
	mlx_loop_hook(mlx->mlx, &main_loop, mlx);
	mlx_key_hook(mlx->win, do_key, mlx);
	mlx_hook(mlx->win, ON_DESTROY, 0, close_window, mlx);
	mlx_loop(mlx->mlx);
}
