#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at index of a listint_t linked list.
 * @head: Pointer to the pointer to the head of the list.
 * @index: Index of the node to delete.
 *
 * Return: 1 if successful, -1 if failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int i;

	if (*head == NULL) /* Check if the list is empty */
		return (-1);

	current = *head;

	if (index == 0) /* Special case: delete the first node */
	{
		*head = current->next;
		free(current);
		return (1);
	}

	/* Traverse the list to the node just before the target node */
	for (i = 0; current != NULL && i < index - 1; i++)
		current = current->next;

	if (current == NULL || current->next == NULL) /* Check if index is out of range */
		return (-1);

	/* Store the next node in a temporary pointer */
	temp = current->next;

	/* Update the 'next' pointer of the current node to skip the target node */
	current->next = temp->next;

	/* Free the target node */
	free(temp);

	return (1);
}
