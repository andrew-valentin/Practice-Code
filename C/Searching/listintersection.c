/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Practice-Code
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */



#include <stdio.h>

// Print all of the values that both arrays have in common
void listIntersection(int *arr1, int *arr2, int len1, int len2)
{
	// your code here
}

int main()
{
	int arr1[] = {0, 1, 3, 10, 41, 321, 3213, 3320};
	int arr2[] = {0, 21, 32, 41, 93, 333, 3031, 3132, 3329, 6942, 8882};
	int len1 = 8;
	int len2 = 11;
	
	listIntersection(arr1, arr2, len1, len2); // 0, 41
	
	int arr3[] = {0, 1, 3, 10, 21, 22, 23, 40};
	int arr4[] = {2, 21, 32};
    int len3 = 8;
	int len4 = 3;
	
	listIntersection(arr3, arr4, len3, len4); // 21

    int arr5[] = {0, 1, 3};
	int arr6[] = {1, 2, 3};
    int len5 = 3;
	int len6 = 3;
	
	listIntersection(arr5, arr6, len5, len6); // 1, 3

    int arr7[] = {0, 2, 4, 6, 8};
	int arr8[] = {1, 3, 5, 7, 9};
    int len7 = 5;
	int len8 = 5;
	
	listIntersection(arr7, arr8, len7, len8); // "Both arrays do not have any values in common!"
	
	return 0;
}