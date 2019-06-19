/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errrors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:01:50 by zamazzal          #+#    #+#             */
/*   Updated: 2019/06/15 17:02:24 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_puterror(char *error)
{
	ft_putstr_fd("error: ", 2);
	ft_putendl_fd(error, 2);
}
