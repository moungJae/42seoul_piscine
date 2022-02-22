/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:08:45 by mojo              #+#    #+#             */
/*   Updated: 2022/02/07 11:09:33 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char		nb_table[15];
	int			i;
	long long	N;

	i = 0;
	N = (long long)nb;
	if (N < 0)
	{
		write(1, "-", 1);
		N = -N;
	}
	while (N >= 0)
	{
		nb_table[i++] = 48 + N % 10;
		N /= 10;
		if (N == 0)
			break ;
	}
	i -= 1;
	while (i >= 0)
		write(1, &nb_table[i--], 1);
}
