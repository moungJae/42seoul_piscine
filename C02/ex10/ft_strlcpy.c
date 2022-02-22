/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:19:54 by mojo              #+#    #+#             */
/*   Updated: 2022/02/06 13:20:24 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	cnt;
	unsigned int	idx;

	cnt = 0;
	idx = 0;
	while (src[cnt] != '\0')
		cnt++;
	if (size != 0)
	{
		while (src[idx] != '\0' && idx < (size - 1))
		{
			dest[idx] = src[idx];
			idx++;
		}
		dest[idx] = '\0';
	}
	return (cnt);
}
