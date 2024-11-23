
#include "../inc/mini_shell.h"

char *ft_strjoin_with_newline(char *s1, char *s2) {
    if (!s2) return s1 ? strdup(s1) : NULL; // If s2 is NULL, just duplicate s1
    if (!s1) {
        // Allocate space for s2 and a newline
        char *new_str = malloc(strlen(s2) + 2); // +1 for newline, +1 for null terminator
        if (!new_str) return NULL;
        strcpy(new_str, s2);
        strcat(new_str, "\n");
        return new_str;
    }

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char *new_str = malloc(len1 + len2 + 2); // +1 for newline, +1 for null terminator
    if (!new_str) return NULL;

    strcpy(new_str, s1);
    strcat(new_str, s2);
    strcat(new_str, "\n"); // Add newline at the end

    return new_str;
}


char *heredoc(t_cmd_node *input)
{
	char *delimiter = NULL;
	char *str_delimiter = NULL;
	char *new_str = NULL;

	check_parag(&(input->next->token));
	while (1)
	{
		delimiter = readline("> ");
		if (delimiter == NULL)
		{
			printf("exit\n");
			free(input);
			break;
		}
		if (strcmp(input->next->token, delimiter) == 0)
		{
			free(delimiter);
			break;
		}
		new_str = ft_strjoin_with_newline(str_delimiter, delimiter);
		//printf("%s", new_str);
		free(str_delimiter);
		str_delimiter = new_str;
		free(delimiter);
	}
	//printf("%s", new_str);
	return (new_str);
}
