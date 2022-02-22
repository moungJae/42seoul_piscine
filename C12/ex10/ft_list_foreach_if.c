/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:44:31 by mojo              #+#    #+#             */
/*   Updated: 2022/02/19 08:32:11 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), \
		void *data_ref, int (*cmp)())
{
	t_list	*elem;

	elem = begin_list;
	while (elem)
	{
		if (cmp(elem->data, data_ref) == 0)
			f(elem->data);
		elem = elem->next;
	}
}
