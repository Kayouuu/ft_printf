/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:09:14 by psaulnie          #+#    #+#             */
/*   Updated: 2021/11/15 17:25:22 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	ft_recursive_unsigned(unsigned int n)
{
	char	c;

	if (n > 9)
		ft_recursive_unsigned(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	ft_putunsigned(unsigned int n)
{
	int				size;
	unsigned int	nbr;

	size = 0;
	nbr = n;
	while (nbr > 9)
	{
		nbr /= 10;
		size++;
	}
	size++;
	ft_recursive_unsigned(n);
	return (size);
}
