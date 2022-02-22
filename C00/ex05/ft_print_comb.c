/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:37:53 by mojo              #+#    #+#             */
/*   Updated: 2022/02/02 16:37:54 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	comb[5];

	comb[0] = '0';
	comb[3] = ',';
	comb[4] = ' ';
	while (comb[0] <= '6')
	{
		comb[1] = comb[0] + 1;
		while (comb[1] <= '8')
		{
			comb[2] = comb[1] + 1;
			while (comb[2] <= '9')
			{
				write(1, comb, 5);
				comb[2]++;
			}
			comb[1]++;
		}
		comb[0]++;
	}
	comb[0] = '7';
	comb[1] = '8';
	comb[2] = '9';
	write(1, comb, 3);
}
