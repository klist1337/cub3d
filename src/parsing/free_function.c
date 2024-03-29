/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:16:07 by eassofi           #+#    #+#             */
/*   Updated: 2023/01/18 02:30:08 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	global_free(t_mlx *mlx)
{
	free(mlx->nb_elemt);
	free_char_matrix(mlx->path);
	free_char_matrix(mlx->cardinal);
	free(mlx->celling);
	free(mlx->floor);
}
