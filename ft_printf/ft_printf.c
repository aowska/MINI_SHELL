/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:50:41 by aelsetih          #+#    #+#             */
/*   Updated: 2024/05/30 11:03:18 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	print_count_pointer(uintptr_t ptr)
{
	if (!ptr)
		return (print_count_string("(nil)"));
	else
		return (print_count_string("0x") + print_count_hex(ptr, 'x'));
}

static int	print_count_spec(char c, va_list args)
{
	if (c == 'c')
		return (print_count_char(va_arg(args, int)));
	if (c == 's')
		return (print_count_string(va_arg(args, char *)));
	if (c == 'p')
		return (print_count_pointer((uintptr_t)va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (print_count_int(va_arg(args, int)));
	if (c == 'u')
		return (print_count_unsigned(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (print_count_hex(va_arg(args, unsigned int), c));
	if (c == '%')
		return (print_count_char('%'));
	return (0);
}

static int	error(va_list args)
{
	va_end(args);
	return (-1);
}

static int	check_error(const char *str, int i)
{
	if (!str[i + 1])
		return (1);
	while (str[i + 1] == ' ')
	{
		if (!str[i + 2])
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		tot_len;
	size_t	i;
	va_list	args;

	i = 0;
	tot_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (check_error(format, i))
				return (error(args));
			if (ft_strchr("cspdiuxX%", format[i + 1]))
				tot_len += print_count_spec(format[i + 1], args);
			else
				tot_len += print_count_char(format[i + 1]);
			i++;
		}
		else
			tot_len += print_count_char(format[i]);
		i++;
	}
	va_end(args);
	return (tot_len);
}
