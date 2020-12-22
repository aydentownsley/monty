#include "monty.h"

/**
 * p_char - print char at top of stack/queue
 *
 * @stack: head of stack/queue
 * @line_number: current line number of monty file
 *
 * Return: void, prints character
 */

void p_char(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp;

	if (stack && *stack)
	{
		tmp = *stack;
		if (tmp->n > 0 && tmp->n <= 127)
		{
			putchar(tmp->n);
			putchar('\n');
		}
		else
			status = IN_PCHAR_EXIT;
	}
/*	hand_exit(PCHAR_EXIT, NULL, line_number); */
}

/**
 * p_str - prints a string from the top of the stack
 *
 * @stack: head of the stack/queue
 * @line_number: current line number of monty file
 *
 * Return: void, prints string
 */

void p_str(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp = *stack;

	if (stack && tmp)
	{
		while (tmp)
		{
			if (tmp->n > 0 && tmp->n <= 127)
				putchar(tmp->n);
			else if (tmp->n == 0)
				break;
			tmp = tmp->next;
		}
	}
	putchar('\n');
}
