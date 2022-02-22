/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:34:08 by mojo              #+#    #+#             */
/*   Updated: 2022/02/07 18:29:20 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isSqrt(int nb)
{
	long long	x;
	long long	N;

	N = (long long)nb;
	x = 0;
	while (1)
	{
		if (x * x == N)
			return ((int)x);
		if (x * x > N)
			return ((int)x - 1);
		x++;
	}
}

int	ft_is_prime(int nb)
{
	int	sqrt_nb;
	int	x;

	if (nb <= 1)
		return (0);
	sqrt_nb = isSqrt(nb);
	x = 2;
	while (x <= sqrt_nb)
	{
		if (nb % x == 0)
			return (0);
		x++;
	}
	return (1);
}
