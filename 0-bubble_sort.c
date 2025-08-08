#include "sort.h"

/**
* swap - Swaps two integers in memory
* @a: Pointer to first integer
* @b: Pointer to second integer
*/

void swap(int *a, int *b)
{
int temp = 0;
temp = *a;
*a = *b;
*b = temp;
}

/**
 * bubble_sort - sorts an array of int in ascend order
 * @array: array
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if ( array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
