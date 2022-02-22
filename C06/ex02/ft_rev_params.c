/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:33:32 by mojo              #+#    #+#             */
/*   Updated: 2022/02/08 13:44:55 by mojo             ###   ########.fr       */
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
	int	i;

	i = argc - 1;
	while (i >= 1)
	{
		write(1, argv[i], str_len(argv[i]));
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
