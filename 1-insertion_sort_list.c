#include "sort.h"

/**
* swap - swap two nodes
* @list: head of the list
* @a: first node ->left
* @b: second node ->right
*/

void swap(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;

	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	b->next = a;
	a->prev = b;
}

/**
* insertion_sort_list - Sorts a doubly linked list of integers
* in ascending order using the insertion sort algorithm
* @list: Double pointer to the head of the list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *cur;

	if (list == NULL)
	return;

	cur = (*list)->next;
	while (cur)
	{
		temp = cur;
		while (temp->prev && temp->n < temp->prev->n)
		{
			swap(list, temp->prev, temp);
			print_list(*list);
		}
		cur = cur->next;
	}
}
