#include "main.h"

/**
 * init_tools - allocates space for the tools
*/
void init_tools(void)
{
	tool = malloc(sizeof(tools_t));
	if (tool == NULL)
		malloc_error();

	tool->instruct = malloc(sizeof(instruction_t));
	if (tool->instruct == NULL)
		malloc_error();

	tool->fp = NULL;
	tool->lineptr = NULL;
	tool->line_number = 0;
	tool->ntoks = 0;
	tool->stack = NULL;
	tool->len = 0;
}

/**
 * stream - gets the stream
 * @filename: name of the file
*/
void stream(char *filename)
{
	tool->fp = fopen(filename, "r");
	if (tool->fp == NULL)
		file_open_error(filename);
}

/**
 * tokenize - tokenizes a string
*/
void tokenize(void)
{
	int i = 0;
	char *token, *lineptr_cpy, *delim;

	delim = " \n";

	lineptr_cpy = malloc(sizeof(char) * (strlen(tool->lineptr) + 1));
	if (lineptr_cpy == NULL)
		malloc_error();

	strcpy(lineptr_cpy, tool->lineptr);
	tool->ntoks = 0;
	token = strtok(lineptr_cpy, delim);
	while (token)
	{
		tool->ntoks++;
		token = strtok(NULL, delim);
	}

	tool->tok = malloc(sizeof(char *) * (tool->ntoks + 1));
	strcpy(lineptr_cpy, tool->lineptr);
	token = strtok(lineptr_cpy, delim);
	while (token)
	{
		tool->tok[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (tool->tok[i] == NULL)
			malloc_error();

		strcpy(tool->tok[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	tool->tok[i] = NULL;
	free(lineptr_cpy);
}

/**
 * get_instruct_func - gets the instruction to perform
 */
void get_instruct_func(void)
{
	int i = 0;
	instruction_t op[] = {
		{"push", &push},
		{"pall", &pall},
		{"pint", &pint},
		{"pop", &pop},
		{"swap", &swap},
		{"add", &add},
		{"nop", &nop},
		{"sub", &sub},
		{"div", &divide},
		{"mul", &mul},
		{"mod", &mod},
		{NULL, NULL}
	};

	if (tool->ntoks == 0)
		return;

	while (op[i].opcode != NULL)
	{
		if (strcmp(tool->tok[0], op[i].opcode) == 0)
		{
			tool->instruct->opcode = op[i].opcode;
			tool->instruct->f = op[i].f;
			return;
		}
		i++;
	}
	invalid_instruction();
}

/**
 * execute - executes the opcode
 */
void execute(void)
{
	stack_t *head = NULL;

	if (tool->tok == 0)
		return;

	tool->instruct->f(&head, tool->line_number);
}
