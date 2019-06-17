/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:23:10 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/15 18:04:43 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		ft_selitem(t_opts **items)
{
	int i;

	i = 0;
	while (items[i] != NULL)
	{
		if (items[i]->is_current)
		{
			items[i]->is_select = (items[i]->is_select) ? 0 : 1;
			items[i]->is_current = 0;
			if (items[i + 1] != NULL)
				items[i + 1]->is_current = 1;
			else
				items[0]->is_current = 1;
			break ;
		}
		i++;
	}
	return (0);
}

char	**ft_getselect(t_opts **items)
{
	int		nbr;
	int		i;
	char	**s;
	int		x;

	nbr = ft_nbrselect(items);
	if (!(s = (char **)malloc(sizeof(char *) * (nbr + 1))))
		return (NULL);
	x = 0;
	i = 0;
	while (i < nbr)
	{
		while (items[x]->is_select == 0)
			x++;
		s[i++] = ft_strdup(items[x++]->name);
	}
	s[i] = NULL;
	return (s);
}

void	ft_selectall(t_opts **items)
{
	int i;

	i = 0;
	while (items[i] != NULL)
		items[i++]->is_select = 1;
}

void	ft_unselectall(t_opts **items)
{
	int i;

	i = 0;
	while (items[i] != NULL)
		items[i++]->is_select = 0;
}
