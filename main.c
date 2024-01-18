#include "monty.h"

tools_t *tool = NULL;

/**
 * main - main function
 * @ac: no of args
 * @av: array of args
 *
 * Return: 0 if successful
 */
int main(int ac, char **av)
{
	size_t n = 0;

	if (ac != 2)
		usage_error();

	init_tools();
	stream(av[1]);

	while (getline(&tool->lineptr, &n, tool->fp) != -1)
	{
		tool->line_number++;
		tokenize();
		get_instruct_func();
		execute();
		free_token();
	}
	close_file();
	free_tools();

	return (0);
}
