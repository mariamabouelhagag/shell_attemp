#include "shell.h"

struct Node
{
	char* token;
	struct Node* next;
};

struct Node* head = NULL;

void add_token(char* token)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->token = token;
	newNode->next = head;
	head = newNode;
}

int count_tokens()
{
	int count = 0;
	struct Node* current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
		return count;
	}
}

char **execute_tokens()
{
	char **tokens;
	char **execute_token;
	int i, a = 0, num_tokens;
	for (i = 0; tokens[i] != NULL; i++)
       	{
		add_token(tokens[i]);
	}
	num_tokens = count_tokens();
	tokens = malloc(sizeof(char*) * num_tokens);
	execute_token = malloc(sizeof(char*) * num_tokens);
	tokens = split_cmd();
	
	while(tokens[i])
	{
		execute_token = execve(tokens[i], tokens, NULL);
		i++;
		tokens = split_cmd();
	}
	struct Node* current = head;
	while (current != NULL) 
	{
		struct Node* temp = current;
		current = current->next;
		free(temp);
		execute_token[a] = NULL;
		free(tokens);
		return execute_token;
}
