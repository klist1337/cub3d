/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:48:40 by eassofi           #+#    #+#             */
/*   Updated: 2022/09/27 04:57:10 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


//void	put_pixel(t_s settings, int x, int y, int color)
//{
//	char	*pixel;
//
//	pixel = settings.addr + (y * settings.line_len + x * (settings.bpp / 8));
//	*(int *)pixel = color;
//}

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
//    mlx->img.data[y * W + x] = mlx->buffer[0][400];
//    return;
    char *pixel;

	pixel = (char *)mlx->img.data + (y * mlx->img.size_line + x * (mlx->img.bpp / 8));
	*(int *)pixel = color;
}

void	put_pixel2(t_mlx *mlx, int x, int y, int color)
{
    mlx->img.data[y * W + x] = mlx->texture[6][50];
    return;
}

void dda(t_point p1, t_point p2, t_mlx *mlx, int color)
{
	// calculate the dx and dy values
	int dx = p2.x - p1.x;
	int dy = p2.y - p1.y;

	// calculate the number of steps needed
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	// calculate the increment in x and y for each step
	float xIncrement = dx / (float) steps;
	float yIncrement = dy / (float) steps;

	// start from the first point
	float x = p1.x;
	float y = p1.y;

	// draw the line
	for (int i = 0; i <= steps; i++)
	{
		put_pixel(mlx, (int)x, (int)y, color);
		// increment the x and y values
		x += xIncrement;
		y += yIncrement;
	}
}


void	square(t_point point, int radius, t_mlx *mlx, int color)
{
	t_point	fake_p1;
	t_point	fake_p2;

	fake_p1.x = point.x - radius;
	fake_p1.y = point.y - radius;
	fake_p2.x = point.x + radius;
	fake_p2.y = point.y - radius;
	while (fake_p2.y <= point.y + radius)
	{
		dda(fake_p1, fake_p2, mlx, color);
		fake_p2.y++;
		fake_p1.y++;
	}
}

void draw_bg(t_mlx *mlx, int radius)
{
    int		i;
    int		j;
    int     x;
    int     y;
    t_point point;

    radius = 4;
    j = 0;
    point.y = j;
    x = 0;
    y = mlx->height;
    while (j < mlx->height)
    {
        x = maximum(x, mlx->width_tab[j]);
        j++;
    }
    t_img *img;
//    img->img = mlx_xpm_file_to_image(mlx->mlx, "pics_xpm/wood.xpm", &x, &y);
//    img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
//                                         &img->size_line, &img->endian);

    j = 0;
    point.y = j;
    while (j < y)
    {
        i = 0;
        point.x = i;
        while (i < x){
            square(point, radius, mlx, GREY);
            point.x += radius * 2 + 1;
            i++;
        }
        point.y += radius * 2 + 1;
        j++;
    }
}


void draw_map(t_mlx *mlx)
{
	int		i;
	int		j;
	int 	radius;
    t_point point;

    radius = 4;
    draw_bg(mlx, radius);
    i = 0;
	j = 0;
    point.y = j;
	while (j < mlx->height)
	{
		i = 0;
        point.x = i;
		while (i < mlx->width_tab[j]){
			if (mlx->matrix[j][i] == 1){
				square(point, radius, mlx, BLACK);
			}
            point.x += radius * 2;
            point.x++;
            i++;
		}
        point.y += radius * 2;
        point.y++;
        j++;
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

//	y = 0;
//	while(y < mlx->height)
//	{
//		int x = 0;
//		while(x <  mlx->width_tab[y])
//		{
//			mlx_pixel_put(mlx, mlx->win, x, y, 0x00FF0000);
//			x++;
//		}
//		y++;
//		printf("\n");
//	}

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
