/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:02:40 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/15 18:06:54 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		ft_tinit(void)
{
	char	*term;
	int		r;

	term = getenv("TERM");
	if (term == NULL)
	{
		ft_puterror("TERM must be set (see 'env').");
		return (-1);
	}
	r = tgetent(NULL, term);
	if (r == -1)
	{
		ft_puterror("Could not access to the termcap database..");
		return (-1);
	}
	if (r == 0)
	{
		ft_puterror("this Terminal is not defined in termcap database.");
		return (-1);
	}
	return (r);
}

void	ft_prepare(int mode)
{
	if (mode)
	{
		ft_tinit();
		ft_noecho();
		ft_nocanon();
		tputs(tgetstr("vi", NULL), 1, ft_putchr);
	}
	else
	{
		tputs(tgetstr("ve", NULL), 1, ft_putchr);
		ft_echo();
		ft_canon();
	}
}
