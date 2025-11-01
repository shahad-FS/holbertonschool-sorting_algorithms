#include "sort.h"

/**
 * swap_ints - swap two integers
 * @a: pointer to first int
 * @b: pointer to second int
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
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[(low + high) / 2];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (i <= high && array[i] < pivot);
		do {
			j--;
		} while (j >= low && array[j] > pivot);

		if (i >= j)
			return (j);
		swap_ints(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * hoare_quick_sort - Recursively sorts an array
 * of integers using Hoare partition.
 * @array: The array to sort.
 * @size: The total size of the array.
 * @low: The starting index of the subarray to sort.
 * @high: The ending index of the subarray to sort.
 */
void hoare_quick_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);
		if (pivot >= low)
			hoare_quick_sort(array, low, pivot, size);
		if (pivot + 1 <= high)
			hoare_quick_sort(array, pivot + 1, high, size);
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
	if (!array || size < 2)
		return;

	hoare_quick_sort(array, 0, (int)size - 1, size);
}
