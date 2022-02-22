/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:38:34 by mojo              #+#    #+#             */
/*   Updated: 2022/02/03 10:39:28 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	low;
	int	high;
	int	tmp;

	low = 0;
	high = size - 1;
	while (high >= size / 2)
	{
		tmp = *(tab + low);
		*(tab + low) = *(tab + high);
		*(tab + high) = tmp;
		low++;
		high--;
	}
}
