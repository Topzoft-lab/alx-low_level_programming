#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: The address of the node where the loop starts, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise = head; /* Slow pointer */
	listint_t *hare = head; /* Fast pointer */

	/* Check if there's a loop in the list */
	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next; /* Move tortoise one step */
		hare = hare->next->next; /* Move hare two steps */

		/* If the pointers meet, there's a loop */
		if (tortoise == hare)
		{
			/* Move one pointer back to the head and continue moving both at the same pace */
			tortoise = head;
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}
			return tortoise; /* Return the start of the loop */
		}
	}

	return NULL; /* No loop found */
}
