/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:17:00 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/15 05:37:07 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int ft_tinit()
{
	char *term;
	char *bp;
	int r;

	term = getenv("TERM");
	if (term == NULL)                                                                                                                                                                                                                                           
	{
		ft_putendl_fd("error : TERM must be set (see 'env').", 2);
		return (-1);
	}
	r = tgetent(NULL, term);
	if (r == -1)
	{
		ft_putendl_fd("error : Could not access to the termcap database..", 2);
		return (-1);
	}
	if (r == 0)
	{
		ft_putendl_fd("error : this Terminal is not defined in termcap database.", 2);
		return (-1);
	}
	return (r);
}

t_opts **ft_create(int argc, char **argv)
{
	int i;
	int j;
	int k;
	t_opts **items;

	i = 0;
	j = 1;
	k = 0;
	if (!(items = (t_opts**)malloc(sizeof(t_opts*) * argc)))
		return (NULL);
	while (k < argc - 1)
		items[k++] = (t_opts*)malloc(sizeof(t_opts));
	while (j < argc)
	{
		items[i]->name = argv[j++];
		items[i]->is_current = (i == 0) ? 1 : 0;
		items[i++]->is_select = 0;
	}
	items[i] = NULL;
	return (items);
}

int		ft_putchr(int c)
{
	return (write(2, &c, 1));
}

void    ft_iscuradsel(char *name, int fd)
{
	tputs(tgetstr("us", NULL), 1, ft_putchr);
	tputs(tgetstr("so", NULL), 1, ft_putchr);
	ft_putstr_fd(RED, fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd(DEFAULT, fd);
	tputs(tgetstr("se", NULL), 1, ft_putchr);
	tputs(tgetstr("ue", NULL), 1, ft_putchr);
}

void    ft_iscurr(char *name, int fd)
{
	tputs(tgetstr("us", NULL), 1, ft_putchr);
	ft_putstr_fd(RED, fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd(DEFAULT, fd);
	tputs(tgetstr("ue", NULL), 1, ft_putchr);
}

void    ft_issel(char *name, int fd)
{
	tputs(tgetstr("so", NULL), 1, ft_putchr);
	ft_putstr_fd(RED, fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd(DEFAULT, fd);
	tputs(tgetstr("se", NULL), 1, ft_putchr);
}

void    ft_display(t_opts *item, int fd)
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

void    ft_putspaces(int n, int fd)
{
	while (n-- > 0)
		ft_putchar_fd(' ', fd);
}

void   ft_putname(t_opts *item, int spaces, int k, int fd)
{
	ft_display(item, fd);
	ft_putspaces(spaces, 1);
	(k == 1) ? ft_putchar('\n') : ft_putchar(' ');
}

int    ft_tallest(t_opts **items)
{
	int i;
	int t;
	int len;

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

int ft_getrow_col(int mode)
{
	struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return ((mode == 1) ? w.ws_row : w.ws_col);
}

size_t  listlen(t_opts **items)
{
	size_t  i;

	i = 0;
	while (items[i] != NULL)
		i++;
	return (i);
}

int     ft_getttyfd()
{
	int fd;
	char *tty;

	tty = ttyname(0);
	fd = open(tty, O_WRONLY);
	return (fd);
}

void    ft_affichage(t_opts **items, int rows, int t)
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
		if (i + rows >=  x)
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

int    ft_show(int ac, t_opts **items)
{
	int t;
	int cl;
	int rows;

	t = ft_tallest(items);
	cl = ft_getrow_col(0) / (t + 3);
	rows = ((ac - 1) % cl == 0) ? ((ac - 1) / cl) : ((ac - 1) / cl) + 1;
	if (ft_getrow_col(1) < rows)
	{
		ft_putendl("error : the window size is too small");
		return (-1);
	}
	ft_affichage(items, rows, t);
	return (0);
}

int ft_getch()
{
	int key;

	key = 0;
	read(0, &key, sizeof(int));
	return (key);
}

void	ft_echo()
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag |= ECHO;
	tcsetattr(0, TCSANOW, &term);
}

void	ft_noecho()
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag &= ~ECHO;
	tcsetattr(0, TCSANOW, &term);
}

void	ft_canon()
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag |= ICANON;
	tcsetattr(0, TCSANOW, &term);
}

void	ft_nocanon()
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag &= ~ICANON;
	tcsetattr(0, TCSANOW, &term);
}

/* Work Range */

size_t	ft_nbrselect(t_opts **items)
{
	size_t	i;
	size_t	nbr;

	i = 0;
	nbr = 0;
	while (items[i] != NULL)
	{
		if (items[i]->is_select)
			nbr++;
		i++;
	}
	return (nbr);
}

int	ft_selitem(t_opts **items)
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

char **ft_getselect(t_opts **items)
{
	int nbr;
	int i;
	char **s;
	int x;

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

char **ft_selectall(t_opts **items)
{
	int i;

	i = 0;
	while (items[i] != NULL)
		items[i++]->is_select = 1;
	return (0);
}

char **ft_unselectall(t_opts **items)
{
	int i;

	i = 0;
	while (items[i] != NULL)
		items[i++]->is_select = 0;
	return (0);
}

char **ft_down(t_opts **items)
{
	int i;

	i = 0;
	while (items[i] != NULL)
	{
		if (items[i]->is_current)
		{
			items[i]->is_current = 0;
			i = (items[i + 1] != NULL) ? i + 1 : 0;
			items[i]->is_current = 1;
			break ;
		}
		i++;
	}
	return (0);
}

char **ft_up(t_opts **items)
{
	int last;
	int i;

	i = 0;
	last = listlen(items) - 1;
	while (items[i] != NULL)
	{
		if (items[i]->is_current)
		{
			items[i]->is_current = 0;
			i = (i - 1 >= 0) ? i - 1 : last;
			items[i]->is_current = 1;
			break ;
		}
		i++;
	}
	return (0);
}

int  ft_move(t_opts **items, int key)
{
	if (key == ESC)
		return (1);
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
	return (0);
}

/*									*/

char **ft_select(int argc, t_opts **items)
{
	int key;
	char **selected;

	while (true)
	{
		tputs(tgetstr("ti", NULL), 1, ft_putchr);
		ft_show(argc, items);
		key = ft_getch();
		tputs(tgetstr("te", NULL), 1, ft_putchr);
		if (key == ENTRE)
			return (ft_getselect(items));
		if (ft_move(items, key))
			break ;
	}
	return (NULL);
}

int ft_checkargs(int argc)
{
	if (argc < 2)
	{
		ft_putendl_fd("usage: ./ft_select arg1 arg2 arg3 ...", 2);
		return (1);
	}
	return (0);
}

int ft_checktitty()
{
	if (!isatty(0))
	{
		ft_putendl_fd("error : you are not in terminal", 2);
		return (1);
	}
	return (0);
}

void    ft_freelist(t_opts **items)
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

void			ft_freetable(char **array)
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

void	ft_putselects(char **table)
{
	size_t	i;

	i = 0;
	while (table[i] != NULL)
	{
		ft_putstr(table[i++]);
		if (table[i] != NULL)
			ft_putchar(' ');
	}
}

int main(int argc, char **argv)
{
	t_opts **items;
	char    **selected;

	if (ft_checkargs(argc))
		return (1);
	if (ft_checktitty())
		return (1);
	ft_tinit();
	ft_noecho();
	ft_nocanon();
	tputs(tgetstr("vi", NULL), 1, ft_putchr);
	items = ft_create(argc, argv);
	selected = ft_select(argc, items);
	ft_putselects(selected);
	ft_freelist(items);
	ft_freetable(selected);
	tputs(tgetstr("ve", NULL), 1, ft_putchr);
	ft_echo();
	ft_canon();
	return (0);
}