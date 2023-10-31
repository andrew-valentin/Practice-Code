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

int roundDown(float num)
{
	if ((int)(num * 10) % 10 == 0)
		return (int)num;
	return (int)num;
}

int roundUp(float num)
{
	if ((int)(num * 10) % 10 == 0)
		return (int)num;
	return (int)num + 1;
}

int *copy(int *arr, int len)
{
	int i;
	int *arrCopy = (int *)malloc(len * sizeof(int));
	
	for (i = 0; i < len; i++)
		arrCopy[i] = arr[i];
	
	return arrCopy;
}

void mergeArrays(int *arr , int *left, int *right, int leftLen, int rightLen)
{
	int i = 0, j = 0, index = 0;
	int *leftCopy = copy(left, leftLen), *rightCopy = copy(right, rightLen);

	while (i < leftLen || j < rightLen)
	{
		if (i == leftLen)
		{
			arr[index++] = rightCopy[j++];
		}
		else if (j == rightLen)
		{
			arr[index++] = leftCopy[i++];
		}
		else
		{
			if (leftCopy[i] < rightCopy[j])
				arr[index++] = leftCopy[i++];
			else
				arr[index++] = rightCopy[j++];
		}
	}
	
	free(leftCopy);
	free(rightCopy);
}

int *mergeSortHelper(int *arr, int len)
{
	int *left, *right;
	int leftLen, rightLen;
	
	if (len == 1)
		return arr;

	leftLen = roundUp(len / 2.0);
	rightLen = roundDown(len / 2.0);
	
	left = mergeSortHelper(arr, leftLen);
	right = mergeSortHelper(arr + leftLen, rightLen);

	mergeArrays(arr, left, right, leftLen, rightLen);
	
	return arr;
}

void mergeSort(int *arr, int len)
{
	if (arr == NULL || len == 0)
		return;
	
	mergeSortHelper(arr, len);
}