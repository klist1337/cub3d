/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 05:13:19 by eassofi           #+#    #+#             */
/*   Updated: 2022/09/27 04:57:10 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	remplace_by_one(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (ft_isspace(line[i]))
		{
			line[i] = '1';
			i++;
		}
		i++;
	}
}

char	*fill_space_by_one(char *line, t_mlx *mlx)
{
	int		i;
	char	*new;

	remplace_by_one(line);
	new = (char *)malloc(sizeof(char) * mlx->width);
	if (!new)
		return (NULL);
	i = -1;
	while (line[++i])
		new[i] = line[i];
	i--;
	while (++i < mlx->width - 1)
		new[i] = '1';
	new[mlx->width] = '\0';
	return (new);
}

void	free_texture(t_mlx *mlx)
{
	int		i;

	i = -1;
	while (++i < 8)
		free(mlx->texture[i]);
	free(mlx->texture);
}

void	init_raycasting_param(t_mlx *mlx)
{
	mlx->height = 0;
	mlx->cub.y = 0;
	mlx->y = 0;
	mlx->cub.height = 0;
	mlx->start_x = 0;
	mlx->start_y = 0;
	mlx->cub.dir_x = 1;  //-1 - 1
	mlx->cub.dir_y = 0; // always 0
	mlx->cub.plane_x = 0; // always 0;
	mlx->cub.plane_y = 0.66; // -0.66 --- 0.66
}

void	init_param_mlx(t_mlx *mlx)
{
	int	i;

	i = -1;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, W,
			H, "cub3d");
	init_raycasting_param(mlx);
	mlx->re_buff = 0;
	mlx->flag = 0;
	mlx->error = 0;
	mlx->nb_player = 0;
	mlx->celling = 0;
	mlx->floor = 0;
	mlx->path = (char **)malloc(sizeof(char *) * 5);
	mlx->nb_elemt = (int *)malloc(sizeof(int) * 6);
	if (!mlx->path || !mlx->nb_elemt)
		return ;
	while (++i < 6)
		mlx->nb_elemt[i] = 0;
}
