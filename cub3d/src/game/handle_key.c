/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:17:07 by eassofi           #+#    #+#             */
/*   Updated: 2022/09/27 04:57:10 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	minimap(t_mlx *mlx)
{

}


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

void	move_right(t_mlx *mlx)
{
	if (mlx->matrix[(int)(mlx->cub.pos_x
			+ mlx->cub.dir_y * mlx->cub.mv_speed)][(int)(mlx->cub.pos_y)] == 0)
		mlx->cub.pos_x += mlx->cub.dir_y * mlx->cub.mv_speed;
	if (mlx->matrix[(int)(mlx->cub.pos_x)][(int)(mlx->cub.pos_y
			- mlx->cub.dir_x * mlx->cub.mv_speed)] == 0)
		mlx->cub.pos_y -= mlx->cub.dir_x * mlx->cub.mv_speed;
}

void	move_left(t_mlx *mlx)
{
	if (mlx->matrix[(int)(mlx->cub.pos_x
			- mlx->cub.dir_y * mlx->cub.mv_speed)][(int)(mlx->cub.pos_y)] == 0)
		mlx->cub.pos_x -= mlx->cub.dir_y * mlx->cub.mv_speed;
	if (mlx->matrix[(int)(mlx->cub.pos_x)][(int)(mlx->cub.pos_y
			+ mlx->cub.dir_x * mlx->cub.mv_speed)] == 0)
		mlx->cub.pos_y += mlx->cub.dir_x * mlx->cub.mv_speed;
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
	// printf("mv_speed2 = %f\n", mlx->cub.mv_speed);
	// printf("rot_speed2 =%f\n", mlx->cub.rot_speed);
	//printf("KEY %d\n", key);
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

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	global_free(mlx);
	exit(0);
}

int	do_key(int key, t_mlx *mlx)
{
	mlx->cub.mv_speed = 0.5;// constant value in squares / second
	mlx->cub.rot_speed = 0.3;// constant value in radian / second
	if (select_key(key))
	{
		//puts("here\n");
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