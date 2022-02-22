/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:25:17 by mojo              #+#    #+#             */
/*   Updated: 2022/02/10 14:50:55 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	str_len(char s[])
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	get_ret_size(int size, char **s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
		len += str_len(s[i++]);
	return (len);
}

char	*empty_str(void)
{
	char	*ret;

	ret = (char *)malloc(1);
	ret[0] = '\0';
	return (ret);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		i;
	int		j;
	int		k;
	int		len;

	if (size <= 0)
		return (empty_str());
	len = get_ret_size(size, strs);
	len += str_len(sep) * (size - 1);
	ret = (char *)malloc(len + 1);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			ret[k++] = strs[i][j++];
		j = 0;
		while (i != size - 1 && sep[j] != '\0')
			ret[k++] = sep[j++];
		i++;
	}
	ret[k] = '\0';
	return (ret);
}
