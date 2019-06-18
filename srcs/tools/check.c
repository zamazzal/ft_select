/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:10:30 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/15 18:06:36 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		ft_checkargs(int argc)
{
	if (argc < 2)
	{
		ft_putendl_fd("usage: ./ft_select arg1 arg2 arg3 ...", 2);
		return (1);
	}
	return (0);
}

int		ft_checktitty(void)
{
	if (!isatty(0))
	{
		ft_puterror("you are not in terminal");
		return (1);
	}
	return (0);
}
