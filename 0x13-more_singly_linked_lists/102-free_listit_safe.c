#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely.
 * @h: Pointer to the pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h;
	listint_t *temp;
	size_t node_count = 0;

	while (current != NULL)
	{
		temp = current->next; /* Store the next node temporarily */
		free(current); /* Free the current node */
		current = temp; /* Move to the next node */
		node_count++; /* Increment the node count */
	}

	*h = NULL; /* Set the head to NULL after freeing all nodes */

	return (node_count); /* Return the size of the list that was freed */
}
