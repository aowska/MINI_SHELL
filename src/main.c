#include "../inc/mini_shell.h"

static int g_in_multiline_mode = 0;

void	signal_handler(int signum)
{
	(void)signum;
	if (g_in_multiline_mode)
	{
		ft_printf("\n");
		rl_on_new_line();
		//rl_replace_line("", 0);
		rl_redisplay();	
	}
	else
		ft_printf("\nMini_shell>> ");		
}

static int	check_quots(const char *str)
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
		return (0);
	return (1);
}

static char	*get_correct_input(const char *str)
{
	char	*temp;
	char	*new_read;
	char	*new_temp;

	temp = ft_strdup(str);
	g_in_multiline_mode = 1;
	while (check_quots(temp))
	{
		new_read = readline("> ");
		if (new_read == NULL)
		{
			ft_printf("exit\n");
			free(temp);
			return (NULL);
		}
		new_temp = ft_strjoin(temp, "\n");
		temp = ft_strjoin(new_temp, new_read);
		free (new_temp);
		free (new_read);
	}
	g_in_multiline_mode = 0;
	return (temp);
}


int	main()
{
	char			*input;
	t_cmd_shell		*cmd;


	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	cmd = init_cmd();
	while (1)
	{
		input = readline("Mini_shell>> ");
		if (input == NULL)
		{
			ft_printf("exit\n");
			free (input);
			break ;
		}
		if (check_quots(input))
		{
			input = get_correct_input(input);
			if (!input)
				break ;
		}
		cmd->argv = fft_split(input);
		handle_input(cmd);
		add_history(input);
		free (input);	
	}
	//rl_clear_history();
	return (0);
}
