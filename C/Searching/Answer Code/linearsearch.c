/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Practice-Code
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */



#include <stdio.h>

// Returns 1 if val is in arr; otherwise, return 0
int linearSearch(int *arr, int len, int val)
{
	int i;
	
	for (i = 0; i < len; i++)
		if (arr[i] == val)
			return 1;
			
	return 0;
}

int main()
{
	int arr[] = {0, 3, 1, 45, 3, 13, 42, 1, 4, 79, 10};
	int len = 11;
	int val = 102;
	
	if (linearSearch(arr, len, val))
		printf("%d is in the array!\n", val);
	else
		printf("%d is not in the array!\n", val);
	
	return 0;
}