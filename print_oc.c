#include "monty.h"

/**
 * p_int - prints the int value from the front/top node
 *
 * @stack: head of stack/queue
 * @line_number: line of monty file
 *
 * Return:
 */

void p_int(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *cursor = *stack;

	if (cursor == NULL || stack == NULL)
		status = PINT_EXIT;

	if (cursor != NULL)
		printf("%d\n", cursor->n);
}

/**
 * p_all - prints all int values from the stack/queue
 *
 * @stack: head of stack/queue
 * @line_number: line of monty file
 *
 * Return:
 */

void p_all(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *cursor = NULL;

	if (*stack == NULL || stack == NULL)
	{
		status = PINT_EXIT;
		return;
	}
	cursor = *stack;
	while (cursor != NULL)
	{
		fprintf(stdout, "%d\n", cursor->n);
		cursor = cursor->next;
	}
}
