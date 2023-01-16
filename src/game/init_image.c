/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:48:40 by eassofi           #+#    #+#             */
/*   Updated: 2023/01/13 19:40:01 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel;

	pixel = (char *)mlx->img.data
		+ (y * mlx->img.size_line + x * (mlx->img.bpp / 8));
	*(int *)pixel = color;
}

void	dda(t_point p1, t_point p2, t_mlx *mlx, int color)
{
	t_point	d;
	float	x;
	float	y;
	float	x_increment;
	float	y_increment;
	int		steps;

	d.x = p2.x - p1.x;
	d.y = p2.y - p1.y;
	if (abs(d.x) > abs(d.y))
		steps = abs(d.x);
	else
		steps = abs(d.y);
	x_increment = d.x / (float) steps;
	y_increment = d.y / (float) steps;
	x = p1.x;
	y = p1.y;
	for (int i = 0; i <= steps; i++)
	{
		put_pixel(mlx, (int)x, (int)y, color);
		x += x_increment;
		y += y_increment;
	}
}


void    square(t_square util)
{
	t_point fake_p1;
	t_point fake_p2;

	fake_p1.x = util.point.x - util.radius;
	fake_p1.y = util.point.y - util.radius;
	fake_p2.x = util.point.x + util.radius;
	fake_p2.y = util.point.y - util.radius;
	while (fake_p2.y <= util.point.y + util.radius)
	{
		dda(fake_p1, fake_p2, util.mlx, util.color);
		fake_p2.y++;
		fake_p1.y++;
	}
}

float distance(t_point p1, t_point p2)
{
	float	x;
	float	y;

	x = p2.x - p1.x;
	y = p2.y - p1.y;
	return sqrt(x * x + y * y);
}

void square_player(t_square util, t_point player, t_point translate)
{
	if (util.point.x > player.x + MINIMAP_LIMIT
		|| util.point.y > player.y + MINIMAP_LIMIT
		|| util.point.x < player.x - MINIMAP_LIMIT
		|| util.point.y < player.y - MINIMAP_LIMIT)
		return;

	util.point.x -= translate.x;
	util.point.y -= translate.y;
	util.point.x += TRANSLATE_X;
	util.point.y += TRANSLATE_Y;
	util.point.x = util.point.x + util.radius * 2 * util.point.x;
	util.point.y = util.point.y + util.radius * 2 * util.point.y;
	if (util.point.x + util.radius > W || util.point.y + util.radius > H
		|| util.point.x - util.radius < 0 || util.point.y - util.radius < 0)
		return;
	square(util);
}
void draw_bg(t_mlx *mlx, int radius, t_point player, t_point translate)
{
	int		i;
	int		j;
	int     x;
	int     y;
	t_square util;

	j = 0;
	util.radius = radius;
	util.mlx = mlx;
	util.point.y = j;
	x = 0;
	y = mlx->height;
	while (j < mlx->height)
	{
		x = maximum(x, mlx->width_tab[j]);
		j++;
	}
	j = 0;
	util.point.y = j;
	util.color = BLACK;
	while (j < y)
	{
		i = 0;
		while (i < x){
			util.point.y = j;
			util.point.x = i;
			square_player(util, player, translate);
			i++;
		}
		j++;
	}
}

void draw_map(t_mlx *mlx)
{
	t_point	cube;
	t_point player;
	t_square util;
	t_point translate;

	util.radius = CUBE_RADIUS;
	util.mlx = mlx;
	player.x = (int)(mlx->cub.pos_y);
	player.y = (int)(mlx->cub.pos_x);
	translate.x = player.x - 10;
	translate.y = player.y - 10;
	draw_bg(mlx, util.radius, player, translate);
	cube.x = 0;
	cube.y = 0;
	util.point.y = cube.y;
	while (cube.y < mlx->height)
	{
		cube.x = 0;
		while (cube.x < mlx->width_tab[cube.y]){
			util.point = cube;
			if (mlx->matrix[cube.y][cube.x] == 1)
			{
				util.color = GREY;
				square_player(util, player, translate);
			}
			if (player.x == cube.x && player.y ==  cube.y)
			{
				util.color = RED;
				square_player(util, player, translate);
			}
			cube.x++;
		}
		cube.y++;
	}
}


void	draw(t_mlx *mlx)
{
	int	x;
	int	y;

	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
		{
			mlx->img.data[y * W + x] = mlx->buffer[y][x];
		}
	}
	draw_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

void	load_image(t_mlx *mlx, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	y = -1;
	img->img = mlx_xpm_file_to_image(mlx->mlx, path,
			&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_line, &img->endian);
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
		{
			texture[img->img_width * y + x]
				= img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(mlx->mlx, img->img);
}

void	 load_texture(t_mlx *mlx)
{
	t_img	img;

	load_image(mlx, mlx->texture[0], mlx->path[0], &img);
	load_image(mlx, mlx->texture[1], mlx->path[1], &img);
	load_image(mlx, mlx->texture[2], mlx->path[2], &img);
	load_image(mlx, mlx->texture[3], mlx->path[3], &img);
	load_image(mlx, mlx->texture[6], "pics_xpm/wood.xpm", &img);
}

void	create_img(t_mlx *mlx)
{
	mlx->img.img = mlx_new_image(mlx->mlx, W, H);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
			&mlx->img.size_line, &mlx->img.endian);
}
