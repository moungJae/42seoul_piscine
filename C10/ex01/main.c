/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:10:40 by mojo              #+#    #+#             */
/*   Updated: 2022/02/13 21:47:35 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <libgen.h>

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

void	go_cat(char *s, char *exec_name)
{
	int		fd;
	int		len;
	char	fix_arr[10];

	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		error_message(s, exec_name);
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
	int		i;
	int		len;
	char	fix_arr[10];

	if (argc == 1)
	{
		while (1)
		{
			len = read(0, fix_arr, 10);
			if (len == 0)
				break ;
			write(1, fix_arr, len);
		}
	}
	else
	{
		i = 1;
		while (i < argc)
			go_cat(argv[i++], argv[0]);
	}
	return (0);
}
