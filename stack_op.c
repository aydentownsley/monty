#include "monty.h"

/**
 * push - adds a node to a list at the front
 * with n (integer) stored in node
 *
 * @stack: head of stack/queue (list)
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
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

void pop(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack)
		delete_begin(stack);
	else
		hand_exit(POP_EXIT, NULL);
}

/**
 * swap -
 *
 * @
 *
 * Return:
 */

void swap(stack_t **stack, unsigned int line_number)
{

}

/**
 * rot_l -
 *
 * @
 *
 * Return:
 */

void rot_l(stack_t **stack, unsigned int line_number)
{

}

/**
 * rot_r -
 *
 * @
 *
 * Return:
 */

void rot_r(stack_t **stack, unsigned int line_number)
{

}
