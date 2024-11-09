/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fft_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:56:37 by aelsetih          #+#    #+#             */
/*   Updated: 2024/10/28 19:56:41 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_shell.h"

static void	count_string(const char *str, int *i)
{
	int	len;
	int	quot;

	quot = -1;
	len = 0;
	while (str[len])
	{
		while (str[len] && 
			(str[len] == 32 || (str[len] >= 9 && str[len] <= 13)))
			len++;
		while (str[len] && ((str[len] != 32 
					&& !(str[len] >= 9 && str[len] <= 13)) || quot == 1))
		{
			if (str[len] == '"')
				quot = quot * -1;
			len++;
		}
		(*i)++;
	}
}

static void	count_char(const char *str, int *i, int *j)
{
	int	len;
	int	quot;

	quot = -1;
	len = *i;
	while (str[len] && (str[len] == 32 
			|| (str[len] >= 9 && str[len] <= 13)))
		len++;
	while (str[len] && ((str[len] != 32 
				&& !(str[len] >= 9 && str[len] <= 13)) || quot == 1))
	{
		if (str[len] == '"')
			quot = quot * -1;
		len++;
		(*j)++;
	}
}

static char	*get_string(const char *str, int *i, int *k)
{
	int		j;
	int		quot;	
	char	*temp;

	quot = -1;
	count_char(str, i, k);
	temp = (char *)malloc(sizeof(char) * ((*k) + 1));
	if (!temp)
		return (NULL);
	j = 0;
	while (str[(*i)] == 32 || (str[(*i)] >= 9 && str[(*i)] <= 13))
		(*i)++;
	while (str[(*i)] && ((str[(*i)] != 32 
				&& !(str[(*i)] >= 9 && str[(*i)] <= 13)) || quot == 1))
	{
		if (str[(*i)] == '"')
			quot = quot * -1;
		temp[j++] = str[(*i)++];
	}
	temp[j] = '\0';
	return (temp);
}

char	**fft_split(const char *str)
{
	int		len;
	int		i;
	int		count;
	int		j;
	char	**split;

	count = 0;
	count_string(str, &count);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	i = 0;
	len = 0;
	while (len < count)
	{
		j = 0;
		split[len] = get_string(str, &i, &j);
		len++;
	}
	split[len] = NULL;
	return (split);
}
