#include "monty.h"
/**
 * pop - pops the top item on stack
 * @stack: stack
 * @line_number: line of code in monty bytecode
 *
 *
 */
void pop(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *save = *stack;

	if (!*stack)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(save);
}
