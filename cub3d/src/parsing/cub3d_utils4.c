/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:09:39 by eassofi           #+#    #+#             */
/*   Updated: 2022/09/27 04:57:10 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_extension_map(char *av, char *ext)
{
	char	**matrix;

	matrix = ft_split(av, '.');
	if (matrix[1] && ft_strncmp(matrix[1], ext, ft_strlen(ext)))
	{
		free_char_matrix(matrix);
		return (1);
	}
	free_char_matrix(matrix);
	return (0);
}

void	copy(char *s1, char *s2, int nb)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != '\n')
		{
			s2[nb] = s1[i];
			nb++;
		}
		i++;
	}
	s2[nb] = '\0';
}

char	*copy_path(char *s1)
{
	char	*s2;
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != '\n')
			nb++;
		i++;
	}
	i = 0;
	s2 = (char *)malloc(sizeof(char) * nb + 1);
	nb = 0;
	copy(s1, s2, nb);
	return (s2);
}

void	count_elmt(t_mlx *mlx, char *str)
{
	if (!ft_strncmp(str, "NO", ft_strlen("NO")))
		mlx->nb_elemt[0]++;
	if (!ft_strncmp(str, "SO", ft_strlen("NO")))
		mlx->nb_elemt[1]++;
	if (!ft_strncmp(str, "WE", ft_strlen("NO")))
		mlx->nb_elemt[2]++;
	if (!ft_strncmp(str, "EA", ft_strlen("NO")))
		mlx->nb_elemt[3]++;
	if (str[0] == 'F' && ft_isspace(str[1]))
		mlx->nb_elemt[4]++;
	if (str[0] == 'C' && ft_isspace(str[1]))
		mlx->nb_elemt[5]++;
}

int	compare_element(char *str)
{
	if (!ft_strncmp(str, "NO", ft_strlen("NO"))
		|| !ft_strncmp(str, "SO", ft_strlen("SO"))
		|| !ft_strncmp(str, "WE", ft_strlen("WE"))
		|| !ft_strncmp(str, "EA", ft_strlen("EA"))
		|| (str[0] == 'F' && ft_isspace(str[1]))
		|| (str[0] == 'C' && ft_isspace(str[1])))
		return (1);
	return (0);
}
