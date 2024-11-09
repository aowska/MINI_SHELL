/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:32:13 by aelsetih          #+#    #+#             */
/*   Updated: 2024/05/30 12:32:15 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // va_list
# include <stdint.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	print_count_char(int c);
int	print_count_string(char	*str);
int	print_count_int(int n);
int	print_count_unsigned(unsigned int n);
int	print_count_hex(uintptr_t n, char c);

#endif
