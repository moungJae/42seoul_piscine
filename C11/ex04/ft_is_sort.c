/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:03:36 by mojo              #+#    #+#             */
/*   Updated: 2022/02/21 10:21:03 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	j;
	int	increasing;
	int	decreasing;
	int	expect;

	i = -1;
	increasing = 0;
	decreasing = 0;
	expect = ((length - 1) * length) / 2;
	while (++i < length - 1)
	{
		j = i;
		while (++j < length)
		{
			if ((*f)(tab[i], tab[j]) >= 0)
				decreasing++;
			if ((*f)(tab[i], tab[j]) <= 0)
				increasing++;
		}
	}
	if (expect == increasing || expect == decreasing)
		return (1);
	return (0);
}
