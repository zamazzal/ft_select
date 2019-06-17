/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:13:45 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/15 17:14:23 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void			ft_freelist(t_opts **items)
{
	int i;

	i = 0;
	while (items[i] != NULL)
	{
		items[i]->name = NULL;
		items[i]->is_current = 0;
		items[i]->is_select = 0;
		free(items[i++]);
	}
	free(items);
}

static void			ft_freetable(char **array)
{
	int i;

	i = 0;
	if (*array)
	{
		while (array[i] != NULL)
			ft_strdel(&array[i++]);
		free(array);
	}
}

void				free_buffers(t_opts **items, char **selected)
{
	if (selected)
		ft_freetable(selected);
	if (items)
		ft_freelist(items);
}
