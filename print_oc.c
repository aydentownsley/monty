#include "monty.h"

/**
 * p_int -
 *
 * @
 *
 * Return:
 */

void p_int(stack_t **stack, unsigned int line_number)
{
	stack_t *cursor = *stack;

	if (cursor == NULL || stack == NULL)
		hand_exit(PINT_EXIT, NULL);

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

void p_all(stack_t **stack, unsigned int line_number)
{
	stack_t *cursor = *stack;

	if (cursor == NULL || stack == NULL)
		hand_exit(PINT_EXIT, NULL);

	while (cursor != NULL)
	{
		printf("%d\n", cursor->n);
		cursor = cursor->next;
	}
}
