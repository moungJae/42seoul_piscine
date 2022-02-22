/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:01:38 by mojo              #+#    #+#             */
/*   Updated: 2022/02/17 21:04:43 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*elem;

	i = 0;
	elem = begin_list;
	while (elem->next && i < nbr)
	{
		elem = elem->next;
		i++;
	}
	if (i == nbr)
		return (elem);
	return (0);
}
