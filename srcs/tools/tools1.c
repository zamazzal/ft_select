/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:13:45 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/18 18:16:55 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void				ft_ctrlz(int sig)
{
	if (sig == SIGCONT)
	{
		signal(SIGTSTP, ft_ctrlz);
		tputs(tgetstr("ti", NULL), 1, ft_putchr);
		ft_prepare(1);
		ft_show(listlen(g_items), g_items);
	}
	else if (sig == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		tputs(tgetstr("te", NULL), 1, ft_putchr);
		ft_prepare(0);
		ioctl(0, TIOCSTI, "\032");
	}
}

void				ft_freelist(t_opts **items)
{
	int i;

	i = 0;
	while (items[i] != NULL)
		free(items[i++]);
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
