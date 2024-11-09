/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:01:37 by aelsetih          #+#    #+#             */
/*   Updated: 2024/05/02 11:01:58 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int n, size_t num)
{
	unsigned char	*ptr;
	unsigned char	c;

	ptr = str;
	c = (unsigned char)n;
	while (num > 0)
	{
		*ptr = c;
		ptr++;
		num--;
	}
	return (str);
}
/*
#include <stdio.h>

int	main()
{
	unsigned char	array[8];
	int	i;

	i = 0;
	ft_memset(array, 65, 8);
	while (i < 8)
	{
		printf("%c", array[i]);
		i++;
	}
}*/
