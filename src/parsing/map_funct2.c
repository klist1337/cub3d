/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funct2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:33:56 by eassofi           #+#    #+#             */
/*   Updated: 2022/09/27 04:57:10 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_map(t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < mlx->height)
	{
		x = -1;
		while (++x < mlx->width_tab[y])
		{
			printf("%d", mlx->map_entry[y][x]);
		}
		y++;
		printf("\n");
	}
}

int	check_map(t_mlx *mlx, char **av)
{
	int	x;
	int	y;

	first_map(mlx, av);
	y = 0;
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width_tab[y])
		{
			if ((x == 0 && mlx->map_entry[y][x] != 1)
				|| (y == 0 && mlx->map_entry[y][x] != 1)
				|| (y == mlx->height - 1 && mlx->map_entry[y][x] != 1)
				|| (x == mlx->width_tab[y] - 1 && mlx->map_entry[y][x] != 1))
			{
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	empty_map_or_directory(char **av)
{
	char	*tmp;
	int		fd;

	fd = open(av[1], O_DIRECTORY, 0777);
	if (fd != -1)
	{
		print_error("Error: file is a directory\n");
		close(fd);
		return (0);
	}
	close(fd);
	fd = open(av[1], O_RDONLY, 0777);
	tmp = get_next_line(fd);
	if (fd >= 0 && tmp == NULL)
	{
		print_error("Error: empty map\n");
		free(tmp);
		return (0);
	}
	free(tmp);
	close(fd);
	return (1);
}

int	check_file_and_extension(char **av, int fd)
{
	if (fd < 0)
	{
		print_error("Error: file don't exist\n");
		return (0);
	}
	if (check_extension_map(av[1], "cub"))
	{
		print_error("Error: wrong extension file please test with .cub\n");
		return (0);
	}
	return (1);
}

void	get_height(t_mlx *mlx, char *line, int fd)
{
	while (line)
	{
		++mlx->height;
		free(line);
		line = get_next_line(fd);
		while (line && ft_strlen(line) == 1)
			skip_line_space(&line, fd);
	}
}
