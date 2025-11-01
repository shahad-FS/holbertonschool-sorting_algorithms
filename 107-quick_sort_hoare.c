#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * hoare_partition - Partitions an array using the Hoare scheme.
 * @array: The array to partition.
 * @size: The total size of the array.
 * @low: The starting index of the partition to sort.
 * @high: The ending index of the partition to sort.
 *
 * Return: The partition index.
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do
		{
			i++;
		} while (array[i] < pivot);
		do
		{
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);
		swap_ints(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * hoare_quick_sort - Recursively sorts an array of integers using Hoare partition.
 * @array: The array to sort.
 * @size: The total size of the array.
 * @low: The starting index of the subarray to sort.
 * @high: The ending index of the subarray to sort.
 */
void hoare_quick_sort(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, size, low, high);
		hoare_quick_sort(array, size, low, pivot);
		hoare_quick_sort(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 *                    the Quick sort algorithm (Hoare partition scheme).
 * @array: Pointer to the array to sort.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_quick_sort(array, size, 0, size - 1);
}
