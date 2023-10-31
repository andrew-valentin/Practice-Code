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

void selectionSort(int *arr, int len)
{
	int i, j, index = 0, min = 0;
	
	for (i = 0; i < len; i++)
	{
		for (j = index; j < len; j++)
			if (arr[j] < arr[min])
				min = j;

		swap(arr + index, arr + min);
		index++;
		min = index;
	}
}