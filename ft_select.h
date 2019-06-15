/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:17:09 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/12 17:45:35 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

#include "libft.h"
#include <curses.h>
#include <term.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>

typedef struct	s_opts
{
	char		*name;
	int			is_current;
	int			is_select;
}				t_opts;

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

# endif
