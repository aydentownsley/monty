#include "monty.h"

/**
 * add_begin - add node to beginnig of stack/queue
 *
 * @stack: head of list
 * @n: int in new node
 *
 * Return: address of new node
 * OR EXIT STATUS
 */

stack_t *add_begin(stack_t **stack, const int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new;
	new->next = *stack;
	*stack = new;

	return (new);
}

/**
 * add_end - add node to end of stack/queue
 *
 * @stack: head of list
 * @n: int in new node
 *
 * Return: address of new node
 * OR EXIT STATUS
 */

stack_t *add_end(stack_t **stack, const int n)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*stack == NULL)
	{
		*stack = new;
	}
	else
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		new->prev = temp;
		temp->next = new;
	}

	return (new);
}

/**
 * delete_begin - delete node at beginning of stack/queue
 *
 * @stack: head of list
 * @n: int in new node
 *
 * Return: int value of node
 * OR EXIT STATUS
 */

void delete_begin(stack_t **stack)
{
	stack_t *curr = *stack;

	if (!stack|| !(*stack))
		status = POP_EXIT;

	*stack = curr->next;
	curr->next->prev = NULL;

	free(curr);
}

/**
 * delete_end - delete node at end of stack/queue
 *
 * @stack: head of list
 * @n: int in new node
 *
 * Return: int value of node
 * OR EXIT STATUS
 */

void delete_end(stack_t **stack)
{
        stack_t *curr = *stack;

        if (!stack || !(*stack))
                return;

	while (curr->next != NULL)
		curr = curr->next;

	curr->prev->next = NULL;

        free(curr);
}

/**
 * free_stack - frees a stack/queue
 *
 * @stack: head of stack
 *
 * Return: VOID
 */

void free_stack(stack_t *stack)
{
	stack_t *new;

	while (stack)
	{
		new = stack->next;
		free(stack);
		stack = new;
	}
}
