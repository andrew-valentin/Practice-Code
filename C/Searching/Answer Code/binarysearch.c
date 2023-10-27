/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Practice-Code
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */



#include <math.h>
#include <stdio.h>

// Returns 1 if val is in arr; otherwise, return 0
int binarySearch(int *arr, int len, int val)
{		
	int mid, lo = 0, hi = len - 1;
		
	while (lo <= hi)
	{
		mid = ((hi - lo) / 2) + lo;
		
		if (arr[mid] > val)
			hi = mid - 1;
		else if (arr[mid] < val)
			lo = mid + 1;
		else
			return 1;
	}
	
	return 0;
}

int main()
{
	int arr[] = {0, 1, 3, 15, 32, 100, 101, 320, 321};
	int len = 9;
	int val = 1001;
	
	if (binarySearch(arr, len, val))
		printf("%d is in the array!\n", val);
	else
		printf("%d is not in the array!\n", val);
	
	return 0;
}