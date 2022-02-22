/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:08:56 by mojo              #+#    #+#             */
/*   Updated: 2022/02/07 14:07:47 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
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
