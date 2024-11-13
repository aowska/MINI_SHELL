
#include "../inc/mini_shell.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	fd_variable(t_cmd_node *input, char **env, int no_newline)
{
	const char	*var_name;
	int			i;
	size_t		len;

	i = 0;
	var_name = input->token + 1;
	while (env[i])
	{
		len = ft_strlen(var_name);
		if (ft_strncmp(env[i], var_name, len) == 0 && env[i][len] == '=')
			return (printf("%s", env[i] + len + 1), (void)0);
		i++;
	}
	if (!no_newline)
		printf("\n");
}
