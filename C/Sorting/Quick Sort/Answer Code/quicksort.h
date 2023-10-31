/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Practice-Code
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */



void printArr(int *arr, int len)
{
	int i;
	
	for (i = 0; i < len; i++)
		printf("%d%c", arr[i], (i == len - 1) ? '\n' : ' ');
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int *arr, int len)
{
	int pivot, left, right;

	if (len <= 1)
		return;
	
	pivot = 0;
	left = 1;
	right = len - 1;
	
	while (left <= right)
	{
		if (arr[left] <= arr[pivot])
		{
			left++;
		}
		else if (arr[right] > arr[pivot])
		{
			right--;
		}
		else
		{
			swap(arr + left, arr + right);
			left++;
			right--;
		}
	}
	
	swap(arr, arr + right);
	
	quickSort(arr, right);
	quickSort(arr + right + 1, len - right - 1);
}