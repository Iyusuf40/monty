#include "monty.h"
/**
 * free - adds a new item on top of stack
 * @stack: stack
 */
void free_(stack_t *stack)
{
	stack_t *current = stack;

	while (stack)
	{
		if (stack->next)
			current = stack->next;
		else
			current = NULL;
		free(stack);
		stack = current;
	}
}
