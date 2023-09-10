#include "shell.h"

void free_tokens(char **tokens)
{
	int i;
	for (i = 0; tokens[i] != NULL; i++)
	{
		if(tokens[i] != NULL)
		{
			free(tokens[i]);
		}
		free(tokens);
	}
}
