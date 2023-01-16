/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kader.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:20:39 by acouliba          #+#    #+#             */
/*   Updated: 2023/01/16 16:20:41 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_bg_part(int *x, int *y, int *j, t_mlx *mlx)
{
	*x = 0;
	*y = mlx->height;
	while (*j < mlx->height)
	{
		*x = maximum(*x, mlx->width_tab[(*j)]);
		(*j)++;
	}
	*j = 0;
}

void	draw_bg(t_mlx *mlx, int radius, t_point player, t_point translate)
{
	int			i;
	int			j;
	int			x;
	int			y;
	t_square	util;

	j = 0;
	util.radius = radius;
	util.mlx = mlx;
	util.point.y = j;
	draw_bg_part(&x, &y, &j, mlx);
	util.point.y = j;
	util.color = BLACK;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			util.point.y = j;
			util.point.x = i;
			square_player(util, player, translate);
			i++;
		}
		j++;
	}
}

t_square	draw_map_part(t_point *cube,
	t_point *player, t_point *translate, t_mlx *mlx)
{
	t_square	util;

	util.radius = CUBE_RADIUS;
	util.mlx = mlx;
	player->x = (int)(mlx->cub.pos_y);
	player->y = (int)(mlx->cub.pos_x);
	translate->x = player->x - 10;
	translate->y = player->y - 10;
	draw_bg(mlx, util.radius, *player, *translate);
	cube->x = 0;
	cube->y = 0;
	util.point.y = cube->y;
	return (util);
}

void	draw_map(t_mlx *mlx)
{
	t_point		cube;
	t_point		player;
	t_square	util;
	t_point		translate;

	util = draw_map_part(&cube, &player, &translate, mlx);
	while (cube.y < mlx->height)
	{
		cube.x = -1;
		while (++cube.x < mlx->width_tab[cube.y])
		{
			util.point = cube;
			if (mlx->matrix[cube.y][cube.x] == 1)
			{
				util.color = GREY;
				square_player(util, player, translate);
			}
			if (player.x == cube.x && player.y == cube.y)
			{
				util.color = RED;
				square_player(util, player, translate);
			}
		}
		cube.y++;
	}
}
