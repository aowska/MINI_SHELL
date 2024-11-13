
#include "../inc/mini_shell.h"

void	heredoc(t_cmd_node *input)
{
	/*int		file;

	if (!(input->next))
		return(printf("bash: syntax error near unexpected token `newline'\n"), (void)0);
	file = open(input->next->token, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (file == -1 )
		return (perror("can not create file"), (void)0);
	while (input && input->prev->type == ARGUMENT)
		input = input->prev;
	while (input && input->type != REDIRECT_APPEND)
	{
		write(file, input->token, ft_strlen(input->token));
		write(file, " ", 1);
		input = input->next;
	}
	if (input && input->type == REDIRECT_APPEND)
		input = input->next->next;
	while (input)
	{
		write(file, input->token, ft_strlen(input->token));
		write(file, " ", 1);
		input = input->next;
	}
	return (write(file, "\n", 1), close(file), (void)0);*/
}
