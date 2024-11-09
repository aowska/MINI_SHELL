/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resirect_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-09 15:13:05 by awacowsk          #+#    #+#             */
/*   Updated: 2024-11-09 15:13:05 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_shell.h"

void	save_in_file(t_cmd_node *input)
{
	int	file;

	write(1, input->token, 1);
	file = open(input->next->token, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
	{
		perror("can not create file");
		return (1);
	}
	/*while (args[j])
	{
		if (!(ft_strstr(args[j], ">>")) && j != i)
		{
			check_parag(&args[j]);
			write(file, args[j], ft_strlen(args[j]));
			write(file, " ", 1);
		}
		j++;
	}*/
	close(file);
	return (0);
}
