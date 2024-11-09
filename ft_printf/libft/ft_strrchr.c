/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:46:00 by aelsetih          #+#    #+#             */
/*   Updated: 2024/05/21 13:59:15 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*occ;
	int		i;

	i = 0;
	occ = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			occ = (char *)&s[i];
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return ((char *)occ);
}
