/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:57:10 by mojo              #+#    #+#             */
/*   Updated: 2022/02/17 11:08:11 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	atoi(char *str)
{
	int	i;
	int	minus;
	int	result;

	i = 0;
	result = 0;
	while (is_isspace(str[i]))
		i++;
	minus = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = 10 * result;
		result = result + (str[i] - '0');
		i++;
	}
	if (minus % 2 == 1)
		result = (-1) * result;
	return (result);
}

void	putnbr(int nb)
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
	write(1, "\n", 1);
}

int	str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0'))
		i++;
	return ((int)s1[i] - (int)s2[i]);
}

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
