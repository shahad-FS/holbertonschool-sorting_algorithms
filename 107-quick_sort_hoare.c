#include "sort.h"


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
	int pivot = array[high];
	int i = low - 1, j = high + 1, temp;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
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
		hoare_quick_sort(array, low, pivot, size);
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

	hoare_quick_sort(array, 0, size - 1, size);
}
