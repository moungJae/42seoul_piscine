/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:38 by mojo              #+#    #+#             */
/*   Updated: 2022/02/15 15:20:37 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_result(char *s, int idx, int op, int cnt)
{
	int	start;

	if (op)
	{
		start = idx;
		write(1, &s[start++], 1);
		start = start % cnt;
		while (start != idx)
		{
			write(1, &s[start++], 1);
			start = start % cnt;
		}
	}
	else
	{
		start = 0;
		while (start < idx)
			write(1, &s[start++], 1);
	}
}

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

void	error_message(char *file, char *exec_name)
{
	print_message(basename(exec_name));
	print_message(": ");
	print_message(file);
	print_message(": ");
	print_message(strerror(errno));
	print_message("\n");
}
