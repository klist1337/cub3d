/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:30:21 by eassofi           #+#    #+#             */
/*   Updated: 2022/11/12 01:28:56 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	map_element(char **line, int fd)
{
	*line = get_next_line(fd);
	while (*line && ft_strlen(*line) == 1)
		skip_line_space(line, fd);
	if (*line == NULL || !compare_element(*line))
	{
		print_error ("Error : Invalid Map\n");
		return (0);
	}
	return (1);
}

int	get_map_elmt(t_mlx *mlx, int fd, char **line)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < 6)
	{
		if (!map_element(line, fd))
			return (0);
		count_elmt(mlx, *line);
		if (!get_texture(mlx, *line, &j))
			return (0);
		if (!get_rgb(mlx, *line))
			return (0);
		free(*line);
		mlx->path[j] = 0;
	}
	if (!check_nb_elmt(mlx))
	{
		print_error("Error : Invalid map\n");
		return (0);
	}
	return (1);
}

void	fill(t_mlx *mlx, char *line, int fd)
{
	int		x;
	int		j;
	int		i;

	i = -1;
	while (line && ++i < mlx->height)
	{
		j = -1;
		x = 0;
		while (++j < mlx->width_tab[i] && line[x])
		{
			while (line[x] && ft_isspace(line[x]))
				x++;
			mlx->map_entry[i][j] = line[x] - '0';
			x++;
		}
		free(line);
		line = get_next_line(fd);
	}
}

void	fill_map(t_mlx *mlx, char **av)
{
	int		i;
	char	*line;
	int		fd;

	i = -1;
	fd = open(av[1], O_RDONLY, 0777);
	mlx->map_entry = (int **) malloc(sizeof(int *) * mlx->height);
	while (++i < mlx->height)
	{
		mlx->map_entry[i] = (int *) malloc(sizeof(int) * mlx->width_tab[i]);
		if (!mlx->map_entry[i])
			exit(0);
	}
	i = -1;
	while (++i < 6)
	{
		line = get_next_line(fd);
		while (ft_strlen(line) == 1)
			skip_line_space(&line, fd);
		free(line);
	}
	line = get_next_line(fd);
	while (ft_strlen(line) == 1)
		skip_line_space(&line, fd);
	fill(mlx, line, fd);
}

void	first_map(t_mlx *mlx, char **av)
{
	int		fd;
	int		i;
	char	*line;

	i = -1;
	fd = open(av[1], O_RDONLY, 0777);
	mlx->width_tab = (int *)malloc(sizeof(int) * mlx->height);
	if (!mlx->width_tab)
		exit(1);
	skip_six_line(&line, fd);
	line = get_next_line(fd);
	while (ft_strlen(line) == 1)
		skip_line_space(&line, fd);
	i = -1;
	while (line && ++i < mlx->height)
	{
		mlx->width_tab[i] = ft_len(line);
		free(line);
		line = get_next_line(fd);
		while (line && ft_strlen(line) == 1)
			skip_line_space(&line, fd);
	}
	fill_map(mlx, av);
}
