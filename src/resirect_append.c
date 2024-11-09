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

	file = open(input->next->token, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
	{
		perror("can not create file");
		return ;
	}
	while (input->prev->type == ARGUMENT)
	{
		input = input->prev;
	}
	while (input->type != REDIRECT_APPEND)
	{
		write(file, input->token, ft_strlen(input->token));
        write(file, " ", 1);
		input = input->next;
	}
	close(file);
	return ;
}
