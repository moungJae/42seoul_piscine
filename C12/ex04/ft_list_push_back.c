/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:51:45 by mojo              #+#    #+#             */
/*   Updated: 2022/02/17 14:53:30 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;

	if (!(*begin_list))
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	elem = *begin_list;
	while (elem->next)
		elem = elem->next;
	elem->next = ft_create_elem(data);
}
