#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Pointer to the pointer to the head of the list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL; /* Pointer to the previous node */
	listint_t *current = *head; /* Pointer to the current node */

	while (current != NULL)
	{
		listint_t *next = current->next; /* Pointer to the next node */
		current->next = prev; /* Reverse the 'next' pointer */

		prev = current; /* Move 'prev' to the current node */
		current = next; /* Move 'current' to the next node */
	}

	*head = prev; /* Update the head pointer to the new first node */

	return (*head);
}
