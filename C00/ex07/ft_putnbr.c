/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:38:32 by mojo              #+#    #+#             */
/*   Updated: 2022/02/20 16:28:38 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	go(char number[20], int idx)
{
	int	i;

	i = idx;
	while (i >= 0)
	{
		write(1, &number[i--], 1);
	}
}

void	ft_putnbr(int nb)
{
	int			i;
	char		number[20];
	char		minus;
	long long	nb_long;

	nb_long = (long long)nb;
	i = 0;
	minus = '-';
	if (nb_long < 0)
	{
		write(1, &minus, 1);
		nb_long = -nb_long;
	}
	if (nb_long == 0)
	{
		number[i++] = '0';
	}
	while (nb_long)
	{
		number[i++] = '0' + nb_long % 10;
		nb_long /= 10;
	}
	go(number, i - 1);
}
