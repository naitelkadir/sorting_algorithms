#include "sort.h"

/**
 * swap_nodes - ...
 * @head: ...
 * @n1: ...
 * @n2: ...
 */
void swap_nodes(listint_t **head, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
	{
		n2->next->prev = *n1;
	}
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
	{
		(*n1)->prev->next = n2;
	}
	else
	{
		*head = n2;
	}
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - ..
 * @list: ...
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *new, *node;
	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	for (node = (*list)->next; node != NULL; node = tmp)
	{
		tmp = node->next;
		new = node->prev;
		while (new != NULL && node->n < new->n)
		{
			swap_nodes(list, &new, node);
			print_list((const listint_t *)*list);
		}
	}
}
