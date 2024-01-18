#include "main.h"

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
