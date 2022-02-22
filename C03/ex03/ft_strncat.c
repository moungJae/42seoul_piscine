/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:42:08 by mojo              #+#    #+#             */
/*   Updated: 2022/02/06 18:39:18 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	n;
	unsigned int	i;
	unsigned int	j;

	n = 0;
	while (dest[n] != '\0')
		n++;
	i = n;
	j = 0;
	while (src[j] != '\0' && j < nb)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
