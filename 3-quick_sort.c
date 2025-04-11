#include "sort.h"

/**
 * swap_ints - Échange deux entiers dans un tableau
 * @a: Adresse du premier entier
 * @b: Adresse du second entier
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partitionne un tableau en utilisant le schéma de Lomuto.
 * @array: Tableau d'entiers.
 * @low: Indice de début de la partition.
 * @high: Indice de fin de la partition (l'élément pivot est array[high]).
 * @size: Taille totale du tableau (pour l'affichage).
 *
 * Return: L'indice du pivot une fois placé à sa position correcte.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				if (array[i] != array[j])
				{
					swap_ints(&array[i], &array[j]);
					print_array(array, size);
				}
				else
				{
					swap_ints(&array[i], &array[j]);
				}
			}
		}
	}

	if ((i + 1) != high)
	{
		if (array[i + 1] != array[high])
		{
			swap_ints(&array[i + 1], &array[high]);
			print_array(array, size);
		}
		else
		{
			swap_ints(&array[i + 1], &array[high]);
		}
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - Trie récursivement un sous-tableau
 *  à l'aide de Quick sort.
 * @array: Tableau d'entiers.
 * @low: Indice de début du sous-tableau.
 * @high: Indice de fin du sous-tableau.
 * @size: Taille totale du tableau (pour l'affichage).
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Trie un tableau d'entiers en ordre croissant
 *en utilisant l'algorithme Quick sort et le schéma de Lomuto.
 * @array: Tableau à trier.
 * @size: Nombre d'éléments dans le tableau.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

