#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct tools_s - variables used in various functions
 * @fp: file pointer
 * @lineptr: points to the line read from file
 * @line_number: file line no
 * @tok: array of tokenized string
 * @ntoks: no of tokens
 * @instruct: refers to the operation of opcode
 * @stack: head node of the stack
 * @len: length of the stack
 *
 * Description: variables that will be used
 * in the entire code to perform opcode ops
*/
typedef struct tools_s
{
	FILE *fp;
	char *lineptr;
	unsigned int line_number;
	char **tok;
	int ntoks;
	instruction_t *instruct;
	stack_t *stack;
	unsigned int len;
} tools_t;

extern tools_t *tool;

void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void divide(stack_t **head, unsigned int line_number);
void mul(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int line_number);
void pchar(stack_t **head, unsigned int line_number);
void pstr(stack_t **head, unsigned int line_number);
void rotl(stack_t **head, unsigned int line_number);
void rotr(stack_t **head, unsigned int line_number);
void malloc_error(void);
void usage_error(void);
void file_open_error(char *s);
void not_int(unsigned int line_number);
void invalid_instruction(void);
void init_tools(void);
void stream(char *filename);
void tokenize(void);
void execute(void);
int is_number(char *s);
void get_instruct_func(void);
void free_token(void);
void free_all(void);
void free_head(void);
void free_stack(stack_t *head);
void free_tools(void);
void close_file(void);

#endif
