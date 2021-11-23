/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:31:36 by psaulnie          #+#    #+#             */
/*   Updated: 2021/11/15 17:25:22 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	ft_recursive(long n, int fd)
{
	char	c;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_recursive(nb / 10, fd);
	c = nb % 10 + '0';
	write(fd, &c, 1);
}

int	ft_putnbr(long n)
{
	int		size;
	long	nbr;

	size = 0;
	nbr = n;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		nbr *= -1;
		size++;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		size++;
	}
	size++;
	ft_recursive(n, 1);
	return (size);
}
