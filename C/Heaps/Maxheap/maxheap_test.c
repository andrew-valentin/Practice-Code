/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Practice-Code
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */



#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "maxheap.h"

int main()
{
	Heap *maxheap = createHeap();
	
	insert(maxheap, 100);
	insert(maxheap, 10);
	insert(maxheap, 30);
	printHeap(maxheap);
	
	printf("Deleted %d\n", deleteMax(maxheap));
	printHeap(maxheap);
	
	insert(maxheap, 999);
	printHeap(maxheap);
	
	printf("Deleted %d\n", deleteMax(maxheap));
	printHeap(maxheap);
	
	printf("Deleted %d\n", deleteMax(maxheap));
	printHeap(maxheap);
	
	insert(maxheap, 99);
	printHeap(maxheap);
	
	insert(maxheap, 10);
	printHeap(maxheap);
	
	printf("Deleted %d\n", deleteMax(maxheap));
	printHeap(maxheap);
	
	printf("Deleted %d\n", deleteMax(maxheap));
	printHeap(maxheap);
	
	printf("Deleted %d\n", deleteMax(maxheap));
	printHeap(maxheap);
	
	printf("Deleted %d\n", deleteMax(maxheap));
	printHeap(maxheap);
	
	maxheap = freeHeap(maxheap);
	
	printf("Deleted %d\n", deleteMax(maxheap));
	printHeap(maxheap);
	
	return 0;
}