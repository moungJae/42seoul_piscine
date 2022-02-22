/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:09:01 by mojo              #+#    #+#             */
/*   Updated: 2022/02/19 14:11:49 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	get_tree_size(t_btree *root)
{
	int	ret;

	ret = 0;
	if (root)
	{
		ret = 1 + get_tree_size(root->left) + get_tree_size(root->right);
	}
	return (ret);
}

void	construct_level(t_btree *root, t_info *t, int *idx, int level)
{
	if (root)
	{
		t[(*idx)].item = root->item;
		t[(*idx)].level = level;
		t[(*idx)].index = (*idx);
		*idx += 1;
		construct_level(root->left, t, idx, level + 1);
		construct_level(root->right, t, idx, level + 1);
	}
}

void	make_max_heap(t_info *t, int cur, int fin)
{
	t_info	tmp;
	int		child;

	child = 2 * cur + 1;
	while (child <= fin)
	{
		if (child + 1 <= fin)
		{
			if ((t[child].level < t[child + 1].level) || \
				((t[child].level == t[child + 1].level) && \
				(t[child].index < t[child + 1].index)))
				child++;
		}
		if ((t[cur].level > t[child].level) || \
			((t[cur].level == t[child].level) && \
			(t[cur].index > t[child].index)))
			break ;
		tmp = t[cur];
		t[cur] = t[child];
		t[child] = tmp;
		cur = child;
		child = 2 * cur + 1;
	}
}

void	sort_by_level(t_info *t, int size)
{
	t_info	tmp;
	int		i;

	i = size / 2;
	while (i >= 0)
		make_max_heap(t, i--, size - 1);
	i = size - 1;
	while (i > 0)
	{
		tmp = t[0];
		t[0] = t[i];
		t[i] = tmp;
		make_max_heap(t, 0, --i);
	}
}

void	btree_apply_by_level(t_btree *root, \
		void (*applyf)(void *item, int current_level, \
			int is_first_elem))
{
	t_info	*t;
	int		*idx;
	int		i;
	int		tree_size;

	tree_size = get_tree_size(root);
	t = (t_info *)malloc(sizeof(t_info) * tree_size);
	i = 0;
	idx = &i;
	construct_level(root, t, idx, 0);
	sort_by_level(t, get_tree_size(root));
	i = 0;
	(*applyf)(t[0].item, t[0].level, 1);
	while (++i < tree_size)
	{
		if (t[i - 1].level != t[i].level)
			(*applyf)(t[i].item, t[i].level, 1);
		else
			(*applyf)(t[i].item, t[i].level, 0);
	}
	free(t);
}
