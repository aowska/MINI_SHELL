/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resirect_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicjawacowska <alicjawacowska@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:13:05 by awacowsk          #+#    #+#             */
/*   Updated: 2024/11/09 21:16:17 by alicjawacow      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_shell.h"

void	resirect_append(t_cmd_node *input)
{
	int	file;
	//struct stat st;

	file = open(input->next->token, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (file == -1) 
		return (perror("can not create file"), (void)0);
	//if (stat(input->next->token, &st) == 0 && st.st_size > 0)
    //    write(file, " ", 1);
	while (input->prev->type == ARGUMENT)
		input = input->prev;
	while (input->type != REDIRECT_APPEND)
	{
		write(file, input->token, ft_strlen(input->token));
        write(file, " ", 1);
		input = input->next;
	}
	write(file, "\n", 1);
	close(file);
	return ;
}
