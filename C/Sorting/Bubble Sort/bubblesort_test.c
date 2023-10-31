/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Practice-Code
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */



#include <stdio.h>

#include "bubblesort.h"

int main()
{
	int arr1[] = {20, 3, 45, 2, 5, 21, 43, 1}; 
	int len1 = 8;
	
	int arr2[] = {1}; 
	int len2 = 1;
	
	int arr3[] = {3, 12, 42, 121, 32, 4, 12, 53, 0};
	int len3 = 9;
	
	int arr4[] = {3, 20, -29, -1, 0};
	int len4 = 5;

	printf("Array: ");
	printArr(arr1, len1);
	// [20, 3, 45, 2, 5, 21, 43, 1]
	
	bubbleSort(arr1, len1);
	
	printf("Array after bubble sort: ");
	printArr(arr1, len1);
	// [1, 2, 3, 5, 20, 21, 43, 45]
	
	printf("\nArray: ");
	printArr(arr2, len2);
	// [1]
	
	bubbleSort(arr2, len2);
	
	printf("Array after bubble sort: ");
	printArr(arr2, len2);
	// [1]
	
	printf("\nArray: ");
	printArr(arr3, len3);
	// [3, 12, 42, 121, 32, 4, 12, 53, 0]
	
	bubbleSort(arr3, len3);
	
	printf("Array after bubble sort: ");
	printArr(arr3, len3);
	// [0, 3, 4, 12, 12, 32, 42, 53, 121]
	
	printf("\nArray: ");
	printArr(arr4, len4);
	// [3, 20, -29, -1, 0]
	
	bubbleSort(arr4, len4);
	
	printf("Array after bubble sort: ");
	printArr(arr4, len4);
	// [-29, -1, 0, 3, 20]
	
	return 0;
}