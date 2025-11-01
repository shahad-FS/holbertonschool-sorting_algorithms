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
 * hoare_lpvt - the hoare partitioning scheme for quick sort
 * @array: array of integers
 * @start: partition start index
 * @endt: partition last index
 * @size: size of the array
 *
 * Return: the
 */
int hoare_lpvt(int *array, int start, int end, size_t size)
{
	int pivot, i, j;

	pivot = array[start];
	i = start - 1;
	j = end + 1;
	while (1)
	{
		while(array[++i] < pivot)
			;
		while (array[--j] > pivot)
			;
		if (i>=j)
			return (j);
		swap_ints(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * hoare_rpvt - the hoare partitioning scheme for quick sort
 * @array: array of integers
 * @start: partition start index
 * @end: partition last index
 * @size: size of the array
 *
 * Return: the
 */
int hoare_rpvt(int *array, int start, int end, size_t size)
{
	int pivot, i, j;
	
	pivot = array[end];
	i = start - 1;
	j = end + 1;
	while (i < j)
	{
		while (array[++i] < pivot)
			;
		while (array[--j] > pivot)
			;
		if (i < j)
		{
			swap_ints(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	return (i);
}

/**
 * quicksort_fn_hoare - quick sort algorithm
 *
 * @array: array of numbers
 * @size: siz of th array
 * @low: the first index
 * @high: the last index
 *
 * Return: void
 */
void quicksort_fn_hoare(int *array, int low, int high, size_t size)
{
	int partitionIndex;

	if (high > low)
	{
		partitionIndex = hoare_rpvt(array, low, high, size);
		quicksort_fn_hoare(array, low, partitionIndex - 1, size);
		quicksort_fn_hoare(array, partitionIndex, high, size);
	}
}

/**
 * quick_sort_hoare - base of quicksort_fn_hoare
 *
 * @array: array of numbers
 * @size: siz of th array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_fn_hoare(array, 0, size - 1, size);
}
