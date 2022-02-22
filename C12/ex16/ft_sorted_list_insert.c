/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:46:29 by mojo              #+#    #+#             */
/*   Updated: 2022/02/21 13:42:27 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*cur;
	t_list	*before;

	if (!(*begin_list))
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	if ((*cmp)(data, (*begin_list)->data) <= 0)
	{
		cur = *begin_list;
		*begin_list = ft_create_elem(data);
		(*begin_list)->next = cur;
		return ;
	}
	before = *begin_list;
	cur = before->next;
	while (cur && (*cmp)(data, cur->data) > 0)
	{
		before = cur;
		cur = cur->next;
	}
	before->next = ft_create_elem(data);
	before->next->next = cur;
}
