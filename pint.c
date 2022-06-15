#include "monty.h"
/**
 * pint - peeps on the stack
 * @stack: stack
 * @line_number: line of code in monty bytecode
 *
 *
 */
void pint(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);

}
