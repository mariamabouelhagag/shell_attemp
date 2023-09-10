#include "shell.h"

int main(void)
{
	pid_t pid;
	char *line;
	char **args, **status;
	int i = 0;
	while (1)
	{
		ssize_t ret = write(STDOUT_FILENO, "$ ", 2);
		if (ret == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
			line = cmd_read();
			args = split_cmd(line);
			if (args[0] != NULL)
			{
				execute_builtin(args);
			}
			pid = fork();
			
			if (pid == -1)
			{
				perror("fork");
				free_tokens(args);
				return (-1);
			}
			if (pid == 0)
			{
				status = execute_tokens(args);
			}
			else if (pid > 0)
			{
				wait(NULL);
				for(i = 0; args[i] != NULL; i++)
				{
					free(args[i]);
				}
			}
			free(args);
	}
	free(line);
	free(status);
}
