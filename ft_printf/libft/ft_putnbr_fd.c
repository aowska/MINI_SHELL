/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:02:30 by aelsetih          #+#    #+#             */
/*   Updated: 2024/05/15 15:38:45 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_action(int n)
{
	int	action;

	action = 1;
	while (n >= 10)
	{
		action *= 10;
		n /= 10;
	}
	return (action);
}

void	ft_special_case(int n, int fd)
{
	if (n == 0)
		write (fd, "0", 1);
	else
		write (fd, "-2147483648", 11);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		action;
	int		result;

	if (n == 0 || n == -2147483648)
		ft_special_case(n, fd);
	else
	{
		if (n < 0)
		{
			n *= -1;
			write (fd, "-", 1);
		}
		action = ft_action(n);
		while (action > 0)
		{
			result = n / action;
			if (n < action)
				result = 0;
			c = result + '0';
			n = n - (result * action);
			action /= 10;
			write (fd, &c, 1);
		}
	}
}
