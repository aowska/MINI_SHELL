/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicjawacowska <alicjawacowska@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:13:13 by awacowsk          #+#    #+#             */
/*   Updated: 2024/11/09 21:15:23 by alicjawacow      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_shell.h"
/*
void check_parag(char **args)
{
	char *start_quote;
	char *end_quote;

	if (*args && **args == '"')
	{
		start_quote = ft_strchr(*args, '"');
		if (start_quote)
			ft_memmove(start_quote, start_quote + 1, ft_strlen(start_quote));
		end_quote = ft_strrchr(*args, '"');
		if (end_quote)
			*end_quote = '\0';
	}
}*/

int fd_echo(t_cmd_node *input)
{
	t_cmd_node *temp;

	temp = input;
	if (!input)
		return (1);
	while (temp)
	{
		if (temp->type == REDIRECT_APPEND)
			resirect_append(temp);
		else if (temp->type == REDIRECT_OUTPUT)
			resirect_output(temp);
		temp = temp->next;
	}
	
	while (input)
	{
		//check_parag(&input->token);
		printf("%s ", input->token);
		input = input->next;
	}
	printf("\n");
	return (0);
}
