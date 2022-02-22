/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:47:31 by mojo              #+#    #+#             */
/*   Updated: 2022/02/17 15:48:20 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*elem;

	elem = begin_list;
	while (elem)
	{
		if (cmp(elem->data, data_ref) == 0)
			return (elem);
		elem = elem->next;
	}
	return (0);
}
