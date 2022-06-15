#include "monty.h"
/**
 * pall - adds a new item on top of stack
 * @stack: stack
 * @line_number: line of code in monty bytecode
 *
 *
 */
void pall(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
