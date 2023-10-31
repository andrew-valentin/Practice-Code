/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Practice-Code
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */



typedef struct Heap
{
	int *arr;
	int size;
	int capacity;
} Heap;

void printHeap(Heap *heap)
{
	int i;
	
	if (heap == NULL || heap->arr == NULL || heap->size == 0)
	{
		printf("Heap is empty.\n");
		return;
	}
	
	for (i = 0; i < heap->size; i++)
		printf("%d%c", heap->arr[i], (i == heap->size - 1) ? '\n' : ' ');
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Dynamically creates a heap and returns the address
Heap *createHeap()
{
	// your code here
}

// Frees a heap
void *freeHeap(Heap *heap)
{
	// your code here
}

// Increases the capacity of a heap
void increaseCapacity(Heap *heap)
{
	// your code here
}

// Moves a newly added element up the heap
void perculateUp(Heap *maxheap)
{
	// your code here
}

// Moves the root down the heap
void perculateDown(Heap *maxheap)
{
	// your code here
}

// Inserts an element into the heap
void insert(Heap *maxheap, int val)
{
	// your code here
}

// Removes the largest element in the heap and returns it
int deleteMax(Heap *maxheap)
{
	// your code here
}

// Returns the largest element in the heap
int findMax(Heap *maxheap)
{
	// your code here
}