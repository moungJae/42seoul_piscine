/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:13:37 by mojo              #+#    #+#             */
/*   Updated: 2022/02/19 17:38:28 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*get_small(void *data, t_list *cur, int (*cmp)())
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

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*cur;
	t_list	*small;
	void	*tmp;

	if (!(*begin_list) || !(*begin_list)->next)
		return ;
	cur = *begin_list;
	while (cur->next)
	{
		small = get_small(cur->data, cur, cmp);
		if (cur != small)
		{
			tmp = cur->data;
			cur->data = small->data;
			small->data = tmp;
		}
		cur = cur->next;
	}
}
