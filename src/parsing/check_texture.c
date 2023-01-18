/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 01:34:05 by eassofi           #+#    #+#             */
/*   Updated: 2023/01/18 18:56:31 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
