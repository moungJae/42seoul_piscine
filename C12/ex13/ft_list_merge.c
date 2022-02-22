/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:03:35 by mojo              #+#    #+#             */
/*   Updated: 2022/02/19 17:28:34 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
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
