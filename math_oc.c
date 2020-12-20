#include "monty.h"

/**
 * add - sets the second from top element of stack to top + second and pops top
 *
 * @stack: the stack opperated on
 * @line_number: unused line_number attribute
 *
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *top = *stack;
	int a;

	if (stack && top && top->next)
	{
		a = top->n;
		top = top->next;
		top->n += a;
		pop(stack, line_num);
	}
	else
		hand_exit(ADD_EXIT, NULL);
}

/**
 * sub - sets the second from top element of stack to top - second and pops top
 *
 * @stack: the stack opperated on
 * @line_number: unused line_number attribute
 *
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *top = *stack;
	int a;

	if (stack && top && top->next)
	{
		a = top->n;
		top = top->next;
		top->n -= a;
		pop(stack, line_num);
	}
	else
		hand_exit(SUB_EXIT, NULL);
}

/**
 * mul - sets the second from top element of stack to top * second and pops top
 *
 * @stack: the stack opperated on
 * @line_number: unused line_number attribute
 *
 * Return: void
 */

void mul(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *top = *stack;
	int a;

	if (stack && top && top->next)
	{
		a = top->n;
		top = top->next;
		top->n *= a;
		pop(stack, line_num);
	}
	else
		hand_exit(MUL_EXIT, NULL);
}

/**
 * divi - sets the second from top element of stack to top / second and pops top
 *
 * @stack: the stack opperated on
 * @line_number: unused line_number attribute
 *
 * Return: void
 */

void divi(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *top = *stack;
	int a;

	if (stack && top && top->next)
	{
		a = top->n;
		top = top->next;
		if (top->n == 0)
			hand_exit(DIV_0_EXIT, NULL);
		top->n = top->n / a;
		pop(stack, line_num);
	}
	else
		hand_exit(DIV_EXIT, NULL);
}

/**
 * mod - sets the second from top element of stack to top % second and pops top
 *
 * @stack: the stack opperated on
 * @line_number: unused line_number attribute
 *
 * Return: void
 */

void mod(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *top = *stack;
	int a;

	if (stack && top && top->next)
	{
		a = top->n;
		top = top->next;
		top->n %= a;
		pop(stack, line_num);
	}
	else
		hand_exit(MOD_EXIT, NULL);
}
