/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:33:40 by mojo              #+#    #+#             */
/*   Updated: 2022/02/09 18:26:58 by mojo             ###   ########.fr       */
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

int	compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

void	make_max_heap(int cur, int argc, char *argv[])
{
	char	*tmp;
	int		child;

	child = 2 * cur;
	while (child < argc)
	{
		if ((child + 1 < argc)
			&& (compare(argv[child], argv[child + 1]) < 0))
			child = child + 1;
		if (compare(argv[cur], argv[child]) > 0)
			break ;
		tmp = argv[cur];
		argv[cur] = argv[child];
		argv[child] = tmp;
		cur = child;
		child = 2 * cur;
	}
}

void	sort_ascii(int argc, char *argv[])
{
	char	*tmp;
	int		i;

	i = argc / 2;
	while (i)
	{
		make_max_heap(i, argc, argv);
		i--;
	}
	while (argc > 1)
	{
		tmp = argv[1];
		argv[1] = argv[argc - 1];
		argv[argc - 1] = tmp;
		make_max_heap(1, --argc, argv);
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	sort_ascii(argc, argv);
	i = 1;
	while (i < argc)
	{
		write(1, argv[i], str_len(argv[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
