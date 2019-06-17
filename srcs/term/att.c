/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   att.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:06:35 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/15 17:07:10 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_echo(void)
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag |= ECHO;
	tcsetattr(0, TCSANOW, &term);
}

void	ft_noecho(void)
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag &= ~ECHO;
	tcsetattr(0, TCSANOW, &term);
}

void	ft_canon(void)
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag |= ICANON;
	tcsetattr(0, TCSANOW, &term);
}

void	ft_nocanon(void)
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag &= ~ICANON;
	tcsetattr(0, TCSANOW, &term);
}
