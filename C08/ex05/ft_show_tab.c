/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:36:34 by mojo              #+#    #+#             */
/*   Updated: 2022/02/12 17:04:06 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		write(1, par[i].str, str_len(par[i].str));
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, str_len(par[i].copy));
		write(1, "\n", 1);
		i++;
	}
}
