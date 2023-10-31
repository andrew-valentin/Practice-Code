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

int findMin(int *arr, int len)
{
	int i, min = INT_MAX;
	
	for (i = 0; i < len; i++)
		if (arr[i] < min)
			min = arr[i];
	
	return min;
}

int findMax(int *arr, int len)
{
	int i, max = INT_MIN;
	
	for (i = 0; i < len; i++)
		if (arr[i] > max)
			max = arr[i];
	
	return max;
}

int findRange(int min, int max)
{
	if (max < 0)
		return (-1 * max) + min + 1;
	else if (min < 0)
		return max + (-1 * min) + 1;
	else
		return max - min + 1;
}

void bucketSortArr(int *arr, int len)
{
	int i, j = 0;
	int min = findMin(arr, len), max = findMax(arr, len), range = findRange(min, max);
	int *buckets = (int *)calloc(range, sizeof(int));

	for (i = 0; i < len; i++)
		buckets[arr[i] - min]++;

	for (i = 0; i < range; i++)
	{
		while (buckets[i] != 0)
		{
			arr[j++] = i + min;	
			buckets[i]--;
		}
	}

	free(buckets);
}