#include "monty.h"

/**
 * add - sets the second from top element of stack to top + second and pops top
 *
 * @stack: the stack opperated on
 * @line_number: unused line_number attribute
 *
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int a;

	if (stack && top && top->next)
	{
		a = top->n;
		top = top->next;
		top->n += a;
		pop(stack, line_number);
	}
	else
		status = ADD_EXIT;
}

/**
 * sub - sets the second from top element of stack to top - second and pops top
 *
 * @stack: the stack opperated on
 * @line_number: unused line_number attribute
 *
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int a;

	if (stack && top && top->next)
	{
		a = top->n;
		top = top->next;
		top->n -= a;
		pop(stack, line_number);
	}
	else
		status = SUB_EXIT;
}

/**
 * mul - sets the second from top element of stack to top * second and pops top
 *
 * @stack: the stack opperated on
 * @line_number: unused line_number attribute
 *
 * Return: void
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int a;

	if (stack && top && top->next)
	{
		a = top->n;
		top = top->next;
		top->n *= a;
		pop(stack, line_number);
	}
	else
		status = MUL_EXIT;
}

/**
 * divi - sets the second from top element of stack to top / second and pops top
 *
 * @stack: the stack opperated on
 * @line_number: unused line_number attribute
 *
 * Return: void
 */

void divi(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int a;

	if (stack && top && top->next)
	{
		a = top->n;
		top = top->next;
		if (top->n == 0)
		{
			status = DIV_0_EXIT;
			break;
		}
		top->n = top->n / a;
		pop(stack, line_number);
	}
	else
		status = DIV_EXIT;
}

/**
 * mod - sets the second from top element of stack to top % second and pops top
 *
 * @stack: the stack opperated on
 * @line_number: unused line_number attribute
 *
 * Return: void
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int a;

	if (stack && top && top->next)
	{
		a = top->n;
		top = top->next;
		top->n %= a;
		pop(stack, line_number);
	}
	else
		status = MOD_EXIT;
}
