/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:08:23 by mojo              #+#    #+#             */
/*   Updated: 2022/02/21 13:46:45 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*small(void *data, t_list *cur, int (*cmp)())
{
	t_list	*ret;

	ret = cur;
	while (cur)
	{
		if ((*cmp)(data, cur->data) > 0)
		{
			data = cur->data;
			ret = cur;
		}
		cur = cur->next;
	}
	return (ret);
}

void	sort_list(t_list **begin_list, int (*cmp)())
{
	t_list	*cur;
	t_list	*s;
	void	*tmp;

	if (!(*begin_list) || !(*begin_list)->next)
		return ;
	cur = *begin_list;
	while (cur->next)
	{
		s = small(cur->data, cur, cmp);
		if (cur != s)
		{
			tmp = cur->data;
			cur->data = s->data;
			s->data = tmp;
		}
		cur = cur->next;
	}
}

void	merge_list(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*elem;

	if (!(*begin_list1))
	{
		*begin_list1 = begin_list2;
		return ;
	}
	elem = *begin_list1;
	while (elem->next)
		elem = elem->next;
	elem->next = begin_list2;
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, \
		int (*cmp)())
{
	sort_list(begin_list1, cmp);
	sort_list(&begin_list2, cmp);
	merge_list(begin_list1, begin_list2);
	sort_list(begin_list1, cmp);
}
