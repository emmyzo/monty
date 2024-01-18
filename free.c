#include "main.h"

/**
 * free_token - frees the token array
 */
void free_token(void)
{
	int i = 0;

	if (tool->tok == NULL)
		return;

	while (tool->tok[i])
	{
		free(tool->tok[i]);
		i++;
	}
	free(tool->tok);
	tool->tok = NULL;
}

/**
 * free_head - frees a list
 */
void free_head(void)
{
	if (tool->stack)
		free_stack(tool->stack);
}

/**
 * free_stack - frees nodes of the stack
 * @head: head node
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;

	if (head->next)
		free_stack(head->next);

	free(head);
}

/**
 * free_tools - frees tool struct
 */
void free_tools(void)
{
	if (tool == NULL)
		return;

	if (tool->instruct)
		free(tool->instruct);

	free_head();

	if (tool->lineptr)
		free(tool->lineptr);

	free(tool);
}

/**
 * free_all - frees token and tools list
 */
void free_all(void)
{
	close_file();
	free_token();
	free_tools();
}
