#include "main.h"

/**
 * push - pushes element to the stack
 * @head: pointer to the head node
 * @line_number: file line no
 *
 */
void push(stack_t **head, unsigned int line_number)
{
	if (tool->ntoks <= 1 || !(is_number(tool->tok[1])))
	{
		free_tools();
		not_int(line_number);
	}

	*head = malloc(sizeof(stack_t));
	if (*head == NULL)
		malloc_error();

	(*head)->next = (*head)->prev = NULL;
	(*head)->n = (int)atoi(tool->tok[1]);

	if (tool->stack)
	{
		(*head)->next = tool->stack;
		tool->stack->prev = *head;
	}
	tool->stack = *head;
	tool->len++;
}

/**
 * pall - prints the values on a stack
 * @head: pointer to the head node
 * @line_number: file line no
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	(void)head;

	if (tool->stack == NULL)
		return;

	temp = tool->stack;

	if (temp)
	{
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}

/**
 * pint - prints value at the top of stack
 * @head: pointer to top node
 * @line_number: file line no
 */
void pint(stack_t **head, unsigned int line_number)
{
	(void)head;

	if (tool->stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", tool->stack->n);
}

/**
 * pop - removes element at top of stack
 * @head: pointer to head node
 * @line_number: file line no
*/
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	(void)head;
	if (tool->stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	temp = tool->stack;
	tool->stack = temp->next;
	free(temp);
	tool->len--;
}

/**
 * swap - swaps the top 2 elems in  the stack
 * @head: pointer to the head node
 * @line_number: file line no
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	(void)head;
	if (tool->len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = tool->stack->next;
	tool->stack->next = temp->next;
	tool->stack->prev = temp;
	temp->next = tool->stack;
	temp->prev = NULL;
	if (tool->len > 2)
		tool->stack->next->prev = tool->stack;
	tool->stack = temp;
}
