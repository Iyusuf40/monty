#include "monty.h"
/**
 * push - adds a new item on top of stack
 * @stack: stack
 * @line_number: line of code in monty bytecode
 *
 *
 */
void push(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *item;

	item = malloc(sizeof(stack_t));
	if (!item)
	{
		if (*stack)
			free_(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	item->n = num;
	item->prev = NULL;
	item->next = *stack;
	if (*stack)
		(*stack)->prev = item;
	*stack = item;
}
