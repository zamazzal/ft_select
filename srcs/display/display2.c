/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:05:42 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/18 19:23:16 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_types(char *name, int fd)
{
	struct stat	buff;

	if (lstat(name, &buff) != -1)
	{
		if (S_ISDIR(buff.st_mode))
			ft_putstr_fd(BLUE, fd);
		else if (S_ISLNK(buff.st_mode))
			ft_putstr_fd(CYAN, fd);
		else if (S_ISREG(buff.st_mode))
			ft_putstr_fd(RED, fd);
		else if (S_ISCHR(buff.st_mode))
			ft_putstr_fd(YELLOW, fd);
		else if (S_ISBLK(buff.st_mode))
			ft_putstr_fd(GRAY, fd);
		else if (S_ISFIFO(buff.st_mode))
			ft_putstr_fd(GREEN, fd);
		else if (S_ISSOCK(buff.st_mode))
			ft_putstr_fd(MAGENTA, fd);
		ft_putstr_fd(name, fd);
		ft_putstr_fd(DEFAULT, fd);
		return ;
	}
	ft_putstr_fd(name, fd);
}

void	ft_iscuradsel(char *name, int fd)
{
	tputs(tgetstr("us", NULL), 1, ft_putchr);
	tputs(tgetstr("so", NULL), 1, ft_putchr);
	ft_types(name, fd);
	tputs(tgetstr("se", NULL), 1, ft_putchr);
	tputs(tgetstr("ue", NULL), 1, ft_putchr);
}

void	ft_iscurr(char *name, int fd)
{
	tputs(tgetstr("us", NULL), 1, ft_putchr);
	ft_types(name, fd);
	tputs(tgetstr("ue", NULL), 1, ft_putchr);
}

void	ft_issel(char *name, int fd)
{
	tputs(tgetstr("so", NULL), 1, ft_putchr);
	ft_types(name, fd);
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
		ft_types(item->name, fd);
}
