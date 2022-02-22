/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:24:58 by mojo              #+#    #+#             */
/*   Updated: 2022/02/10 11:03:35 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ret;
	int		len;
	int		i;

	len = str_len(src);
	ret = (char *)malloc(len + 1);
	i = 0;
	while (i < len)
	{
		ret[i] = src[i];
		i++;
	}
	ret[len] = '\0';
	return (ret);
}
