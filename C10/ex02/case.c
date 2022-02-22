/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:20:31 by mojo              #+#    #+#             */
/*   Updated: 2022/02/15 19:44:36 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	no_argument(char *size)
{
	go_tail(ft_atoi(size), 0);
}

void	special_message(char *s)
{
	print_message("==> ");
	print_message(s);
	print_message(" <==\n");
}

void	yes_argument(int argc, char **argv)
{
	int	i;
	int	fd;
	int	newLine;

	i = 2;
	newLine = 0;
	while (++i < argc)
	{
		errno = 0;
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			error_message(argv[i], argv[0]);
			continue ;
		}
		if (argc > 4)
		{
			if (newLine++)
				print_message("\n");
			special_message(argv[i]);
		}
		go_tail(ft_atoi(argv[2]), fd);
		close(fd);
	}
}
