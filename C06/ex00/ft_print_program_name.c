/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:33:02 by mojo              #+#    #+#             */
/*   Updated: 2022/02/09 18:25:43 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_len(char s[])
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
		cnt++;
	return (cnt);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		write(1, argv[0], str_len(argv[0]));
		write(1, "\n", 1);
	}
	return (0);
}
