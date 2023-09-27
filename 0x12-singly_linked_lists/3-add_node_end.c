#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Pointer to the pointer to the head of the list.
 * @str: String to be duplicated and added to the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *current;

	if (str == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t)); /* Allocate memory for the new node */

	if (new_node == NULL)
		return (NULL); /* Return NULL if malloc fails */

	new_node->str = strdup(str); /* Duplicate the input string */

	if (new_node->str == NULL)
	{
		free(new_node); /* Free the new_node if strdup fails */
		return (NULL);
	}

	new_node->len = strlen(str); /* Set the length of the string */
	new_node->next = NULL; /* Initialize the next pointer for the new node */

	if (*head == NULL)
	{
		*head = new_node; /* If the list is empty, make the new node the head */
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next; /* Traverse to the last node */
		}
		current->next = new_node; /* Add the new node to the end of the list */
	}

	return (new_node);
}
