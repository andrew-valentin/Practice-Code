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
	heap->capacity = 0;
	
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
void perculateUp(Heap *maxheap)
{
	int parent, curr_index = maxheap->size - 1;
	
	while (curr_index > 0)
	{
		parent = floor((curr_index - 1) / 2);
		
		if (maxheap->arr[parent] < maxheap->arr[curr_index])
		{
			swap(maxheap->arr + curr_index, maxheap->arr + parent);
			curr_index = parent;
		}
		else
		{
			return;
		}
	}
}

// Moves the root down the heap
void perculateDown(Heap *maxheap)
{
	int min_val, left, right, curr_index = 0;
	
	while (curr_index < maxheap->size)
	{
		left = curr_index * 2 + 1;
		right = curr_index * 2 + 2;
		
		if (left >= maxheap->size && right >= maxheap->size)
		{
			return;
		}
		else if (right >= maxheap->size)
		{
			if (maxheap->arr[curr_index] < maxheap->arr[left])
			{
				swap(maxheap->arr + curr_index, maxheap->arr + left);
				curr_index = left;
				continue;
			}
			else
			{
				return;
			}
		}		
		else if (left >= maxheap->size)
		{
			if (maxheap->arr[curr_index] < maxheap->arr[right])
			{
				swap(maxheap->arr + curr_index, maxheap->arr + right);
				curr_index = right;
				continue;
			}
			else
			{
				return;
			}
		}	
		
		if (maxheap->arr[curr_index] < maxheap->arr[left] && maxheap->arr[curr_index] < maxheap->arr[right])
		{
			if (maxheap->arr[right] < maxheap->arr[left])
			{
				swap(maxheap->arr + curr_index, maxheap->arr + left);
				curr_index = left;
				continue;
			}
			else
			{
				swap(maxheap->arr + curr_index, maxheap->arr + right);
				curr_index = right;
				continue;
			}
		}
		else if (maxheap->arr[curr_index] < maxheap->arr[left])
		{
			swap(maxheap->arr + curr_index, maxheap->arr + left);
			curr_index = left;
			continue;
		}
		else if (maxheap->arr[curr_index] < maxheap->arr[right])
		{
			swap(maxheap->arr + curr_index, maxheap->arr + right);
			curr_index = right;
			continue;
		}
		else
		{
			return;
		}
	}
}

// Inserts an element into the heap
void insert(Heap *maxheap, int val)
{
	if (maxheap == NULL || maxheap->arr == NULL)
		return;
	
	maxheap->arr[maxheap->size++] = val;
	perculateUp(maxheap);
	
	if (maxheap->size == maxheap->capacity)
		increaseCapacity(maxheap);
}

// Removes the largest element in the heap and returns it
int deleteMax(Heap *maxheap)
{
	int val;

	if (maxheap == NULL || maxheap->arr == NULL || maxheap->size == 0)
		return INT_MIN;
	
	val = maxheap->arr[0];
	maxheap->arr[0] = maxheap->arr[--maxheap->size];
	perculateDown(maxheap);

	return val;
}

// Returns the largest element in the heap
int findMax(Heap *maxheap)
{
	return (maxheap == NULL || maxheap->arr == NULL) ? INT_MIN : maxheap->arr[0];
}