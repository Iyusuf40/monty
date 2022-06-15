#include "monty.h"
/**
 * add - swaps items on top of stack
 * @stack: stack
 * @line_number: line of code in monty bytecode
 *
 *
 */
void add(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *save = *stack;

	if (!((*stack)->next))
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	((*stack)->next)->n = (*stack)->n + ((*stack)->next)->n;
	*stack = (*stack)->next;
	free(save);
}
