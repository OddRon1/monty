#include "monty.h"
/**
* free_stack - this function frees a doubly linked list
* @head: this points to the head of the stack
* return: this function has no return
*/
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
