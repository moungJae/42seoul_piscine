/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:24:32 by mojo              #+#    #+#             */
/*   Updated: 2022/02/17 14:20:28 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_size(char **tab)
{
	int	i;

	i = 0;
	while (*tab)
	{
		i++;
		tab++;
	}
	return (i);
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

void	make_max_heap(int cur, int fin, char **tab)
{
	char	*tmp;
	int		child;

	child = 2 * cur + 1;
	while (child <= fin)
	{
		if ((child < fin)
			&& (compare(tab[child], tab[child + 1]) < 0))
			child++;
		if (compare(tab[cur], tab[child]) > 0)
			break ;
		tmp = tab[cur];
		tab[cur] = tab[child];
		tab[child] = tmp;
		cur = child;
		child = 2 * cur + 1;
	}
}

void	ft_sort_string_tab(char **tab)
{
	char	*tmp;
	int		i;
	int		size;

	size = get_size(tab);
	i = size / 2;
	while (i >= 0)
		make_max_heap(i--, size - 1, tab);
	i = size - 1;
	while (i > 0)
	{
		tmp = tab[0];
		tab[0] = tab[i];
		tab[i] = tmp;
		make_max_heap(0, --i, tab);
	}	
}
