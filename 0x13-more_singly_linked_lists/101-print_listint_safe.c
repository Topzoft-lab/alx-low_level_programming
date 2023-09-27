#include "lists.h"


/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;
	size_t node_count = 0;
	const listint_t *visited[1024]; /* Array to track visited nodes */
	size_t i;

	while (current != NULL)
	{
		/* Check if the current node has been visited */
		for (i = 0; i < node_count; i++)
		{
			if (current == visited[i])
			{
				printf("-> [%p] %d\n", (void *)current, current->n);
				exit(98); /* Exit with status 98 if a loop is detected */
			}
		}

		visited[node_count] = current; /* Add the current node to the visited array */
		node_count++;

		printf("[%p] %d\n", (void *)current, current->n);
		current = current->next;
	}

	return (node_count);
}
