/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:46:41 by mojo              #+#    #+#             */
/*   Updated: 2022/02/15 15:20:05 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	go_write(int fd)
{
	char	c;

	while (read(fd, &c, 1))
		if (errno)
			return ;
}

void	go_tail(int word_cnt, int fd)
{
	int		i;
	int		op;
	char	*ret;
	char	c;

	if (word_cnt == 0)
	{
		go_write(fd);
		return ;
	}
	ret = (char *)malloc(word_cnt);
	op = 0;
	i = 0;
	while (read(fd, &c, 1))
	{
		if (errno)
			return ;
		if (i + 1 == word_cnt)
			op = 1;
		ret[i] = c;
		i = (i + 1) % word_cnt;
	}
	print_result(ret, i, op, word_cnt);
	free(ret);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		no_argument(argv[2]);
	else
		yes_argument(argc, argv);
	return (0);
}
