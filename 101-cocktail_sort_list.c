#include "sort.h"

/**
 * swap_nodes_forward - ...
 * @list: ...
 * @tail: ...
 * @n1: ...
 */
void swap_nodes_forward(listint_t **list, listint_t **tail, listint_t **n1)
{
	listint_t *tmp = (*n1)->next;
	
	if ((*n1)->prev != NULL)
	{
		(*n1)->prev->next = tmp;
	}
	else
	{
		*list = tmp;
	}
	tmp->prev = (*n1)->prev;
	(*n1)->next = tmp->next;
	if (tmp->next != NULL)
	{
		tmp->next->prev = (*n1);
	}
	else
	{
		*tail = (*n1);
	}
	(*n1)->prev = tmp;
	tmp->next = (*n1);
	*n1 = tmp;
}
/**
 * swap_nodes_backward - ...
 * @list: ...
 * @tail: ...
 * @n1: ...
 */
void swap_nodes_backward(listint_t **list, listint_t **tail, listint_t **n1)
{
	listint_t *tmp = (*n1)->prev;
	if ((*n1)->next != NULL)
	{
		(*n1)->next->prev = tmp;
	}
	else
	{
		*tail = tmp;
	}
	tmp->next = (*n1)->next;
	(*n1)->prev = tmp->prev;
	if (tmp->prev != NULL)
	{
		tmp->prev->next = (*n1);
	}
	else
	{
		*list = (*n1);
	}
	(*n1)->next = tmp;
	tmp->prev = (*n1);
	*n1 = tmp;
}

/**
 * cocktail_sort_list - ...
 * @list: ...
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *n1;
	bool swapped = false;
	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	for (tail = *list; tail->next != NULL;)
	{
		tail = tail->next;
	}
	while (swapped == false)
	{
		swapped = true;
		for (n1 = *list; n1 != tail; n1 = n1->next)
		{
			if (n1->n > n1->next->n)
			{
				swap_nodes_forward(list, &tail, &n1);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
		for (n1 = n1->prev; n1 != *list; n1 = n1->prev)
		{
			if (n1->n < n1->prev->n)
			{
				swap_nodes_backward(list, &tail, &n1);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
	}
}
