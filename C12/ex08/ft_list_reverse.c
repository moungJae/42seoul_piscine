/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:03:08 by mojo              #+#    #+#             */
/*   Updated: 2022/02/17 15:14:06 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*cur;

	if (!(*begin_list) || !(*begin_list)->next)
		return ;
	prev = *begin_list;
	cur = prev->next;
	prev->next = 0;
	while (cur->next)
	{
		tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
	cur->next = prev;
	*begin_list = cur;
}
