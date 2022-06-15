#include "monty.h"
/**
 * main - main function of monty interpreter
 * @ac: argument count
 * @av: argument vector
 *
 * Return: EXIT_[SUCCESS, FAILURE]
 */
int num;
int main(int ac, char **av)
{
	ssize_t gl;
	size_t h = 20;
	unsigned int line_number = 1, i = 0;
	char *line = NULL;
	FILE *stream;
	const char *dl = "	 \n";
	char *p_argv[20];
	stack_t *head = NULL;
	instruction_t arr[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"nop", nop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(av[1], "r");
	if (!stream)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		gl = getline(&line, &h, stream);
		if (gl == -1)
		{
			free(line);
			break;
		}
		remove_new_line(line);
		make_array(line, dl, p_argv);
		if (p_argv[1])
			num = atoi(p_argv[1]);
		for (i = 0; arr[i].opcode; i++)
		{
			if (p_argv[0][0] == '#')
				break;
			if (!strcmp((arr[i]).opcode, p_argv[0]))
			{
				(arr[i]).f(&head, line_number);
				break;
			}
		}
		if (i == (sizeof(arr) / sizeof(instruction_t)) - 1)
		{
			dprintf(2, "L%u: unknown instruction %s\n", line_number, p_argv[0]);
			exit(EXIT_FAILURE);
		}
		line_number++;
		free(line);
		line = NULL;
	}
	fclose(stream);
	exit(EXIT_SUCCESS);
}
