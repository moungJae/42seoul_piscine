/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:59:38 by mojo              #+#    #+#             */
/*   Updated: 2022/02/19 12:47:32 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*elem;
	t_list	*tmp;

	elem = begin_list;
	while (elem)
	{
		tmp = elem;
		elem = elem->next;
		(*free_fct)(tmp->data);
		free(tmp);
	}
}
