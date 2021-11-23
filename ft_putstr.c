/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:13:38 by psaulnie          #+#    #+#             */
/*   Updated: 2021/11/15 17:25:22 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putstr(char *s)
{
	int	counter;

	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	counter = 0;
	while (s[counter])
	{
		write(1, &s[counter], 1);
		counter++;
	}
	return (counter);
}
