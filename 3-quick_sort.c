#include "sort.h"

/*
*swap - two elements into an array on the same position
*@array: array of integer
*@item1: array item1
*@item2: array item2
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/*
 *lomuto_partition - lomuto partition 
 *@array: array element
 *@first: first array element on the dot
 *@last: last array element on the dot
 *@size: size of an array
 *Return: return last element
 */

int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}

/*
 *qs - qs
 *@array: array element
 *@first: A first array element on the dot
 *@last: A last array element on the dot
 *@size: array size
 */

void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;


	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);
	}
}

/*
*
 *quick_sort - sort the the position
 *@array: array element
 *@size: A array size
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
