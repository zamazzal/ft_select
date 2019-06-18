/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:17:00 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/17 21:15:38 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
	}
	return (0);
}

char		**ft_select(int argc, t_opts **items)
{
	int key;

	while (true)
	{
		tputs(tgetstr("ti", NULL), 1, ft_putchr);
		ft_show(argc, items);
		key = ft_getch();
		tputs(tgetstr("te", NULL), 1, ft_putchr);
		if (key == ENTRE && g_true != 1)
			return (ft_getselect(items));
		if (ft_move(items, key, g_true))
			break ;
	}
	return (NULL);
}

static void	ft_signalhandl(int sig)
{
	if (sig == SIGWINCH)
	{
		tputs(tgetstr("te", NULL), 1, ft_putchr);
		tputs(tgetstr("ti", NULL), 1, ft_putchr);
		ft_show(g_argc, g_items);
	}
	else
	{
		tputs(tgetstr("te", NULL), 1, ft_putchr);
		tputs(tgetstr("ve", NULL), 1, ft_putchr);
		tputs(tgetstr("se", NULL), 1, ft_putchr);
		tputs(tgetstr("ue", NULL), 1, ft_putchr);
		exit(1);
	}
}

static void	ft_signals(void)
{
	signal(SIGWINCH, ft_signalhandl);
	signal(SIGABRT, ft_signalhandl);
	signal(SIGINT, ft_signalhandl);
	signal(SIGBUS, ft_signalhandl);
	signal(SIGTERM, ft_signalhandl);
	signal(SIGFPE, ft_signalhandl);
	signal(SIGSEGV, ft_signalhandl);
	signal(SIGXCPU, ft_signalhandl);
	signal(SIGXFSZ, ft_signalhandl);
}

int			main(int argc, char **argv)
{
	t_opts	**items;
	char	**selected;

	g_argc = argc;
	if (ft_checkargs(argc) || ft_checktitty())
		exit(1);
	ft_prepare(1);
	ft_signals();
	items = ft_create(argc, argv);
	g_items = items;
	selected = ft_select(argc, items);
	ft_putselects(selected);
	free_buffers(items, selected);
	ft_prepare(0);
	exit(0);
}
