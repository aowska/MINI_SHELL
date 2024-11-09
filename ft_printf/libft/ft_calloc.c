/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:23:36 by aelsetih          #+#    #+#             */
/*   Updated: 2024/05/21 14:22:12 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb && !size && SIZE_MAX / nmemb < size)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, nmemb * size);
	return (ptr);
}
