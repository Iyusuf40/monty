#include "monty.h"
/**
 * swap - swaps items on top of stack
 * @stack: stack
 * @line_number: line of code in monty bytecode
 *
 *
 */
void swap(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *save;

	if (!((*stack)->next))
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	save = *stack;
	*stack = (*stack)->next;
	save->next = (*stack)->next;
	save->prev = *stack;
	(*stack)->prev = NULL;
	(*stack)->next = save;
}
