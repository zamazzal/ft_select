/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:07:24 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/15 18:06:11 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		ft_down(t_opts **items)
{
	int i;

	i = 0;
	while (items[i] != NULL)
	{
		if (items[i]->is_current)
		{
			items[i]->is_current = 0;
			i = (items[i + 1] != NULL) ? i + 1 : 0;
			items[i]->is_current = 1;
			break ;
		}
		i++;
	}
}

void		ft_up(t_opts **items)
{
	int last;
	int i;

	i = 0;
	last = listlen(items) - 1;
	while (items[i] != NULL)
	{
		if (items[i]->is_current)
		{
			items[i]->is_current = 0;
			i = (i - 1 >= 0) ? i - 1 : last;
			items[i]->is_current = 1;
			break ;
		}
		i++;
	}
}
