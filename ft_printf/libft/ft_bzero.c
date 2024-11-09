/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:15:02 by aelsetih          #+#    #+#             */
/*   Updated: 2024/05/14 11:23:37 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ar, size_t num)
{
	unsigned char	*ptr;

	ptr = ar;
	while (num > 0)
	{
		*ptr = 0;
		ptr++;
		num--;
	}
}
