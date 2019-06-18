/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:24:27 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/15 18:05:50 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_opts	**ft_create(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	t_opts	**items;

	i = 0;
	j = 1;
	k = 0;
	if (!(items = (t_opts**)malloc(sizeof(t_opts*) * argc)))
		return (NULL);
	while (k < argc - 1)
		items[k++] = (t_opts*)malloc(sizeof(t_opts));
	while (j < argc)
	{
		items[i]->name = argv[j++];
		items[i]->is_current = (i == 0) ? 1 : 0;
		items[i++]->is_select = 0;
	}
	items[i] = NULL;
	return (items);
}

size_t	ft_nbrselect(t_opts **items)
{
	size_t	i;
	size_t	nbr;

	i = 0;
	nbr = 0;
	while (items[i] != NULL)
	{
		if (items[i]->is_select)
			nbr++;
		i++;
	}
	return (nbr);
}

void	ft_putselects(char **table)
{
	size_t	i;

	i = 0;
	if (table)
	{
		while (table[i] != NULL)
		{
			ft_putstr(table[i++]);
			if (table[i] != NULL)
				ft_putchar(' ');
		}
	}
}
