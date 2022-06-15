#include "monty.h"
/**
 * rotr - adds a new item on top of stack
 * @stack: stack
 * @line_number: line of code in monty bytecode
 *
 *
 */
void rotr(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *current = *stack, *save = *stack;

	if (!current || !current->next)
		return;

	while (current->next)
	{
		current = current->next;
	}
	
	(current->prev)->next = NULL;
	current->prev = NULL;
	current->next = *stack;
	save->prev = current;
	*stack = current;
}
