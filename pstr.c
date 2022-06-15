#include "monty.h"
/**
 * pstr - pops the top item on stack
 * @stack: stack
 * @line_number: line of code in monty bytecode
 *
 *
 */
void pstr(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *save = *stack;
	int n_field;

	if (!*stack)
	{
		putchar('\n');
		return;
	}

	while (save)
	{
		n_field = save->n;
		if (n_field > 127 || n_field <= 0)
		{
			putchar('\n');
			return;
		}
		putchar(n_field);
		save = save->next;
	}
	putchar('\n');
}
