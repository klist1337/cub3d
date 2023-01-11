/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:00:23 by eassofi           #+#    #+#             */
/*   Updated: 2021/11/18 15:00:30 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst;

	if (!alst || !new)
		return ;
	if (!*alst)
	{
		*alst = new;
	}
	else
	{
		lst = ft_lstlast(*alst);
		lst -> next = new;
	}
}
