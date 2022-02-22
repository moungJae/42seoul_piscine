/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:25:04 by mojo              #+#    #+#             */
/*   Updated: 2022/02/08 16:32:11 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ret;
	int	i;

	if (min >= max)
		return (0);
	ret = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	while (min < max)
		ret[i++] = min++;
	return (ret);
}
