/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:34:30 by mojo              #+#    #+#             */
/*   Updated: 2022/02/07 18:25:52 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	go_ten_queens_puzzle(char result[], int step);

int	base_case(char result[])
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < 10)
	{
		result[0] = 48 + i;
		ret += go_ten_queens_puzzle(result, 1);
		i++;
	}
	return (ret);
}

int	is_here(char result[], int step, char pos)
{
	int	i;

	i = 0;
	while (i < step)
	{
		if (result[i] + (step - i) == pos)
			return (0);
		if (result[i] - (step - i) == pos)
			return (0);
		if (result[i] == pos)
			return (0);
		i++;
	}
	return (1);
}

int	backtracking(char result[], int step)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < 10)
	{
		if (!is_here(result, step, 48 + i))
		{
			i++;
			continue ;
		}
		result[step] = 48 + i;
		ret += go_ten_queens_puzzle(result, step + 1);
		i++;
	}
	return (ret);
}

int	go_ten_queens_puzzle(char result[], int step)
{
	int	i;
	int	ret;

	if (step == 10)
	{
		write(1, result, 11);
		return (1);
	}
	i = 0;
	ret = 0;
	if (step == 0)
		ret += base_case(result);
	else
		ret += backtracking(result, step);
	return (ret);
}

int	ft_ten_queens_puzzle(void)
{
	char	result[11];

	result[10] = '\n';
	return (go_ten_queens_puzzle(result, 0));
}
