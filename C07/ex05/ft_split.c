/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:25:30 by mojo              #+#    #+#             */
/*   Updated: 2022/02/10 14:42:14 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_charset(char *str, char *charset, int idx)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (str[idx] == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_split_size(char *str, char *charset)
{
	int	i;
	int	is_first;
	int	size;

	i = 0;
	is_first = 1;
	size = 0;
	while (str[i] != '\0')
	{
		while (is_charset(str, charset, i))
		{
			i++;
			is_first++;
		}
		if (str[i] == '\0')
			break ;
		if (is_first)
		{
			size++;
			is_first = 0;
		}
		i++;
	}
	return (size);
}

int	get_length(char *str, char *charset, int idx)
{
	int	i;

	i = 0;
	while (str[i + idx] != '\0')
	{
		if (is_charset(str, charset, i + idx))
			break ;
		i++;
	}
	return (i);
}

char	*go_malloc(char *ret, char *str, int len, int idx)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ret[i] = str[idx + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		split_size;
	int		i;
	int		j;
	int		len;

	split_size = get_split_size(str, charset);
	ret = (char **)malloc(sizeof(char *) * (split_size + 1));
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (is_charset(str, charset, i))
			i++;
		if (str[i] == '\0')
			break ;
		len = get_length(str, charset, i);
		ret[j] = (char *)malloc(sizeof(char) * (len + 1));
		go_malloc(ret[j++], str, len, i);
		i += len;
	}
	ret[j] = 0;
	return (ret);
}
