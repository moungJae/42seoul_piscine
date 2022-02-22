/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:57:31 by mojo              #+#    #+#             */
/*   Updated: 2022/02/19 13:58:26 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*ret;

	ret = (t_btree *)malloc(sizeof(t_btree));
	ret->left = 0;
	ret->right = 0;
	ret->item = item;
	return (ret);
}
