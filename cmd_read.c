#include "shell.h"

char* cmd_read()
{
	char *cmd = NULL;
	size_t n = 0;
	int i, value;
	
	value = getline(&cmd, &n, stdin);
	if (value == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(cmd);
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
		else
		{
			while (cmd[i])
			{
				if (cmd[i] == '\n')
				{
					cmd[i] = 0;
				}
				i ++;
			}
		}
		return(cmd);
	}

