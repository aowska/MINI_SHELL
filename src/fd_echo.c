/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicjawacowska <alicjawacowska@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:13:13 by awacowsk          #+#    #+#             */
/*   Updated: 2024/11/10 21:03:49 by alicjawacow      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_shell.h"

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
}

int fd_echo(t_cmd_node *input)
{
	t_cmd_node *temp;

	temp = input;
	if (!input)
		return (1);
	while (temp)
	{
		if (temp->type == REDIRECT_APPEND)
			return (resirect_append(temp), 0);
		else if (temp->type == REDIRECT_OUTPUT)
			return (resirect_output(temp), 0);
		else if(temp->type == REDIRECT_INPUT)
			return (printf("\n"), 0);
		else if (temp->type == VARIABLE)
			return(fd_variable(temp));
		temp = temp->next;
	}
	input = input->next;
	while (input)
	{
		check_parag(&input->token);
		printf("%s ", input->token);
		input = input->next;
	}
	printf("\n");
	return (0);
}

/*		else if(temp->type == REDIRECT_INPUT)
			return (resirect_input(temp), 0);*/