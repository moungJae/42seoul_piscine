/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:44:12 by mojo              #+#    #+#             */
/*   Updated: 2022/02/14 18:55:33 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_address_x(unsigned int address, int fin)
{
	int				i;
	unsigned char	c;
	unsigned char	temp[7];

	i = 0;
	while (i < 7)
	{
		if (address % 16 < 10)
			c = 48 + (address % 16);
		else
			c = 97 + (address % 16 - 10);
		address /= 16;
		temp[i++] = c;
	}
	i -= 1;
	while (i >= 0)
		write(1, &temp[i--], 1);
	if (fin)
		write(1, "\n", 1);
	else
		write(1, " ", 1);
}

void	print_hex_x(char *s, int size)
{
	int				i;
	int				c;
	unsigned char	*tmp;
	unsigned char	hex[2];

	i = 0;
	tmp = (unsigned char *)s;
	while (i < size)
	{
		c = (int) *(tmp + i);
		if (c % 16 < 10)
			hex[1] = 48 + (c % 16);
		else
			hex[1] = 97 + (c % 16 - 10);
		c /= 16;
		if (c % 16 < 10)
			hex[0] = 48 + (c % 16);
		else
			hex[0] = 97 + (c % 16 - 10);
		write(1, hex, 2);
		i++;
		if (i < 16)
			write(1, " ", 1);
	}
}

void	print_blank_x(int idx)
{
	int	i;

	i = idx;
	while (i < 16)
	{
		write(1, "  ", 2);
		i++;
		if (i < 16)
			write(1, " ", 1);
	}
}

void	print_memory_x(char *s, unsigned int size, int how)
{
	print_address_x(size, 0);
	if (how != 16)
	{
		print_hex_x(s, how);
		print_blank_x(how);
	}
	else
	{
		print_hex_x(s, 16);
	}
	write(1, "\n", 1);
}
