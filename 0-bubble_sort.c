#include "sort.h"
/**
 * bubble_sort - Sort an array using Bubble Sort
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		if (array[j] > array[j + 1])
		{
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			print_array(array, size);
		}
	}
}
