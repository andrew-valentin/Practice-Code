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

Heap *createHeap(int len)
{
	Heap *heap = (Heap *)malloc(sizeof(Heap));
	
	heap->arr = (int *)malloc(len * sizeof(int));
	heap->size = 0;
	heap->capacity = len;
	
	return heap;
}

void *freeHeap(Heap *heap)
{
	if (heap == NULL)
		return NULL;
	
	free(heap->arr);
	free(heap);
	
	return NULL;
}

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

int roundDown(float num)
{
	if ((int)(num * 10) % 10 == 0)
		return (int)num;
	return (int)num;
}

int roundUp(float num)
{
	if ((int)(num * 10) % 10 == 0)
		return (int)num;
	return (int)num + 1;
}

void perculateUp(Heap *minheap)
{
	int parent, curr_index = minheap->size - 1;
	
	while (curr_index > 0)
	{
		parent = roundDown((curr_index - 1) / 2);
		
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
}

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

Heap *heapify(int *arr, int len)
{
	int i;
	Heap *heap = createHeap(len);
	
	for (i = 0; i < len; i++)
		insert(heap, arr[i]);
	
	return heap;
}

void heapSort(int *arr, int len)
{
	int i;
	Heap *heap = heapify(arr, len);

	for (i = 0; i < len; i++)
		arr[i] = deleteMin(heap);
	
	heap = freeHeap(heap);
}