#include "../inc/mini_shell.h"

void	signal_handler(int signum)
{
	(void)signum;
	ft_printf("\nMini_shell>> ");		
}

static int	check_double_quots(const char *str)
{
	int	quots;
	int	i;

	quots = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
			quots++;
		i++;
	}
	if (quots % 2 == 0)
		return (1);
	printf("Error: unclosed double quote\n");		
	return (0);
}

static int	check_single_quots(const char *str)
{
	int	quots;
	int	i;

	quots = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			quots++;
		i++;
	}
	if (quots % 2 == 0)
		return (1);
	printf("Error: unclosed single quote\n");
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_cmd_shell	*cmd;
	//int	i;

	if (argc != 1)
	{
		printf("Error: only the %s with no other arguments\n", argv[0]);
		return (0);
	}
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	cmd = init_cmd(envp);
	while (1)
	{
		input = readline("Mini_shell>> ");
		if (input == NULL)
		{
			printf("exit\n");
			free (input);
			break ;
		}
		if (check_double_quots(input) && check_single_quots(input))
		{
			if (input[0] != '\0')
			{
				cmd->argv = fft_split(input);
				add_history(input);				
				free (input);
				/*i = 0;
				while (cmd->env[i])
				{
					ft_printf("%s\n", cmd->env[i]);
					i++;
				}*/
				handle_input(cmd);
						
					
			}
		}
		if (cmd->node != NULL)
		{
			free_cmd_node(cmd->node);
			cmd->node = NULL;	
		}			
	}
	
	rl_clear_history();
	return (0);
}