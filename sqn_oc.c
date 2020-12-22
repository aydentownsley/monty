#include "monty.h"

/**
 * nop - do nothing
 *
 * @stack: the pointer to the head of the stack;
 * @line_number: current line number
 *
 * Return: void
 */

void nop(stack_t **stack __attribute__ ((unused)),
unsigned int line_number __attribute__ ((unused)))
{}

/**
 * stackf - handle list as stack
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
 * queue - handle list as queue
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
