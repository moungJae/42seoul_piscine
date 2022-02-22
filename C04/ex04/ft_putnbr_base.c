/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:09:05 by mojo              #+#    #+#             */
/*   Updated: 2022/02/07 11:10:21 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(char *check, char c, int cnt)
{
	int	i;

	if (c == '+' || c == '-')
		return (0);
	i = 0;
	while (i < cnt)
	{
		if (check[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	go_putnbr_base(long long nbr, char *base, long long cnt)
{
	int		i;
	char	result[40];

	i = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	while (nbr >= 0)
	{
		result[i++] = base[nbr % cnt];
		nbr /= cnt;
		if (nbr == 0)
			break ;
	}
	i -= 1;
	while (i >= 0)
		write(1, &result[i--], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	cnt;

	cnt = 0;
	while (base[cnt] != '\0')
	{
		if (!is_valid(base, base[cnt], cnt))
			return ;
		cnt++;
	}
	if (cnt <= 1)
		return ;
	go_putnbr_base(nbr, base, cnt);
}
