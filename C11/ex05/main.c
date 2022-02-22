/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:13:56 by mojo              #+#    #+#             */
/*   Updated: 2022/02/21 13:19:41 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_calculate(t_info *t)
{
	t->cmp[ADD] = &add;
	t->cmp[SUB] = &sub;
	t->cmp[MUL] = &multiply;
	t->cmp[DIV] = &divide;
	t->cmp[MOD] = &modular;
}

int	is_operator(char *s)
{
	if (!str_cmp(s, "+"))
		return (ADD);
	else if (!str_cmp(s, "-"))
		return (SUB);
	else if (!str_cmp(s, "*"))
		return (MUL);
	else if (!str_cmp(s, "/"))
		return (DIV);
	else if (!str_cmp(s, "%"))
		return (MOD);
	return (-1);
}

void	print_message(char *s)
{
	write(1, s, str_len(s));
}

void	go(t_info *t)
{
	if (t->op == ADD)
		putnbr(t->cmp[ADD](t->x, t->y));
	else if (t->op == SUB)
		putnbr(t->cmp[SUB](t->x, t->y));
	else if (t->op == MUL)
		putnbr(t->cmp[MUL](t->x, t->y));
	else if (t->op == DIV)
	{
		if (t->y == 0)
			print_message("Stop : division by zero\n");
		else
			putnbr(t->cmp[DIV](t->x, t->y));
	}
	else if (t->op == MOD)
	{
		if (t->y == 0)
			print_message("Stop : modulo by zero\n");
		else
			putnbr(t->cmp[MOD](t->x, t->y));
	}
}

int	main(int argc, char **argv)
{
	t_info	t;

	set_calculate(&t);
	if (argc == 4)
	{
		t.op = is_operator(argv[2]);
		if (t.op != -1)
		{
			t.x = atoi(argv[1]);
			t.y = atoi(argv[3]);
			go(&t);
		}
		else
		{
			print_message("0\n");
		}
	}
	return (0);
}
