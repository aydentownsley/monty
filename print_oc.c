#include "monty.h"

/**
 * p_int -
 *
 * @
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
 * p_all -
 *
 * @
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
		printf("%d\n", cursor->n);
		cursor = cursor->next;
	}
}
