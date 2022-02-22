/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:38:21 by mojo              #+#    #+#             */
/*   Updated: 2022/02/02 16:38:22 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int x, int y, int u, int v)
{
	char	result[7];

	result[0] = x;
	result[1] = y;
	result[2] = ' ';
	result[3] = u;
	result[4] = v;
	result[5] = ',';
	result[6] = ' ';
	if (x == 57 && y == 56 && u == 57 && v == 57)
	{
		write(1, result, 5);
	}
	else
	{
		write(1, result, 7);
	}
}

void	go(int x, int y)
{
	int	u;
	int	v;

	if (y == 57)
	{
		u = x + 1;
		v = 48;
	}
	else
	{
		u = x;
		v = y + 1;
	}
	while (u <= 57)
	{
		while (v <= 57)
		{
			print(x, y, u, v);
			v++;
		}
		u++;
		v = 48;
	}
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 48;
	while (x <= 57)
	{
		y = 48;
		while (y <= 57)
		{
			if (!(x == 57 && y == 57))
			{
				go(x, y);
			}
			y++;
		}
		x++;
	}
}
