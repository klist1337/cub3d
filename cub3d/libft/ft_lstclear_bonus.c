/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:09:37 by eassofi           #+#    #+#             */
/*   Updated: 2022/02/06 00:32:17 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*node;
	t_list	*tmp;

	if (!*lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		tmp = node;
		node = node->next;
		ft_lstdelone(tmp, del);
	}
	*lst = 0;
}
