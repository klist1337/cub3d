/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:17:07 by eassofi           #+#    #+#             */
/*   Updated: 2023/01/16 16:16:54 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	main_loop(t_mlx *mlx)
{
	raycaster(mlx);
	draw(mlx);
	return (0);
}

int	select_key(int key)
{
	return (key == MV_FORWRD || key == MV_BACK
		|| key == ROT_RIGHT || key == ROT_LEFT
		|| key == MV_LEFT || key == MV_RIGHT);
}

void	move_forward(t_mlx *mlx)
{
	if (mlx->matrix[(int)(mlx->cub.pos_x
			+ mlx->cub.dir_x * mlx->cub.mv_speed)][(int)(mlx->cub.pos_y)] == 0)
		mlx->cub.pos_x += mlx->cub.dir_x * mlx->cub.mv_speed;
	if (mlx->matrix[(int)(mlx->cub.pos_x)][(int)(mlx->cub.pos_y
			+ mlx->cub.dir_y * mlx->cub.mv_speed)] == 0)
		mlx->cub.pos_y += mlx->cub.dir_y * mlx->cub.mv_speed;
}

void	move_backward(t_mlx *mlx)
{
	if (mlx->matrix[(int)(mlx->cub.pos_x
			- mlx->cub.dir_x * mlx->cub.mv_speed)][(int)(mlx->cub.pos_y)] == 0)
		mlx->cub.pos_x -= mlx->cub.dir_x * mlx->cub.mv_speed;
	if (mlx->matrix[(int)(mlx->cub.pos_x)][(int)(mlx->cub.pos_y
			- mlx->cub.dir_y * mlx->cub.mv_speed)] == 0)
		mlx->cub.pos_y -= mlx->cub.dir_y * mlx->cub.mv_speed;
}

int	do_key(int key, t_mlx *mlx)
{
	mlx->cub.mv_speed = 0.5;
	mlx->cub.rot_speed = 0.3;
	if (select_key(key))
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		move_key(key, mlx);
	}
	if (key == ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		global_free(mlx);
		exit(0);
	}
	raycaster(mlx);
	main_loop(mlx);
	return (0);
}
