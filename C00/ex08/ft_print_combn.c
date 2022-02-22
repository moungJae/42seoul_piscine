/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:38:04 by mojo              #+#    #+#             */
/*   Updated: 2022/02/20 16:31:06 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_finish(int n, char result[])
{
	int	i;
	int	ret;

	i = n - 1;
	ret = 1;
	if (result[i] != '9')
	{
		ret = 0;
	}
	else
	{
		i--;
		while (i >= 0)
		{
			if ((result[i] + 1) != result[i + 1])
			{
				ret = 0;
			}
			i--;
		}
	}
	return (ret);
}

void	print_result(int n, char result[])
{
	result[n] = ',';
	result[n + 1] = ' ';
	if (n == 1)
	{
		if (result[0] == '9')
		{
			write(1, result, 1);
		}
		else
		{
			write(1, result, 3);
		}
	}
	else
	{
		if (is_finish(n, result))
		{
			write(1, result, n);
		}
		else
		{
			write(1, result, n + 2);
		}
	}
}

void	go(char cur, int cur_idx, int n, char result[])
{
	char	c;

	if (cur_idx == n)
	{
		print_result(n, result);
	}
	if (!(cur == '9' && cur_idx != n))
	{
		c = cur + 1;
		while (c <= '9')
		{
			result[cur_idx] = c;
			go(c, cur_idx + 1, n, result);
			c++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	result[12];
	char	c;

	c = '0';
	while (c <= '9')
	{
		result[0] = c;
		go(c, 1, n, result);
		c++;
	}
}
