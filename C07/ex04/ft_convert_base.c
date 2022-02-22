/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:25:23 by mojo              #+#    #+#             */
/*   Updated: 2022/02/21 19:30:26 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check(char *base, char c, int cnt);
int	is_space(char c);
int	is_base(char c, char *base, int cnt);
int	go_atoi_base(char *str, char *base, int cnt);
int	ft_atoi_base(char *str, char *base);

char	g_tmp[100];

int	is_valid(char c, char *base, int cnt)
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

int	get_length(long long convert_num, int cnt)
{
	int	len;

	len = 0;
	if (convert_num < 0)
	{
		len = 1;
		convert_num = -convert_num;
	}
	while (convert_num >= 0)
	{
		len++;
		convert_num /= cnt;
		if (convert_num == 0)
			break ;
	}
	return (len);
}

char	*go_convert_base(long long convert_num, char *base_to, long long cnt)
{
	int		i;
	int		j;
	int		len;
	char	*ret;

	len = get_length(convert_num, cnt);
	ret = (char *)malloc(len + 1);
	j = 0;
	if (convert_num < 0)
	{
		ret[j++] = '-';
		convert_num = -convert_num;
	}
	i = 0;
	while (convert_num >= 0)
	{
		g_tmp[i++] = base_to[convert_num % cnt];
		convert_num /= cnt;
		if (convert_num == 0)
			break ;
	}
	while (j < len)
		ret[j++] = g_tmp[--i];
	ret[j] = '\0';
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	cnt;
	int	convert_num;

	cnt = 0;
	while (base_from[cnt] != '\0')
	{
		if (!is_valid(base_from[cnt], base_from, cnt))
			return (0);
		cnt++;
	}
	if (cnt <= 1)
		return (0);
	cnt = 0;
	while (base_to[cnt] != '\0')
	{
		if (!is_valid(base_to[cnt], base_to, cnt))
			return (0);
		cnt++;
	}
	if (cnt <= 1)
		return (0);
	convert_num = ft_atoi_base(nbr, base_from);
	return (go_convert_base(convert_num, base_to, cnt));
}
