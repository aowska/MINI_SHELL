/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:39:57 by aelsetih          #+#    #+#             */
/*   Updated: 2024/05/06 11:42:53 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count(int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_count(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	str[len] = '\0';
	len--;
	while (n > 0)
	{
		str[len] = ((n % 10) + '0');
		n /= 10;
		len--;
	}
	return (str);
}
