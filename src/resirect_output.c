
#include "../inc/mini_shell.h"

void	resirect_output(t_cmd_node *input)
{
	int	file;
	//struct stat st;

	file = open(input->next->token, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1) 
		return (perror("can not create file"), (void)0);
	//if (stat(input->next->token, &st) == 0 && st.st_size > 0)
    //    write(file, " ", 1);
	while (input && input->prev->type == ARGUMENT)
		input = input->prev;
	while (input && input->type != REDIRECT_OUTPUT)
	{
		write(file, input->token, ft_strlen(input->token));
		write(file, " ", 1);
		input = input->next;
	}
	if (input && input->type == REDIRECT_OUTPUT)
		input = input->next->next;
	while (input)
	{
		write(file, input->token, ft_strlen(input->token));
		write(file, " ", 1);
		input = input->next;
	}
	return (write(file, "\n", 1), close(file), (void)0);
}
