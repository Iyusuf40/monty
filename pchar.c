#include "monty.h"
/**
 * pchar - pops the top item on stack
 * @stack: stack
 * @line_number: line of code in monty bytecode
 *
 *
 */
void pchar(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		/*exit(EXIT_FAILURE);*/
		num = -1;
		return;
	}

	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		free_(*stack);
		num = -1;
		return;
		/*exit(EXIT_FAILURE);*/
	}

	putchar((*stack)->n);
	putchar('\n');
}
