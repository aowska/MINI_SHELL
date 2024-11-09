#include "../inc/mini_shell.h"

void fd_ls(void)
{
	DIR *dirp;
	struct dirent *direntp;
	char cwd[1024];
	int i;

	i = 0;
	getcwd(cwd, sizeof(cwd));
	dirp = opendir(cwd);
	if (dirp == NULL)
	{
		printf("can't open %s", cwd);
		return ;
	}
	else
	{
		while ((direntp = readdir(dirp)) != NULL)
		{
			if (direntp->d_name[0] != '.')
			{
				printf("%s ", direntp->d_name);
				if (i > 4)
				{
					printf("\n");
					i = 0;
				}
				i++;
			}
		}
		closedir(dirp);
	}
	printf("\n");
	return ;
}