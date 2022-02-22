/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:12:57 by mojo              #+#    #+#             */
/*   Updated: 2022/02/16 08:28:33 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	go_write(t_info *t)
{
	int				i;
	unsigned int	length;
	char			c;

	i = 0;
	length = 0;
	while (read(0, &c, 1))
	{
		if (errno)
			return ;
		t->cur[i++] = c;
		length++;
		if (i % 16 == 0)
		{
			operation(t, length);
			i = 0;
		}
	}
	print_remainder(t, length);
}

unsigned int	go(int fd, unsigned int length, t_info *t)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		len;
	char				tmp[16];

	len = 0;
	if (length % 16 != 0)
	{
		i = (length % 16);
		j = 0;
		len = read(fd, tmp, 16 - (length % 16));
		while (j < len)
			t->cur[i++] = tmp[j++];
		if (len != 16 - (length % 16))
			return (length + len);
		operation(t, length + len);
	}
	return (go_other(fd, length + len, t));
}

void	read_file(int argc, char **argv, t_info *t)
{
	int				i;
	int				fd;
	int				check;
	unsigned int	len;

	i = 1 + t->option;
	check = 0;
	len = 0;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			error_message(argv[0], argv[i++]);
			check++;
			continue ;
		}
		len = go(fd, len, t);
		i++;
		close(fd);
	}
	if (check == (argc - 2 + (t->option ^ 1)))
		bad_file(argv[0], argv[argc - 1]);
	else
		print_remainder(t, len);
}

int	is_option(char *op)
{
	int	len;

	len = str_len(op);
	if (len == 2 && op[0] == '-' && op[1] == 'C')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	*t;

	t = (t_info *)malloc(sizeof(t_info));
	t->star_op = 0;
	t->option = 0;
	if (argc >= 2 && is_option(argv[1]))
		t->option = 1;
	if (t->option)
	{
		if (argc == 2)
			go_write(t);
		else if (argc >= 3)
			read_file(argc, argv, t);
	}
	else
	{
		if (argc == 1)
			go_write(t);
		else if (argc >= 2)
			read_file(argc, argv, t);
	}
	free(t);
	return (0);
}
