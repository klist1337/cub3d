/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kader_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:20:26 by acouliba          #+#    #+#             */
/*   Updated: 2023/01/16 16:20:28 by acouliba         ###   ########.fr       */
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
	t_point		d;
	t_pointf	tf;
	t_pointf	increment;
	int			steps;
	int			i;

	i = 0;
	d.x = p2.x - p1.x;
	d.y = p2.y - p1.y;
	if (abs(d.x) > abs(d.y))
		steps = abs(d.x);
	else
		steps = abs(d.y);
	increment.x = d.x / (float) steps;
	increment.y = d.y / (float) steps;
	tf.x = p1.x;
	tf.y = p1.y;
	while (i <= steps)
	{
		put_pixel(mlx, (int)tf.x, (int)tf.y, color);
		tf.x += increment.x;
		tf.y += increment.y;
		i++;
	}
}

void	square(t_square util)
{
	t_point	fake_p1;
	t_point	fake_p2;

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

void	square_player(t_square util, t_point player, t_point translate)
{
	if (util.point.x > player.x + MINIMAP_LIMIT
		|| util.point.y > player.y + MINIMAP_LIMIT
		|| util.point.x < player.x - MINIMAP_LIMIT
		|| util.point.y < player.y - MINIMAP_LIMIT)
		return ;
	util.point.x -= translate.x;
	util.point.y -= translate.y;
	util.point.x += TRANSLATE_X;
	util.point.y += TRANSLATE_Y;
	util.point.x = util.point.x + util.radius * 2 * util.point.x;
	util.point.y = util.point.y + util.radius * 2 * util.point.y;
	if (util.point.x + util.radius > W || util.point.y + util.radius > H
		|| util.point.x - util.radius < 0 || util.point.y - util.radius < 0)
		return ;
	square(util);
}
