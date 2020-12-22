#include "monty.h"

/**
 * push - adds a node to a list at the front
 * with n (integer) stored in node
 *
 * @stack: head of stack/queue (list)
 * @line_number: line number of monty file
 *
 * Return: void
 */

void push(stack_t **stack __attribute__((unused)),
unsigned int line_number __attribute__((unused)))
{
	return;
}

/**
 * pop - removes top/front of stack/queue
 *
 * @stack: head of stack/queue
 * @line_number: line number of monty file
 *
 * Return:
 */

void pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	if (*stack)
	{
		*stack = delete_begin(stack);
	}
	else
	{
		status = POP_EXIT;
	}
}

/**
 * swap - swaps the top to elements of stack/queue
 *
 * @stack: head of stack/queue
 * @line_number: line number of monty file
 *
 * Return: void, change stack
 */

void swap(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack, *headnext = *stack;
	int tmp;

	if (stack && head && head->next)
	{
		headnext = head->next;
		tmp = head->n;
		head->n = headnext->n;
		headnext->n = tmp;
	}
	else
		status = SWAP_EXIT;
}

/**
 * rot_l - top element of stack/queue becomes last
 *
 * @stack: head of stack/queue
 * @line_number: line number of monty file
 *
 * Return: void, mods stack/queue
 */

void rot_l(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int tmp;

	if (stack == NULL || head == NULL)
		return;

	tmp = head->n;

	pop(stack, line_number);

	add_end(stack, tmp);
}

/**
 * rot_r - takes head and moves to tail
 *
 * @stack: head of stack/queue
 * @line_number: line number of monty file
 *
 * Return: void, change stack
 */

void rot_r(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tail = *stack;
	int tmp;

	if (stack == NULL || tail == NULL)
		return;

	while (tail->next)
		tail = tail->next;

	tmp = tail->n;

	delete_end(stack);

	add_begin(stack, tmp);
}
