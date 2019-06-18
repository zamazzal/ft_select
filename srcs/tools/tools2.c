/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:14:38 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/15 17:18:10 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		ft_getch(void)
{
	int key;

	key = 0;
	read(0, &key, sizeof(int));
	return (key);
}

int		ft_getttyfd(void)
{
	int		fd;
	char	*tty;

	tty = ttyname(0);
	fd = open(tty, O_WRONLY);
	return (fd);
}

size_t	listlen(t_opts **items)
{
	size_t	i;

	i = 0;
	while (items[i] != NULL)
		i++;
	return (i);
}

int		ft_getrow_col(int mode)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	return ((mode == 1) ? w.ws_row : w.ws_col);
}

int		ft_tallest(t_opts **items)
{
	int	i;
	int	t;
	int	len;

	i = 0;
	t = 0;
	len = 0;
	while (items[i] != NULL)
	{
		len = ft_strlen(items[i]->name);
		if (len > t)
			t = len;
		i++;
	}
	return (t);
}
