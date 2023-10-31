/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Practice-Code
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */



#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "minheap.h"

int main()
{
	Heap *minheap = createHeap();
	
	insert(minheap, 3);
	insert(minheap, 10);
	insert(minheap, 4);
	printHeap(minheap);
	
	printf("Deleted %d\n", deleteMin(minheap));
	printHeap(minheap);
	
	insert(minheap, 1);
	printHeap(minheap);
	
	printf("Deleted %d\n", deleteMin(minheap));
	printHeap(minheap);
	
	printf("Deleted %d\n", deleteMin(minheap));
	printHeap(minheap);
	
	insert(minheap, 12);
	printHeap(minheap);
	
	insert(minheap, 19);
	printHeap(minheap);
	
	printf("Deleted %d\n", deleteMin(minheap));
	printHeap(minheap);
	
	printf("Deleted %d\n", deleteMin(minheap));
	printHeap(minheap);
	
	printf("Deleted %d\n", deleteMin(minheap));
	printHeap(minheap);
	
	printf("Deleted %d\n", deleteMin(minheap));
	printHeap(minheap);
	
	minheap = freeHeap(minheap);
	
	printf("Deleted %d\n", deleteMin(minheap));
	printHeap(minheap);
	
	return 0;
}