/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:20:02 by aelsetih          #+#    #+#             */
/*   Updated: 2024/05/21 12:59:06 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	temp;

	temp = (char) c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == temp)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == temp)
		return ((char *)&str[i]);
	return (NULL);
}
