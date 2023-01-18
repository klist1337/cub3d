/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:38:41 by eassofi           #+#    #+#             */
/*   Updated: 2023/01/18 18:40:03 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	floorcast(mlx);
	draw_in_window(mlx);
}

void	raycasting(t_mlx *mlx)
{
	init_texture(mlx);
	init_buff(mlx);
	load_texture(mlx);
	create_img(mlx);
	mlx_loop_hook(mlx->mlx, &main_loop, mlx);
	mlx_hook(mlx->win, 2, 0, do_key, mlx);
	mlx_hook(mlx->win, ON_DESTROY, 0, close_window, mlx);
	mlx_loop(mlx->mlx);
}
