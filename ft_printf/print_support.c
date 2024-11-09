/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:50:50 by aelsetih          #+#    #+#             */
/*   Updated: 2024/05/29 17:50:52 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	print_count_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_count_string(char	*str)
{
	if (!str)
		return (print_count_string("(null)"));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_count_int(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free (str);
	return (len);
}

int	print_count_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 10)
		len = print_count_char(n + '0');
	else
	{
		len += print_count_unsigned(n / 10);
		len += print_count_unsigned(n % 10);
	}
	return (len);
}

int	print_count_hex(uintptr_t n, char c)
{
	if (n >= 16)
		return (print_count_hex(n / 16, c) + print_count_hex(n % 16, c));
	else
	{
		if (n <= 9)
			return (print_count_char(n + '0'));
		else if (c == 'x')
			return (print_count_char(n - 10 + 'a'));
		else if (c == 'X')
			return (print_count_char(n - 10 + 'A'));
	}
	return (0);
}
