/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:07:56 by mojo              #+#    #+#             */
/*   Updated: 2022/02/14 11:38:03 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	show_message(char *s)
{
	write(1, s, str_len(s));
}

void	display(char *s)
{
	int		fd;
	int		len;
	char	fix_arr[10];

	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		show_message("Cannot read file.\n");
		return ;
	}
	while (1)
	{
		len = read(fd, fix_arr, 10);
		if (len == 0)
			break ;
		write(1, fix_arr, len);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		show_message("File name missing.\n");
	else if (argc == 2)
		display(argv[1]);
	else
		show_message("Too many arguments.\n");
	return (0);
}
