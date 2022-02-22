/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:53:44 by mojo              #+#    #+#             */
/*   Updated: 2022/02/17 20:29:54 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*head;
	t_list	*elem;
	int		i;

	i = 0;
	head = 0;
	while (i < size)
	{
		elem = ft_create_elem(strs[i]);
		elem->next = head;
		head = elem;
		i++;
	}
	return (head);
}
