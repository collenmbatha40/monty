#include "monty.h"

/**
 * pint - Prints the int at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @lineNum: The number of the current line being processed
 */
void pint(stack_t **stack, unsigned int lineNum)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", lineNum);
		cleanup();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * push - Pushes an item to the top of the stack
 * @num: The number to push
 */
void push(char *num)
{
	if (num == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", gvar.lineNum);
		cleanup();
		exit(EXIT_FAILURE);
	}

	checkNum(num);

	pushInt(atoi(num));
}

/**
 * pushInt - pushes an int to the top of the stack
 * @n: The number to be pushed
 */
void pushInt(int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *tmp = gvar.stack;

	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		cleanup();
		exit(EXIT_FAILURE);
	}

	new->n = n;

	if (!gvar.stack)
	{
		new->next = NULL;
		new->prev = NULL;
		gvar.stack = new;
	}
	else
	{
		if (gvar.isStack)
		{
			new->next = gvar.stack;
			new->prev = NULL;
			gvar.stack->prev = new;
			gvar.stack = new;
		}
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
			new->prev = tmp;
			new->next = NULL;
		}
	}
}

/**
 * checkNum - checks if a string is a valid number
 * @num: The string to check
 */
void checkNum(char *num)
{
	int i = 0;

	if (num[0] == '-')
		i++;

	for (; num[i]; ++i)
	{
		if (!isdigit(num[i]))
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
					gvar.lineNum);
			cleanup();
			exit(EXIT_FAILURE);
		}
	}
}
