#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the head of the stack
 * @lineNum: The number of the line currently being run
 */
void pop(stack_t **stack, unsigned int lineNum)
{
	stack_t *pitem;

	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", lineNum);
		cleanup();
		exit(EXIT_FAILURE);
	}

	pitem = *stack;

	*stack = (*stack)->next;
	free(pitem);
	if (*stack)
		(*stack)->prev = NULL;
}

/**
 * pall - Prints all items on the stack
 * @stack: Double pointer to the head of the stack
 * @lineNum: The current line numer being processed
 */
void pall(stack_t **stack, unsigned int lineNum)
{
	stack_t *item;

	(void)(lineNum);

	if (!stack)
		return;

	for (item = *stack; item; item = item->next)
		printf("%d\n", item->n);
}
