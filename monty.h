#ifndef MONTY_H
#define MONTY_H

/*____ INCLUDES ____*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

/*____ MACROS ____*/

#define MALLOC_EXIT (0)
#define OP_EXIT (1)
#define OPEN_EXIT (2)
#define ARG_EXIT (3)
#define PUSH_INT_EXIT (4)
#define PINT_EXIT (5)
#define POP_EXIT (6)
#define SWAP_EXIT (7)
#define ADD_EXIT (8)
#define SUB_EXIT (9)
#define MUL_EXIT (10)
#define DIV_EXIT (11)
#define DIV_0_EXIT (12)
#define MOD_EXIT (13)
#define IN_PCHAR_EXIT (14)
#define PCHAR_EXIT (15)
#define STACK (16)
#define QUEUE (17)

/*____ GLOBAL VARIABLES ____*/

extern int status;

/*____ STRUCTURES ____*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*____ PROTOTYPES _____*/

void (*check_op(char *buffer))(stack_t **stack, unsigned int line_number);
int check_int(char *buffer, stack_t **stack);
void hand_exit(char *buffer, stack_t **stack,
unsigned int line_number, FILE *fp);
void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void rot_l(stack_t **stack, unsigned int line_number);
void rot_r(stack_t **stack, unsigned int line_number);
void p_int(stack_t **stack, unsigned int line_number);
void p_all(stack_t **stack, unsigned int line_number);
void p_char(stack_t **stack, unsigned int line_number);
void p_str(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void divi(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
stack_t *add_begin(stack_t **stack, const int n);
stack_t *add_end(stack_t **stack, const int n);
stack_t *delete_begin(stack_t **stack);
void delete_end(stack_t **stack);
void free_stack(stack_t *stack);
void nop(stack_t **stack, unsigned int line_number);
void stackf(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
char *find_str(char *buffer);
void main_help(char *buffer, stack_t **stack,
unsigned int line_number, FILE *fp);
void free_exit(char *buffer, stack_t **stack, char *str, FILE *fp);

#endif /* MONTY_H */
