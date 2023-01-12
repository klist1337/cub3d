/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 01:04:32 by eassofi           #+#    #+#             */
/*   Updated: 2022/09/27 05:32:05 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_strchr2(char *s, int c);
char	*ft_strjoin2(char *s1, char *s2);
size_t	ft_strlen2(char *str);
#endif
