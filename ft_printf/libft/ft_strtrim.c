/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:37:28 by aelsetih          #+#    #+#             */
/*   Updated: 2024/05/21 12:26:05 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*new(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	if (len <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trim;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup (s1));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && trim(set, s1[start]))
		start++;
	while (end > start && trim(set, s1[end - 1]))
		end--;
	str_trim = new(s1, start, end - start);
	return (str_trim);
}
