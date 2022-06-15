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
	int stack_or_que = 1;
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
		{"queue", nop},
		{"stack", nop},
		{NULL, NULL}
	};

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(av[1], "r");
	if (!stream)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
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
		if (!strcmp(p_argv[0], "stack"))
			stack_or_que = 1;
		else if (!strcmp(p_argv[0], "queue"))
			stack_or_que = 2;
		if (p_argv[1])
			num = atoi(p_argv[1]);
		for (i = 0; arr[i].opcode; i++)
		{
			if (p_argv[0][0] == '#')
				break;
			if (!strcmp((arr[i]).opcode, p_argv[0]))
			{
				if (!strcmp(p_argv[0], "push"))
				{
					if (stack_or_que == 1)
						push(&head, line_number);
					else
						push_end(&head, line_number);
					break;
				}
				(arr[i]).f(&head, line_number);
				break;
			}
		}
		if (i == (sizeof(arr) / sizeof(instruction_t)) - 1)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, p_argv[0]);
			if (head)
				free_(head);
			fclose(stream);
			exit(EXIT_FAILURE);
		}
		line_number++;
		free(line);
		line = NULL;
	}
	if (head)
		free_(head);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
