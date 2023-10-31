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

void insertionSort(int *arr, int len)
{
	int i, j, index = 1, min = 0;
	
	for (i = index; i < len; i++)
	{
		for (j = index - 1; j >= 0; j--)
		{
			if (arr[j] < arr[j + 1])
				break;
				
			swap(arr + j, arr + j + 1);
		}
		
		index++;
	}
}