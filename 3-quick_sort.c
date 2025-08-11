#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: Pointer to first integer
 * @b: Pointer to second integer
 */
void swap(int *a, int *b)
{

int temp = *a;
*a = *b;
*b = temp;
}

/**
* lomuto_partition - Partitions the array using Lomuto scheme
* @array: The array to be partitioned
* @size: Size of the array
* @low: Starting index of the partition
* @high: Ending index of the partition
* Return: The final index of the pivot
*/
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = (low - 1);
	int j = 0;
	for (j = low; j < high; j++)
		{
		if (array[j] <= pivot)
			{
			i++;
			if (i != j)
				{
				swap(&array[i], &array[j]);
			   print_array(array, size);
				}
			}
		}
		if (array[i + 1] != array[high])
		{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
		}
	return (i + 1);
}

/**
* quick_sort_recursive - Recursively sorts array using quicksort
* @array: The array to be sorted
* @size: Size of the array
* @low: Starting index of the current partition
* @high: Ending index of the current partition
*/
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, size, low, high);
		quick_sort_recursive(array, size, low, pivot_index - 1);
		quick_sort_recursive(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - that sorts array of int in ascending order
 * @array: array
 * @size: size array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}
