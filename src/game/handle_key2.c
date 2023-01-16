/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:06:51 by eassofi           #+#    #+#             */
/*   Updated: 2023/01/16 16:18:09 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_left(t_mlx *mlx)
{
	if (mlx->matrix[(int)(mlx->cub.pos_x
			- mlx->cub.dir_y * mlx->cub.mv_speed)][(int)(mlx->cub.pos_y)] == 0)
		mlx->cub.pos_x -= mlx->cub.dir_y * mlx->cub.mv_speed;
	if (mlx->matrix[(int)(mlx->cub.pos_x)][(int)(mlx->cub.pos_y
			+ mlx->cub.dir_x * mlx->cub.mv_speed)] == 0)
		mlx->cub.pos_y += mlx->cub.dir_x * mlx->cub.mv_speed;
}

void	move_right(t_mlx *mlx)
{
	if (mlx->matrix[(int)(mlx->cub.pos_x
			+ mlx->cub.dir_y * mlx->cub.mv_speed)][(int)(mlx->cub.pos_y)] == 0)
		mlx->cub.pos_x += mlx->cub.dir_y * mlx->cub.mv_speed;
	if (mlx->matrix[(int)(mlx->cub.pos_x)][(int)(mlx->cub.pos_y
			- mlx->cub.dir_x * mlx->cub.mv_speed)] == 0)
		mlx->cub.pos_y -= mlx->cub.dir_x * mlx->cub.mv_speed;
}

void	rotate_right(t_mlx *mlx)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = mlx->cub.dir_x;
	old_plane_x = mlx->cub.plane_x;
	mlx->cub.dir_x = mlx->cub.dir_x * cos(-mlx->cub.rot_speed)
		- mlx->cub.dir_y * sin(-mlx->cub.rot_speed);
	mlx->cub.dir_y = old_dir_x * sin(-mlx->cub.rot_speed) + mlx->cub.dir_y
		* cos(-mlx->cub.rot_speed);
	mlx->cub.plane_x = mlx->cub.plane_x * cos(-mlx->cub.rot_speed)
		- mlx->cub.plane_y * sin(-mlx->cub.rot_speed);
	mlx->cub.plane_y = old_plane_x * sin(-mlx->cub.rot_speed)
		+ mlx->cub.plane_y * cos(-mlx->cub.rot_speed);
}

void	rotate_left(t_mlx *mlx)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = mlx->cub.dir_x;
	old_plane_x = mlx->cub.plane_x;
	mlx->cub.dir_x = mlx->cub.dir_x * cos(mlx->cub.rot_speed)
		- mlx->cub.dir_y * sin(mlx->cub.rot_speed);
	mlx->cub.dir_y = old_dir_x * sin(mlx->cub.rot_speed) + mlx->cub.dir_y
		* cos(mlx->cub.rot_speed);
	mlx->cub.plane_x = mlx->cub.plane_x * cos(mlx->cub.rot_speed)
		- mlx->cub.plane_y * sin(mlx->cub.rot_speed);
	mlx->cub.plane_y = old_plane_x * sin(mlx->cub.rot_speed)
		+ mlx->cub.plane_y * cos(mlx->cub.rot_speed);
}

void	move_key(int key, t_mlx *mlx)
{
	if (key == MV_FORWRD)
		move_forward(mlx);
	if (key == MV_BACK)
		move_backward(mlx);
	if (key == MV_RIGHT)
		move_right(mlx);
	if (key == MV_LEFT)
		move_left(mlx);
	if (key == ROT_RIGHT)
		rotate_right(mlx);
	if (key == ROT_LEFT)
		rotate_left(mlx);
}
