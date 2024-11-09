/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:33:01 by aelsetih          #+#    #+#             */
/*   Updated: 2024/05/15 15:14:25 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	size_t	len;

	len = 0;
	dest = (char *)malloc(ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	while (str[len])
	{
		dest[len] = str[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}
