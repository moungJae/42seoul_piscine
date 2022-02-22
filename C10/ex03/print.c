/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:14:55 by mojo              #+#    #+#             */
/*   Updated: 2022/02/15 15:33:09 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	print_message(char *s)
{
	write(1, s, str_len(s));
}

void	error_message(char *exec_name, char *s)
{
	print_message(basename(exec_name));
	print_message(": ");
	print_message(s);
	print_message(": ");
	print_message(strerror(errno));
	print_message("\n");
}

void	bad_file(char *exec_name, char *s)
{
	print_message(basename(exec_name));
	print_message(": ");
	print_message(s);
	print_message(": ");
	print_message("Bad file descriptor\n");
}

void	print_remainder(t_info *t, unsigned int length)
{
	if (t->option)
	{
		if (length % 16 != 0)
			print_memory_o(t->cur, length - (length % 16), length % 16);
		if (length)
			print_address_o(length, 1);
	}
	else
	{
		if (length % 16 != 0)
			print_memory_x(t->cur, length - (length % 16), length % 16);
		if (length)
			print_address_x(length, 1);
	}
}
