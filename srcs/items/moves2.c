/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:08:30 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/15 18:05:22 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static int		calcil(int i, int ro, int cl, int ac)
{
	if ((i + ro * cl) - 1 >= ac)
	{
		i = (i + ro * (cl - 1)) - 1;
	}
	else
	{
		if (ro * cl == ac && (i - ro == 0))
			i = ac - 1;
		else
			i = (i + ro * cl) - 1;
	}
	i = (i >= ac) ? ac - 1 : i;
	i = (i < 0) ? ac - 1 : i;
	return (i);
}

static int		calcir(int i, int ro, int cl, int ac)
{
	if ((i - ro * cl) + 1 < 0)
	{
		i = (i - (ro * (cl - 1))) + 1;
	}
	else
	{
		if (ro * cl == ac && (i - ro == ac - 1))
			i = 0;
		else
			i = (i - ro * cl) + 1;
	}
	i = (i < 0) ? 0 : i;
	i = (i >= ac) ? 0 : i;
	return (i);
}

void			ft_left(t_opts **items)
{
	int i;
	int cl;
	int ro;
	int ac;

	i = 0;
	ac = listlen(items);
	cl = ft_getrow_col(0) / (ft_tallest(items) + 4);
	ro = (ac % cl == 0) ? (ac / cl) : ((ac / cl) + 1);
	while (items[i] != NULL)
	{
		if (items[i]->is_current)
		{
			items[i]->is_current = 0;
			i = i - ro;
			if (i < 0)
				i = calcil(i, ro, cl, ac);
			items[i]->is_current = 1;
			break ;
		}
		i++;
	}
}

void			ft_right(t_opts **items)
{
	int i;
	int cl;
	int ro;
	int ac;

	i = 0;
	ac = listlen(items);
	cl = (ft_getrow_col(0) / (ft_tallest(items) + 4));
	ro = (ac % cl == 0) ? (ac / cl) : ((ac / cl) + 1);
	while (items[i] != NULL)
	{
		if (items[i]->is_current)
		{
			items[i]->is_current = 0;
			i = i + ro;
			if (i >= ac)
				i = calcir(i, ro, cl, ac);
			items[i]->is_current = 1;
			break ;
		}
		i++;
	}
}
