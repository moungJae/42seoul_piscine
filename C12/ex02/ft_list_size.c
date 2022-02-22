/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:49:20 by mojo              #+#    #+#             */
/*   Updated: 2022/02/17 20:18:24 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		ret;
	t_list	*elem;

	ret = 0;
	elem = begin_list;
	while (elem)
	{
		elem = elem->next;
		ret++;
	}
	return (ret);
}
