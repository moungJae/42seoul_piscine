/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:16:35 by mojo              #+#    #+#             */
/*   Updated: 2022/02/05 17:28:01 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	make_tmp(unsigned char hex[], unsigned char tmp)
{
	if ((int)tmp / 16 >= 10)
		hex[0] = 97 + (int)tmp / 16 - 10;
	else
		hex[0] = 48 + (int)tmp / 16;
	if ((int)tmp % 16 >= 10)
		hex[1] = 97 + (int)tmp % 16 - 10;
	else
		hex[1] = 48 + (int)tmp % 16;
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	hex[2];
	unsigned char	tmp;
	char			backslash;

	i = 0;
	backslash = '\\';
	while (str[i] != '\0')
	{
		if (str[i] >= ' ' && str[i] <= '~')
			write(1, &str[i], 1);
		else
		{
			write(1, &backslash, 1);
			tmp = str[i];
			make_tmp(hex, tmp);
			write(1, hex, 2);
		}
		i++;
	}
}
