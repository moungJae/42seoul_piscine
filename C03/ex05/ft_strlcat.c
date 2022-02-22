/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:42:26 by mojo              #+#    #+#             */
/*   Updated: 2022/02/06 18:36:27 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char *dest)
{
	unsigned int	cnt;

	cnt = 0;
	while (dest[cnt] != '\0')
		cnt++;
	return (cnt);
}

unsigned int	set_return_value(char *dest, char *src, unsigned int size)
{
	if (size == 0)
		return (str_len(src));
	else if (size <= str_len(dest))
		return (size + str_len(src));
	return (str_len(dest) + str_len(src));
}

void	go_strlcat(char *dest, char *src, unsigned int go)
{
	while (*src != '\0')
	{
		if (go)
		{
			*(dest++) = *src;
			go--;
		}
		src++;
	}
	*dest = '\0';
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*dst;
	unsigned int	dst_cur;
	unsigned int	ret;

	dst_cur = 0;
	dst = dest;
	ret = set_return_value(dest, src, size);
	while (dst_cur < size)
	{
		dst_cur++;
		if (*dst == '\0')
			break ;
		dst++;
	}
	if (dst_cur == size)
		return (ret);
	go_strlcat(dst, src, size - dst_cur);
	return (ret);
}
