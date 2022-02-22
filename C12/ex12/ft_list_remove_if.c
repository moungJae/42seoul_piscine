/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:48:55 by mojo              #+#    #+#             */
/*   Updated: 2022/02/20 10:49:03 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	remove_operation(t_list *before, t_list *cur, \
		t_list **begin_list, void (*free_fct)(void *))
{
	if (before)
	{
		before->next = cur->next;
		(*free_fct)(cur->data);
		free(cur);
	}
	else
	{
		*begin_list = cur->next;
		(*free_fct)(cur->data);
		free(cur);
	}
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, \
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*before;
	t_list	*cur;
	t_list	*tmp;

	if (!(*begin_list))
		return ;
	before = 0;
	cur = *begin_list;
	while (cur)
	{
		if ((*cmp)(cur->data, data_ref) == 0)
		{
			tmp = cur->next;
			remove_operation(before, cur, begin_list, free_fct);
			cur = tmp;
		}
		else
		{
			before = cur;
			cur = cur->next;
		}
	}
}
