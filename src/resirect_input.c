/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicjawacowska <alicjawacowska@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:41:22 by alicjawacow       #+#    #+#             */
/*   Updated: 2024/11/10 20:53:33 by alicjawacow      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_shell.h"

void	resirect_input(t_cmd_node *input)
{
	int		file;
	int		i;
	char	*temp;

	i = 0;
	if (!(input->next))
		return(printf("bash: syntax error near unexpected token `newline'\n"), (void)0);
	file = open(input->next->token, O_RDONLY);
	if (file == -1) 
		return (perror("can not create file"), (void)0);
	while (i++ < 2000)
	{
		temp = NULL;
		temp = get_next_line(file);
		if (!temp)
			break ;
		printf("%s", temp);
		fflush(0);
		free(temp);
	}
	close(file);
	return ;
}
