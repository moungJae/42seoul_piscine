/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:07:25 by mojo              #+#    #+#             */
/*   Updated: 2022/02/19 14:08:10 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	tree_traversal(t_btree *root, int level)
{
	if (root)
	{
		return (max(tree_traversal(root->left, level + 1), \
					tree_traversal(root->right, level + 1)));
	}
	return (level);
}

int	btree_level_count(t_btree *root)
{
	return (tree_traversal(root, 0));
}
