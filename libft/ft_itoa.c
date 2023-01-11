/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:22:51 by eassofi           #+#    #+#             */
/*   Updated: 2021/11/16 22:05:46 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	absolute_value(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

static int	get_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		++len;
	while (nb)
	{
		++len;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = get_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	if (n < 0)
		res[0] = '-';
	else if (n == 0)
		res[0] = '0';
	res[len] = '\0';
	while (n)
	{
		--len;
		res[len] = absolute_value(n % 10) + '0';
		n = n / 10;
	}
	return (res);
}
