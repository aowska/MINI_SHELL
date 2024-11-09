/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:37:40 by aelsetih          #+#    #+#             */
/*   Updated: 2024/05/15 15:51:35 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	char		*d;
	const char	*s;

	if (dest == NULL && src == NULL)
		return (dest);
	d = (char *) dest;
	s = (const char *) src;
	while (num > 0)
	{
		*d++ = *s++;
		num--;
	}
	return (dest);
}
