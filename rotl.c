#include "monty.h"
/**
 * rotl - adds a new item on top of stack
 * @stack: stack
 * @line_number: line of code in monty bytecode
 *
 *
 */
void rotl(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *current = *stack, *save;

	if (!current || !current->next)
		return;

	while (current->next)
		current = current->next;

	save = (*stack)->next;
	current->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = current;
	/*current->next = save->next;*/
	current->prev = NULL;
	*stack = save;
}
