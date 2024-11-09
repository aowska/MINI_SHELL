/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:26:13 by aelsetih          #+#    #+#             */
/*   Updated: 2024/05/15 11:49:06 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	if (src_len < size - dest_len)
		ft_memcpy(dest + dest_len, src, src_len + 1);
	else
	{
		ft_memcpy(dest + dest_len, src, size - dest_len -1);
		dest[size - 1] = '\0';
	}
	return (dest_len + src_len);
}
