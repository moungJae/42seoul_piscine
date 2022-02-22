/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:21:58 by mojo              #+#    #+#             */
/*   Updated: 2022/02/05 18:24:07 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha_and_numeric(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	go_convert(char *str, int i, int is_first)
{
	if (is_first == 1)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';
	}
	else
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	is_first;

	i = 0;
	is_first = 1;
	while (str[i] != '\0')
	{
		if (is_alpha_and_numeric(str[i]) == 0)
			is_first = 1;
		else
		{
			go_convert(str, i, is_first);
			is_first = 0;
		}
		i++;
	}
	return (str);
}
