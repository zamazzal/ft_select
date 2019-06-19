/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:17:00 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/19 21:38:30 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int			ft_move(t_opts **items, int key, int x)
{
	if (key == ESC)
		return (1);
	if (x != 1)
	{
		if (key == SPACE)
			ft_selitem(items);
		if (key == CTRLA)
			ft_selectall(items);
		if (key == CTRLU)
			ft_unselectall(items);
		if (key == DOWN)
			ft_down(items);
		if (key == UP)
			ft_up(items);
		if (key == RIGHT)
			ft_right(items);
		if (key == LEFT)
			ft_left(items);
		if (key == CTRLX)
			ft_selectmatch(items);
	}
	return (0);
}

char		**ft_select(void)
{
	t_opts	**backup;
	int		key;

	while (true)
	{
		tputs(tgetstr("ti", NULL), 1, ft_putchr);
		ft_show(listlen(g_items), g_items);
		key = ft_getch();
		tputs(tgetstr("te", NULL), 1, ft_putchr);
		if (key == ENTRE && g_true != 1)
			return (ft_getselect(g_items));
		if (ft_move(g_items, key, g_true))
			break ;
		if ((key == BACKSPACE) || (key == DELETE))
		{
			backup = g_items;
			if (!(g_items = ft_deletitem(g_items)))
			{
				ft_freelist(backup);
				return (NULL);
			}
		}
	}
	return (NULL);
}

static void	ft_signalhandl(int sig)
{
	if (sig == SIGWINCH)
	{
		tputs(tgetstr("te", NULL), 1, ft_putchr);
		tputs(tgetstr("ti", NULL), 1, ft_putchr);
		ft_show(listlen(g_items), g_items);
	}
	else
	{
		tputs(tgetstr("te", NULL), 1, ft_putchr);
		ft_prepare(0);
		exit(1);
	}
}

static void	ft_signals(void)
{
	int x;

	x = 1;
	while (x <= 31)
	{
		if (x != 16 && x != 18 && x != 19 && x != 23 && x != 29)
			signal(x, ft_signalhandl);
		x++;
	}
	signal(SIGTSTP, ft_ctrlz);
	signal(SIGCONT, ft_ctrlz);
}

int			main(int argc, char **argv)
{
	char	**selected;

	if (ft_checkargs(argc) || ft_checktitty() || ft_tinit() == -1)
		exit(1);
	ft_prepare(1);
	ft_signals();
	g_items = ft_create(argc, argv);
	selected = ft_select();
	ft_putselects(selected);
	free_buffers(g_items, selected);
	ft_prepare(0);
	exit(0);
}
