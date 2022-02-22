/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:18:06 by mojo              #+#    #+#             */
/*   Updated: 2022/02/15 19:35:33 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	operation(t_info *t, unsigned int length)
{
	if (t->option)
	{
		if (ft_strcmp(t->cur, t->before))
		{
			print_memory_o(t->cur, length - 16, 16);
			t->star_op = 0;
		}
		else if (!(t->star_op++))
			write(1, "*\n", 2);
		ft_strcpy(t->before, t->cur);
	}
	else
	{
		if (ft_strcmp(t->cur, t->before))
		{
			print_memory_x(t->cur, length - 16, 16);
			t->star_op = 0;
		}
		else if (!(t->star_op++))
			write(1, "*\n", 2);
		ft_strcpy(t->before, t->cur);
	}
}

unsigned int	go_other(int fd, unsigned int length, t_info *t)
{
	int				i;
	unsigned int	len;
	unsigned int	t_len;
	unsigned int	ret;
	char			tmp[16];

	ret = length;
	while (1)
	{
		i = 0;
		len = read(fd, tmp, 16);
		t_len = len;
		ret += len;
		while (len--)
		{
			t->cur[i] = tmp[i];
			i++;
		}
		if (t_len != 16)
			return (ret);
		operation(t, ret);
	}
	return (ret);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (i < 16 && (s1[i] == s2[i]))
		i++;
	if (i == 16)
		return (0);
	return (1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
