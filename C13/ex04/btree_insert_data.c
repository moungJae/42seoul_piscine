/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:02:14 by mojo              #+#    #+#             */
/*   Updated: 2022/02/19 14:04:31 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	go_insert(t_btree *elem, void *item, \
		int (*cmpf)(void *, void *))
{
	if ((*cmpf)(item, elem->item) < 0)
	{
		if (elem->left)
			go_insert(elem->left, item, cmpf);
		else
			elem->left = btree_create_node(item);
	}
	else
	{
		if (elem->right)
			go_insert(elem->right, item, cmpf);
		else
			elem->right = btree_create_node(item);
	}
}

void	btree_insert_data(t_btree **root, void *item, \
		int (*cmpf)(void *, void *))
{
	if (!(*root))
		*root = btree_create_node(item);
	else
		go_insert(*root, item, cmpf);
}
