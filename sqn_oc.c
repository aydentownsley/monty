#include "monty.h"
/* prototypes not added yet */
/**
 * nop -
 *
 * @stack: the pointer to the head of the stack;
 * @line_number: current line number
 *
 * Return: void
 */

void nop(stack_t **stack __attribute__ ((unused)), unsigned int line_number __attribute__ ((unused)))
{
	return;
}

/**
 * stack -
 *
 * @stack: the pointer to the head of the stack;
 * @line_number: current line number
 *
 * Return: void
 */

void stackf(stack_t **stack __attribute__ ((unused)),
unsigned int line_number __attribute__ ((unused)))
{
	status = STACK;
}

/**
 * queue -
 *
 * @stack: the pointer to the head of the stack;
 * @line_number: current line number
 *
 * Return: void
 */

void queue(stack_t **stack __attribute__ ((unused)),
unsigned int line_number __attribute__ ((unused)))
{
	status = QUEUE;
}
