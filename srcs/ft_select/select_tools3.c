/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_tools3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:06:38 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/18 20:16:36 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void			ft_selectmatch(t_opts **items)
{
	char	*name;
	int		i;

	i = 0;
	while (items[i] != NULL)
	{
		if (items[i]->is_current == 1)
		{
			name = items[i]->name;
			break ;
		}
		i++;
	}
	i = 0;
	while (items[i] != NULL)
	{
		if (ft_strequ(items[i]->name, name))
			items[i]->is_select = 1;
		i++;
	}
}

static t_opts	*ft_elementcpy(t_opts *dest, t_opts *src, int x)
{
	if (!(dest = (t_opts*)malloc(sizeof(t_opts))))
		return (NULL);
	dest->name = src->name;
	dest->is_current = (x == 1) ? 1 : 0;
	dest->is_select = src->is_select;
	return (dest);
}

t_opts			**delinlist(t_opts **new, t_opts **items)
{
	int x;
	int i;
	int j;

	i = 0;
	j = 0;
	while (items[i] != NULL)
	{
		if (items[i]->is_current != 1)
		{
			new[j] = ft_elementcpy(new[j], items[i], x);
			j++;
			x = 0;
		}
		else
		{
			x = 1;
			if (items[i + 1] == NULL)
				new[0]->is_current = 1;
		}
		i++;
	}
	new[j] = NULL;
	return (new);
}
