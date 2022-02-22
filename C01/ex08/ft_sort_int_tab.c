/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:44:20 by mojo              #+#    #+#             */
/*   Updated: 2022/02/03 10:43:39 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	make_heap(int *tab, int cur, int size)
{
	int	child;

	child = 2 * cur + 1;
	while (child <= size)
	{
		if ((child < size) && (*(tab + child) < *(tab + child + 1)))
			child++;
		if (*(tab + cur) > *(tab + child))
			child = size + 1;
		else
		{
			ft_swap(tab + cur, tab + child);
			cur = child;
			child = 2 * cur + 1;
		}
	}
}

void	heap_sort(int *tab, int size)
{
	int	i;

	i = size / 2;
	while (i >= 0)
		make_heap(tab, i--, size - 1);
	i = size - 1;
	while (i > 0)
	{
		ft_swap(tab, tab + i);
		make_heap(tab, 0, --i);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	heap_sort(tab, size);
}
