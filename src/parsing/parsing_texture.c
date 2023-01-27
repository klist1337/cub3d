/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:47:08 by eassofi           #+#    #+#             */
/*   Updated: 2023/01/27 21:57:46 by eassofi          ###   ########.fr       */
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

int	get_path(t_var *var, char *str, char **path, char **cardinal)
{
	if ((str[0] == 'N' && str[1] == 'O') || (str[0] == 'S' && str[1] == 'O')
		|| (str[0] == 'W' && str[1] == 'E') || (str[0] == 'E' && str[1] == 'A'))
	{
		var->matrix = ft_split(str, ' ');
		var->nb = get_nb_of_split(var->matrix);
		if (var->nb == 1 || var->nb > 2
			|| (var->matrix[1] && ft_strlen(var->matrix[1]) == 1)
			|| ft_strlen(var->matrix[0]) != 2)
		{
			print_error("Error : bad texture\n");
			return (0);
		}
		else if (var->nb == 2 && ft_strlen(var->matrix[1]) > 1)
		{
			*path = copy_path(var->matrix[1]);
			cardinal[0] = strdup(var->matrix[0]);
			var->flag = 1;
		}
		else if (var->nb > 2)
			join_texture(var->matrix, &var->flag, path);
		free_char_matrix(var->matrix);
	}
	return (1);
}

int	get_tex(char *str, char **path, int *flag, char **cardinal)
{
	t_var	var;

	var.nb = 0;
	var.matrix = NULL;
	var.flag = 0;
	if (!get_path(&var, str, path, cardinal))
		return (0);
	*flag = var.flag;
	return (1);
}

int	get_texture(t_mlx *mlx, char *line, int *j)
{
	int		flag;
	char	*s;
	char	*cardinal;

	flag = 0;
	s = NULL;
	cardinal = NULL;
	if (get_tex(line, &s, &flag, &cardinal))
	{
		if (flag == 1)
		{
			mlx->path[*j] = ft_strdup(s);
			mlx->cardinal[*j] = ft_strdup(cardinal);
			*j = *j + 1;
			free(s);
			free(cardinal);
		}
	}
	else
		return (0);
	return (1);
}
