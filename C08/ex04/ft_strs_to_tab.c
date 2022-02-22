/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:36:22 by mojo              #+#    #+#             */
/*   Updated: 2022/02/12 16:59:51 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*str_dup(char *s)
{
	int		i;
	int		len;
	char	*ret;

	len = str_len(s);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s[i] != '\0')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ret;
	int			i;
	char		*s;

	ret = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		s = av[i];
		ret[i].size = str_len(s);
		ret[i].str = s;
		ret[i].copy = str_dup(s);
		i++;
	}
	ret[ac].str = 0;
	return (ret);
}
