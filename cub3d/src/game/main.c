/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:26:15 by eassofi           #+#    #+#             */
/*   Updated: 2022/09/27 04:57:10 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


int matrix_and_raycasting(t_mlx *mlx, char **av)
{
	if (fill_matrix(mlx, av) || mlx->start_pos == '\0')
	{
		print_error ("Error : invalid map\n");
		return (0);
	}
	if (check_map(mlx, av))
	{
		print_error("Error : Invalid map\n");
		return (0);
	}
	if (convert_colorrgb(mlx->floor, &mlx->floor_color)
		|| convert_colorrgb(mlx->celling, &mlx->celling_color))
		return (0);
	free_int_matrix(mlx, mlx->map_entry);
	player(mlx);
	raycasting(mlx);
	global_free(mlx);
	free_int_matrix(mlx, mlx->matrix);
	free_int_matrix(mlx, mlx->map_entry);
	return (1);
}

int cub3d(t_mlx *mlx, char **av, char *line, int fd)
{
	if (!empty_map_or_directory(av))
		return (0);
	fd = open(av[1], O_RDONLY, 0777);
	if (!check_file_and_extension(av, fd))
		return (0);
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	init_param_mlx(mlx);
	if (!get_map_elmt(mlx, fd, &line))
		return (0);
	if (check_texture(mlx->path))
		return (0);
	line = get_next_line(fd);
	while (line && ft_strlen(line) == 1)
		skip_line_space(&line, fd);
	if (!line)
	{
		print_error("Error : Invalid map\n");
		return (0);
	}
	get_height(mlx, line, fd);
	if (!matrix_and_raycasting(mlx, av))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	t_mlx	*mlx;
	char	*line;

	line = NULL;
	mlx = NULL;
	fd = 0;
	if (ac - 1 == 1)
	{
		if (!cub3d(mlx, av, line, fd))
			return (1);
	}
	else
		print_error("Wrong argument\n");
}
