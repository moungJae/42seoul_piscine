/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:09:15 by mojo              #+#    #+#             */
/*   Updated: 2022/02/21 19:09:42 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(char *base, char c, int cnt)
{
	int	i;

	if (c == '+' || c == '-')
		return (0);
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (0);
	i = 0;
	while (i < cnt)
	{
		if (base[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	is_base(char c, char *base, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	go_atoi_base(char *str, char *base, int cnt)
{
	int	i;
	int	minus;
	int	result;

	i = 0;
	while (is_space(str[i]))
		i++;
	minus = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			minus++;
	}
	result = 0;
	while (is_base(str[i], base, cnt) != -1)
		result = cnt * result + is_base(str[i++], base, cnt);
	if (minus % 2 == 1)
		result = (-1) * result;
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int		cnt;

	cnt = 0;
	while (base[cnt] != '\0')
	{
		if (!check(base, base[cnt], cnt))
			return (0);
		cnt++;
	}
	if (cnt <= 1)
		return (0);
	return (go_atoi_base(str, base, cnt));
}
