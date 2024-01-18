#include "monty.h"

/**
 * mod - mod the top 2 elems in  the stack
 * @head: pointer to head node
 * @line_number: file line no
 *
 */
void mod(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	(void)head;
	if (tool->len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	if (tool->stack->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tool->stack->next->n %= tool->stack->n;
	temp = tool->stack;
	tool->stack = temp->next;
	free(temp);
	tool->len--;
}

/**
 * pchar - prints a char at top of stack
 * @head: pointer to head node
 * @line_number: file line no
*/
void pchar(stack_t **head, unsigned int line_number)
{
	int i;
	(void)head;

	if (tool->stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	for (i = 65; i <= 90; i++)
	{
		if (tool->stack->n == i)
		{
			printf("%c\n", tool->stack->n);
			return;
		}
	}

	for (i = 97; i <= 122; i++)
	{
		if (tool->stack->n == i)
		{
			printf("%c\n", tool->stack->n);
			return;
		}
	}

	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * pstr - prints string from top of the stack
 * @head: pointer to the head node
 * @line_number: file line no
*/
void pstr(stack_t **head, unsigned int line_number)
{
	(void)head;

	if (tool->stack == NULL)
		printf("\n");

	while (tool->stack)
	{
		if (tool->stack->n == 0)
			return;

		pchar(&tool->stack, line_number);
		tool->stack = tool->stack->next;
	}

}
