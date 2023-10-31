/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Practice-Code
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */



#include <stdio.h>

typedef struct Heap
{
	int *arr;
	int size;
	int capacity;
} Heap;

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

Heap *createHeap(int len)
{
	// your code goes here
}

void *freeHeap(Heap *heap)
{
	// your code goes here
}

/*
The following auxilliary functions are not required, 
but may help you if you are feeling stuck:

	- roundDown()
	- roundUp()
	- perculateUp()
	- perculateDown()
	- insert()
	- deleteMin()
	- heapify()
*/

int roundDown(float num)
{
	// your code goes here
}

int roundUp(float num)
{
	// your code goes here
}

void perculateUp(Heap *minheap)
{
	// your code goes here
}

void perculateDown(Heap *minheap)
{
	// your code goes here
}

void insert(Heap *minheap, int val)
{
	// your code goes here
}

int deleteMin(Heap *minheap)
{
	// your code goes here
}

Heap *heapify(int *arr, int len)
{
	// your code goes here
}

void heapSort(int *arr, int len)
{
	// your code goes here
}