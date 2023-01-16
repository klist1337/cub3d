/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:16:07 by eassofi           #+#    #+#             */
/*   Updated: 2022/09/27 04:57:10 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	global_free(t_mlx *mlx)
{
	free(mlx->nb_elemt);
	free_char_matrix(mlx->path);
	free(mlx->celling);
	free(mlx->floor);
}
