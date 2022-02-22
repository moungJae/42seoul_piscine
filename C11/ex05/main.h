/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:17:46 by mojo              #+#    #+#             */
/*   Updated: 2022/02/21 13:17:42 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>

# define ADD 0
# define SUB 1
# define MUL 2
# define DIV 3
# define MOD 4

typedef struct s_info
{
	int	x;
	int	y;
	int	op;
	int	(*cmp[5])(int, int);
}	t_info;

int		atoi(char *str);
void	putnbr(int nb);
int		str_cmp(char *s1, char *s2);
int		str_len(char *s);
int		add(int x, int y);
int		sub(int x, int y);
int		multiply(int x, int y);
int		divide(int x, int y);
int		modular(int x, int y);

#endif
