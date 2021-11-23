/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 09:13:11 by psaulnie          #+#    #+#             */
/*   Updated: 2021/11/19 17:16:44 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_puthexa(uint32_t nbr, char *hexa)
{
	int			i;
	uint32_t	n;
	char		str[9];

	n = nbr;
	i = 0;
	if (!n)
		i = 1;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = hexa[nbr % 16];
		nbr = nbr / 16;
		i--;
	}
	return (ft_putstr(str));
}
