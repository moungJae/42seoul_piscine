/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:05:27 by mojo              #+#    #+#             */
/*   Updated: 2022/02/19 14:06:28 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, \
		int (*cmpf)(void *, void *))
{
	void	*ret;

	ret = 0;
	if (root)
	{
		if ((*cmpf)(root->item, data_ref) == 0)
			return (root->item);
		ret = btree_search_item(root->left, data_ref, cmpf);
		if (ret)
			return (ret);
		ret = btree_search_item(root->right, data_ref, cmpf);
		if (ret)
			return (ret);
	}
	return (0);
}
