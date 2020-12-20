#ifndef MONTY_H
#define MONTY_H

/*____ INCLUDES ____*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>

/*____ MACROS ____*/

#define STACK (0)
#define QUEUE (1)
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

/*____ GLOBAL VARIABLES ____*/

extern unsigned int line_num;
extern int stack_queue;
extern char *buffer;
extern unsigned int file_pos;

/*____ PROTOTYPES _____*/

size_t get_size(FILE *fp);
void open_and_read(char *file);
int main(int argc, char *argv[]);
void check_op(stack_t **stack);
void null_comp(char *oc);
int check_int(void);
void hand_exit(int ex, char *str);
void push(stack_t **stack, unsigned int line_number __attribute__((unused)));
void pop(stack_t **stack, unsigned int line_number __attribute__((unused)));
void swap(stack_t **stack, unsigned int line_numbe __attribute__((unused)));
void rot_l(stack_t **stack, unsigned int line_number __attribute__((unused)));
void rot_r(stack_t **stack, unsigned int line_number __attribute__((unused)));
void p_int(stack_t **stack, unsigned int line_number __attribute__((unused)));
void p_all(stack_t **stack, unsigned int line_number __attribute__((unused)));
void p_char(stack_t **stack, unsigned int line_number __attribute__((unused)));
void p_str(stack_t **stack, unsigned int line_number __attribute__((unused)));
void add(stack_t **stack, unsigned int line_number __attribute__((unused)));
void sub(stack_t **stack, unsigned int line_number __attribute__((unused)));
void mul(stack_t **stack, unsigned int line_number __attribute__((unused)));
void divi(stack_t **stack, unsigned int line_number __attribute__((unused)));
void mod(stack_t **stack, unsigned int line_number __attribute__((unused)));
stack_t *add_begin(stack_t **stack, const int n);
stack_t *add_end(stack_t **stack, const int n);
void delete_begin(stack_t **stack);
void delete_end(stack_t **stack);
void free_stack(stack_t *stack);

#endif /* MONTY_H */
