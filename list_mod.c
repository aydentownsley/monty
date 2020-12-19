#include "monty.h"

/**
 * add_begin - add node to beginnig of stack/queue
 *
 * @head: head of list
 * @n: int in new node
 *
 * Return: address of new node
 * OR EXIT STATUS
 */

stack_t *add_begin(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;

	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;

	return (new);
}

/**
 * add_end - add node to end of stack/queue
 *
 * @head: head of list
 * @n: int in new node
 *
 * Return: address of new node
 * OR EXIT STATUS
 */

stack_t *add_end(stack_t **head, const int n)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		new->prev = temp;
		temp->next = new;
	}

	return (new);
}

/**
 * delete_begin - delete node at beginning of stack/queue
 *
 * @head: head of list
 * @n: int in new node
 *
 * Return: int value of node
 * OR EXIT STATUS
 */

int delete_begin(stack_t **head)
{
	stack_t *curr = *head;
	int value;

	if (!head || !(*head))
		return (-1);

	value = head->n;

	*head = *head->next;
	*head->prev = NULL;

	free(current);
	return (value);
}

/**
 * delete_end - delete node at end of stack/queue
 *
 * @head: head of list
 * @n: int in new node
 *
 * Return: int value of node
 * OR EXIT STATUS
 */

int delete_end(stack_t **head)
{
        stack_t *curr = *head;
        int value;

        if (!head || !(*head))
                return (-1);
	while (curr->next != NULL)
		curr = curr->next;

        value = curr->n;

	curr->prev->next = NULL;

        free(current);
        return (value);
}

/**
 * free_stack - frees a stack/queue
 *
 * @head: head of stack
 *
 * Return: VOID
 */

void free_stack(stack_t *head)
{
	stack_t *new;

	while (head)
	{
		new = head->next;
		free(head);
		head = new;
	}
}
