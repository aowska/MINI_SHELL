/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:44:35 by aelsetih          #+#    #+#             */
/*   Updated: 2024/05/14 11:45:34 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (const char *)src;
	if (d < s)
	{
		while (num--)
			*d++ = *s++;
	}
	else
	{
		d += num - 1;
		s += num -1;
		while (num--)
			*d-- = *s--;
	}
	return (dest);
}
