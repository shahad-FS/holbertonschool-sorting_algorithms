#include "sort.h"

/**
 * merge_subarrays - Merges two sorted subarrays into one sorted array
 * @array: The original array
 * @temp: Temporary array used for merging
 * @left: Starting index of left subarray
 * @mid: Middle index, separates left and right
 * @right: Ending index of right subarray
 */
void merge_subarray(int *array, int *temp,
		size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];
	while (j < right)
		temp[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_recursive - Recursively splits the array and merges it
 * @array: The array to sort
 * @temp: Temporary array for merging
 * @left: Starting index
 * @right: Ending index (non-inclusive)
 */
void merge_recursive(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	mid = left + (right - left) / 2;
	merge_recursive(array, temp, left, mid);
	merge_recursive(array, temp, mid, right);
	merge_subarray(array, temp, left, mid, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	merge_recursive(array, temp, 0, size);
	free(temp);
}
