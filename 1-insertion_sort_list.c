#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list using insertion sort
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		tmp = current;
		current = current->next;

		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			listint_t *left = tmp->prev;
			listint_t *right = tmp;

			left->next = right->next;
			if (right->next)
				right->next->prev = left;

			right->prev = left->prev;
			right->next = left;

			if (left->prev)
				left->prev->next = right;
			else
				*list = right;

			left->prev = right;
			print_list(*list);
		}
	}
}
