#include "main.h"

/**
 * is_number - checks if string reps an integer
 * @s: string to be checked
 *
 * Return: 1 if successful, otherwise 0
 */
int is_number(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (i == 0 && s[i] == '-' && s[i + 1])
		{
			i++;
			continue;
		}
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}


/**
 * close_file - closes a file
*/
void close_file(void)
{
	if (tool->fp == NULL)
		return;

	fclose(tool->fp);
	tool->fp = NULL;
}
