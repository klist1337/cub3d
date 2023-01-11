/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:25:24 by eassofi           #+#    #+#             */
/*   Updated: 2023/01/11 18:12:48 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	skip_six_line(char **line, int fd)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		*line = get_next_line(fd);
		while (ft_strlen(*line) == 1)
			skip_line_space(line, fd);
		free(*line);
		i++;
	}
}

void	get_width(t_mlx *mlx, char **av)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY, 0777);
	skip_six_line(&line, fd);
	mlx->width = 0;
	line = get_next_line(fd);
	while (ft_strlen(line) == 1)
		skip_line_space(&line, fd);
	while (line)
	{
		mlx->width = maximum(mlx->width, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
	}
}

int	check_and_fill(t_mlx *mlx, char **line)
{
	char	*new;

	while (mlx->x < mlx->width - 1)
	{
		new = fill_space_by_one(*line, mlx);
		if (!ft_isdigit(new[mlx->x]) && (new[mlx->x] == 'N'
				|| new[mlx->x] == 'W' || new[mlx->x] == 'E'
				|| new[mlx->x] == 'S'))
		{
			mlx->nb_player++;
			mlx->start_x = mlx->x;
			mlx->start_y = mlx->y;
			mlx->start_pos = new[mlx->x];
			mlx->matrix[mlx->y][mlx->x] = 0;
		}
		else if (new[mlx->x] == '0' || new[mlx->x] == '1')
			mlx->matrix[mlx->y][mlx->x] = new[mlx->x] - '0';
		else
		{
			printf("new= %d", new[mlx->x]);
			return (1);
		}
		free(new);
		mlx->x++;
	}
	return (0);
}

int	fill_matrix2(t_mlx *mlx, char *line, int fd)
{
	char	*tmp;

	while (mlx->y < mlx->height)
	{
		mlx->x = 0;
		if (check_and_fill(mlx, &line))
			return (1);
		tmp = line;
		line = get_next_line(fd);
		free(tmp);
		mlx->y++;
	}
	return (0);
}

int	fill_matrix(t_mlx *mlx, char **av)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	get_width(mlx, av);
	mlx->matrix = (int **)malloc(sizeof(int *) * (mlx->height));
	fd = open(av[1], O_RDONLY, 0777);
	if (!mlx->matrix || fd < 0)
		exit(0);
	while (i < mlx->height)
	{
		mlx->matrix[i] = (int *) malloc(sizeof(int) * (mlx->width - 1));
		if (!mlx->matrix[i])
			exit(0);
		i++;
	}
	skip_six_line(&line, fd);
	line = get_next_line(fd);
	while (line && ft_strlen(line) == 1)
		skip_line_space(&line, fd);
	if (!line || fill_matrix2(mlx, line, fd) || mlx->nb_player > 1)
		return (1);
	return (0);
}
