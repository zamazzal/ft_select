/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:05:42 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/15 18:03:00 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_iscuradsel(char *name, int fd)
{
	tputs(tgetstr("us", NULL), 1, ft_putchr);
	tputs(tgetstr("so", NULL), 1, ft_putchr);
	ft_putstr_fd(RED, fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd(DEFAULT, fd);
	tputs(tgetstr("se", NULL), 1, ft_putchr);
	tputs(tgetstr("ue", NULL), 1, ft_putchr);
}

void	ft_iscurr(char *name, int fd)
{
	tputs(tgetstr("us", NULL), 1, ft_putchr);
	ft_putstr_fd(RED, fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd(DEFAULT, fd);
	tputs(tgetstr("ue", NULL), 1, ft_putchr);
}

void	ft_issel(char *name, int fd)
{
	tputs(tgetstr("so", NULL), 1, ft_putchr);
	ft_putstr_fd(name, fd);
	tputs(tgetstr("se", NULL), 1, ft_putchr);
}

void	ft_display(t_opts *item, int fd)
{
	if (item->is_current && item->is_select)
		ft_iscuradsel(item->name, fd);
	else if (item->is_current)
		ft_iscurr(item->name, fd);
	else if (item->is_select)
		ft_issel(item->name, fd);
	else
		ft_putstr_fd(item->name, fd);
}
