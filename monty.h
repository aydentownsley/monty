#ifndef MONTY_H
#define MONTY_H

#define Stack (0)
#define Queue (1)

extern size_t line_num;
extern stack_t **head;
extern size_t ex_stat;
extern int stack_queue;

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

void push(stack_t **stack, unsigned int line_number):
void pop(stack_t **stack, unsigned int line_number):
void swap(stack_t **stack, unsigned int line_number):
void rot_l(stack_t **stack, unsigned int line_number):
void rot_r(stack_t **stack, unsigned int line_number):
void p_int(stack_t **stack, unsigned int line_number):
void p_all(stack_t **stack, unsigned int line_number):
void p_char(stack_t **stack, unsigned int line_number):
void p_str(stack_t **stack, unsigned int line_number):
void add(stack_t **stack, unsigned int line_number):
void sub(stack_t **stack, unsigned int line_number):
void mul(stack_t **stack, unsigned int line_number):
void div(stack_t **stack, unsigned int line_number):
void mod(stack_t **stack, unsigned int line_number):

#endif /* MONTY_H */
