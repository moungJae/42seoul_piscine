/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:34:16 by mojo              #+#    #+#             */
/*   Updated: 2022/02/07 18:27:36 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_sqrt(int nb)
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

int	is_prime(int nb)
{
	int	sqrt_nb;
	int	x;

	if (nb <= 1)
		return (0);
	sqrt_nb = is_sqrt(nb);
	x = 2;
	while (x <= sqrt_nb)
	{
		if (nb % x == 0)
			return (0);
		x++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	x;

	if (is_prime(nb))
		return (nb);
	x = nb + 1;
	while (1)
	{
		if (is_prime(x))
			return (x);
		x++;
	}
}
