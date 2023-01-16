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

float	distance(t_point p1, t_point p2)
{
	float	x;
	float	y;

	x = p2.x - p1.x;
	y = p2.y - p1.y;
	return (sqrt(x * x + y * y));
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

void	load_texture(t_mlx *mlx)
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
