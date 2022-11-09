/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:47:08 by eassofi           #+#    #+#             */
/*   Updated: 2022/09/27 04:57:10 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	join_texture(char **matrix, int *flag, char **path)
{
	char	*tmp;
	int		i;

	i = 2;
	while (matrix[i])
	{
		tmp = matrix[1];
		matrix[1] = ft_strjoin(matrix[1], matrix[i]);
		free(tmp);
		i++;
	}
	*path = copy_path(matrix[1]);
	*flag = 1;
}

int	get_tex(char *str, char **path, int *flag)
{
	char	**matrix;
	int		nb;

	nb = 0;
	matrix = NULL;
	if ((str[0] == 'N' && str[1] == 'O') || (str[0] == 'S' && str[1] == 'O')
		|| (str[0] == 'W' && str[1] == 'E') || (str[0] == 'E' && str[1] == 'A'))
	{
		matrix = ft_split(str, ' ');
		nb = get_nb_of_split(matrix);
		if (nb == 1 || (matrix[1] && ft_strlen(matrix[1]) == 1))
		{
			print_error("Error : bad texture\n");
			return (0);
		}
		else if (nb == 2 && ft_strlen(matrix[1]) > 1)
		{
			*path = copy_path(matrix[1]);
			*flag = 1;
		}
		else if (nb > 2)
			join_texture(matrix, flag, path);
		free_char_matrix(matrix);
	}
	return (1);
}

int	get_texture(t_mlx *mlx, char *line, int *j)
{
	int		flag;
	char	*s;

	flag = 0;
	s = NULL;
	if (get_tex(line, &s, &flag))
	{
		if (flag == 1)
		{
			mlx->path[*j] = ft_strdup(s);
			*j = *j + 1;
			free(s);
		}
	}
	else
		return (0);
	return (1);
}

int	isvalid_texture(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY, 0777);
	if (fd < 0)
	{	
		print_error("Error: Texture file don't exist\n");
		return (0);
	}
	if (check_extension_map(path, "xpm"))
	{
		print_error("Error : wrong extension file (xpm)\n");
		return (0);
	}
	close (fd);
	return (1);
}

int	check_texture(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
	{
		if (!isvalid_texture(path[i]))
			return (1);
	}
	return (0);
}
