#include "monty.h"

/**
 * push - adds a node to a list at the front
 * with n (integer) stored in node
 *
 * @stack: head of stack/queue (list)
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	int n;

	n = check_int();

	if (stack_queue == 0)
		add_begin(stack, n);
	else if (stack_queue == 1)
		add_end(stack, n);
}

/**
 * pop -
 *
 * @
 *
 * Return:
 */

void pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	if (stack && *stack)
		delete_begin(stack);
	else
		hand_exit(POP_EXIT, NULL);
}

/**
 * swap - swaps the top to elements of stack/queue
 *
 * @stack: head of stack/queue
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
	hand_exit(SWAP_EXIT, NULL);
}

/**
 * rot_l - top element of stack/queue becomes last
 *
 * @stack: head of stack/queue
 *
 * Return: void, mods stack/queue
 */

void rot_l(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;
	int tmp;

	if (stack == NULL || head == NULL)
		return;

	tmp = head->n;

	pop(stack, line_num);

	add_end(stack, tmp);
}

/**
 * rot_r -
 *
 * @
 *
 * Return:
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
