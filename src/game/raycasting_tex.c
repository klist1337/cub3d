/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_tex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:51:17 by eassofi           #+#    #+#             */
/*   Updated: 2023/01/18 04:47:00 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_texture(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	mlx->texture = (int **)malloc(sizeof (int *) * 8);
	if (!mlx->texture)
		exit(0);
	while (++i < 8)
		mlx->texture[i] = (int *)malloc(sizeof(int) * (TEXT_H * TEXT_W));
	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < TEXT_H * TEXT_W)
			mlx->texture[i][j] = 0;
	}
}

void	step_texture(t_mlx *mlx, t_cub *cub, t_dda *dda, int x)
{
	double		step;
	double		text_pos;
	int			y;
	int			color;

	step = 1.0 * TEXT_H / cub->line_height;
	y = cub->draw_start - 1;
	text_pos = (cub->draw_start - H / 2 + cub->line_height) * step;
	while (++y < cub->draw_end)
	{
		cub->text_y = (int)text_pos & (TEXT_H - 1);
		text_pos += step;
		color = mlx->texture[cub->text_num][TEXT_H * cub->text_y + cub->text_x];
		if (dda->side == 1)
			color = (color >> 1) & 8355711;
		mlx->buffer[y][x] = color;
	}
}

void	set_texture(t_dda *dda, t_cub *cub)
{
	if (dda->side == 0 && cub->raydir_x < 0)
		cub->text_num = 0;
	if (dda->side == 0 && cub->raydir_x >= 0)
		cub->text_num = 1;
	if (dda->side == 1 && cub->raydir_y < 0)
		cub->text_num = 2;
	if (dda->side == 1 && cub->raydir_y >= 0)
		cub->text_num = 3;
}

void	texture_calculation(t_cub *cub, t_mlx *mlx, t_dda *dda, int x)
{
	set_texture(dda, cub);
	if (dda->side == 0)
		cub->wall_x = mlx->cub.pos_y + cub->perpwalldist * cub->raydir_y;
	else
		cub->wall_x = mlx->cub.pos_x + cub->perpwalldist * cub->raydir_x;
	cub->wall_x -= floor(cub->wall_x);
	cub->text_x = (int)(cub->wall_x * (double)(TEXT_W));
	if (dda->side == 0 && cub->raydir_x > 0)
		cub->text_x = TEXT_W - cub->text_x - 1;
	if (dda->side == 1 && cub->raydir_x < 0)
		cub->text_x = TEXT_W - cub->text_x - 1;
	step_texture(mlx, cub, dda, x);
}
