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
	Heap *heap = (Heap *)malloc(sizeof(Heap));
	
	heap->arr = (int *)malloc(sizeof(int));
	heap->size = 0;
	heap->capacity = 1;
	
	return heap;
}

// Frees a heap
void *freeHeap(Heap *heap)
{
	if (heap == NULL)
		return NULL;
	
	free(heap->arr);
	free(heap);
	
	return NULL;
}

// Increases the capacity of a heap
void increaseCapacity(Heap *heap)
{
	heap->capacity++;
	heap->arr = (int *)realloc(heap->arr, heap->capacity);
}

// Moves a newly added element up the heap
void perculateUp(Heap *minheap)
{
	int parent, curr_index = minheap->size - 1;
	
	while (curr_index > 0)
	{
		parent = floor((curr_index - 1) / 2);
		
		if (minheap->arr[parent] > minheap->arr[curr_index])
		{
			swap(minheap->arr + curr_index, minheap->arr + parent);
			curr_index = parent;
		}
		else
		{
			return;
		}
	}
}

// Moves the root down the heap
void perculateDown(Heap *minheap)
{
	int min_val, left, right, curr_index = 0;
	
	while (curr_index < minheap->size)
	{
		left = curr_index * 2 + 1;
		right = curr_index * 2 + 2;
		
		if (left >= minheap->size && right >= minheap->size)
		{
			return;
		}
		else if (right >= minheap->size)
		{
			if (minheap->arr[curr_index] > minheap->arr[left])
			{
				swap(minheap->arr + curr_index, minheap->arr + left);
				curr_index = left;
				continue;
			}
			else
			{
				return;
			}
		}		
		else if (left >= minheap->size)
		{
			if (minheap->arr[curr_index] > minheap->arr[right])
			{
				swap(minheap->arr + curr_index, minheap->arr + right);
				curr_index = right;
				continue;
			}
			else
			{
				return;
			}
		}	
		
		if (minheap->arr[curr_index] > minheap->arr[left] && minheap->arr[curr_index] > minheap->arr[right])
		{
			if (minheap->arr[right] > minheap->arr[left])
			{
				swap(minheap->arr + curr_index, minheap->arr + left);
				curr_index = left;
				continue;
			}
			else
			{
				swap(minheap->arr + curr_index, minheap->arr + right);
				curr_index = right;
				continue;
			}
		}
		else if (minheap->arr[curr_index] > minheap->arr[left])
		{
			swap(minheap->arr + curr_index, minheap->arr + left);
			curr_index = left;
			continue;
		}
		else if (minheap->arr[curr_index] > minheap->arr[right])
		{
			swap(minheap->arr + curr_index, minheap->arr + right);
			curr_index = right;
			continue;
		}
		else
		{
			return;
		}
	}
}

void insert(Heap *minheap, int val)
{
	if (minheap == NULL || minheap->arr == NULL)
		return;
	
	minheap->arr[minheap->size++] = val;
	perculateUp(minheap);
	
	if (minheap->size == minheap->capacity)
		increaseCapacity(minheap);
}

// Removes the smallest element in the heap and returns it
int deleteMin(Heap *minheap)
{
	int val;

	if (minheap == NULL || minheap->arr == NULL || minheap->size == 0)
		return INT_MAX;
	
	val = minheap->arr[0];
	minheap->arr[0] = minheap->arr[--minheap->size];
	perculateDown(minheap);

	return val;
}

// Returns the smallest element in the heap
int findMin(Heap *minheap)
{
	return (minheap == NULL || minheap->arr == NULL) ? INT_MAX : minheap->arr[0];
}