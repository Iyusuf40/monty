#include "monty.h"
/**
 * div - subtracts top of stack n filed from the seconf
 * @stack: stack
 * @line_number: line of code in monty bytecode
 *
 *
 */
void _div(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *save = *stack;

	if (!*stack || !((*stack)->next))
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	((*stack)->next)->n = ((*stack)->next)->n / (*stack)->n;
	*stack = (*stack)->next;
	free(save);
}
