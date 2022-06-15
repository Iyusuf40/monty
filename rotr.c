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
	stack_t *current = *stack, *save, *prev;

	if (!current || !current->next)
		return;

	while (current->next)
	{
		prev = current->prev;
		save = current->next;
		current->next = prev;
		if (prev)
			prev->prev = current;
		current->prev = current->next;
		current = save;
	}
	current->prev = NULL;
	current->next = prev->prev;
	*stack = current;
}
