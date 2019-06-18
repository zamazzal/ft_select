/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:17:09 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/18 15:56:40 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <curses.h>
# include <term.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <fcntl.h>

typedef struct	s_opts
{
	char		*name;
	int			is_current;
	int			is_select;
}				t_opts;

int		g_argc;
t_opts	**g_items;
int		g_true;

# define DEFAULT "\033[0m"
# define BLACK "\033[30;1m"
# define RED "\033[31;1m"
# define GREEN "\033[32;1m"
# define YELLOW "\033[33;1m"
# define BLUE "\033[34;1m"
# define MAGENTA "\033[35;1m"
# define CYAN "\033[36;1m"
# define WHITE "\033[37;1m"

# define ENTRE 10
# define SPACE 32
# define CTRLA 1
# define CTRLU 21
# define RIGHT 4414235
# define LEFT 4479771
# define UP 4283163
# define DOWN 4348699
# define ESC 27

int				ft_putchr(int c);
void			ft_putspaces(int n, int fd);
void			ft_affichage(t_opts **items, int rows, int t);
int				ft_show(int ac, t_opts **items);
void			ft_putname(t_opts *item, int spaces, int k, int fd);
void			ft_iscuradsel(char *name, int fd);
void			ft_iscurr(char *name, int fd);
void			ft_issel(char *name, int fd);
void			ft_display(t_opts *item, int fd);
int				ft_move(t_opts **items, int key, int x);
char			**ft_select(int argc, t_opts **items);
t_opts			**ft_create(int argc, char **argv);
size_t			ft_nbrselect(t_opts **items);
void			ft_putselects(char **table);
int				ft_selitem(t_opts **items);
char			**ft_getselect(t_opts **items);
void			ft_selectall(t_opts **items);
void			ft_unselectall(t_opts **items);
void			ft_down(t_opts **items);
void			ft_up(t_opts **items);
void			ft_left(t_opts **items);
void			ft_right(t_opts **items);
void			ft_puterror(char *error);
void			ft_echo(void);
void			ft_noecho(void);
void			ft_canon(void);
void			ft_nocanon(void);
int				ft_tinit(void);
void			ft_prepare(int mode);
int				ft_checkargs(int argc);
int				ft_checktitty(void);
void			free_buffers(t_opts **items, char **selected);
int				ft_getch(void);
int				ft_getttyfd(void);
size_t			listlen(t_opts **items);
int				ft_getrow_col(int mode);
int				ft_tallest(t_opts **items);
#endif
