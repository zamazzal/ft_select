/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:20:13 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/15 17:57:02 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		ft_putchr(int c)
{
	return (write(2, &c, 1));
}

void	ft_putspaces(int n, int fd)
{
	while (n-- > 0)
		ft_putchar_fd(' ', fd);
}

void	ft_affichage(t_opts **items, int rows, int t)
{
	int i;
	int x;
	int j;
	int fd;

	x = listlen(items);
	i = 0;
	j = 1;
	fd = ft_getttyfd();
	while (items[i] != NULL)
	{
		if (j > rows)
			break ;
		if (i + rows >= x)
		{
			ft_putname(items[i], (t - ft_strlen(items[i]->name) + 2), 1, fd);
			i = j++;
		}
		else
		{
			ft_putname(items[i], (t - ft_strlen(items[i]->name) + 2), 0, fd);
			i = i + rows;
		}
	}
	close(fd);
}

int		ft_show(int ac, t_opts **items)
{
	int t;
	int cl;
	int rows;

	t = ft_tallest(items);
	cl = ft_getrow_col(0) / (t + 3);
	rows = 0;
	if (cl != 0)
		rows = ((ac - 1) % cl == 0) ? ((ac - 1) / cl) : (((ac - 1) / cl) + 1);
	if ((ft_getrow_col(1) < rows) || (rows == 0) || (cl = 0))
	{
		ft_puterror("the window size is too small");
		ft_putendl_fd("use ESC to exit", 2);
		g_true = 1;
		return (1);
	}
	ft_affichage(items, rows, t);
	g_true = 0;
	return (0);
}

void	ft_putname(t_opts *item, int spaces, int k, int fd)
{
	ft_display(item, fd);
	ft_putspaces(spaces, fd);
	(k == 1) ? ft_putchar_fd('\n', fd) : ft_putchar_fd(' ', fd);
}
